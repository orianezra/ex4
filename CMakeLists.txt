cmake_minimum_required(VERSION 3.6)
project(ex3)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES Point.cpp Point.h tests/TripInfoTest.cpp Cab.cpp Cab.h tests/CabTest.cpp CarColors.h CarsManufactor.h CheckPoint.cpp CheckPoint.h Driver.cpp Driver.h tests/DriverTest.cpp Gps.cpp Gps.h tests/GpsTest.cpp Grid.cpp Grid.h tests/GridTest.cpp LuxuryCab.cpp LuxuryCab.h tests/LuxuryCabTest.cpp Map.cpp Map.h MaterialStatus.h Passenger.cpp Passenger.h Person.h TexiCenter.cpp TexiCenter.h tests/TexiCenterTest.cpp tests/PassengerTest.cpp TripInfo.cpp TripInfo.h Vehicles.h tests/CheckPointTest.cpp tests/MapTest.cpp main.cpp)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

#same as yanai
set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})
link_libraries(${Boost_LIBRARIES})

add_executable(ex3 ${SOURCE_FILES})
target_link_libraries(ex3 gtest gtest_main)