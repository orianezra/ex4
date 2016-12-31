
#ifndef EX3_POINT_H
#define EX3_POINT_H
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/detail/archive_serializer_map.hpp>
#include <boost/archive/detail/basic_iarchive.hpp>
#include <boost/archive/detail/basic_oarchive.hpp>
#include <boost/archive/detail/basic_iserializer.hpp>
#include <boost/archive/detail/basic_serializer.hpp>
#include <boost/archive/detail/polymorphic_iarchive_route.hpp>
#include <boost/archive/detail/polymorphic_oarchive_route.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/throw_exception.hpp>
using namespace std;
using namespace boost;
using namespace boost::archive;
using namespace serialization;

/*
 * This class's purpose is to manage a point object.
 * It contains methods that would enable access to the point's members.
 */

class Point{

    //protected member section.
protected:
    int x_axis;
    int y_axis;
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & x_axis;
        ar & y_axis;
    }
    //public member section.
public:
    Point();
    Point(int x, int y);
    virtual ~Point();
    void setX_axis(int x);
    void setY_axis(int y);
    int getX_axis();
    int getY_axis();
    bool operator ==(const Point &point) const;
    bool operator !=(const Point &other) const;
    virtual bool operator <=(const Point &other) const;
    virtual bool operator >=(const Point &other) const;
    std::string serial_str;


    void save() {
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa << *this;

        s.flush();
    }

    Point load(){

        boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        Point p;
        ia >> p;

        return p;
    }
};

#endif //EX3_POINT_