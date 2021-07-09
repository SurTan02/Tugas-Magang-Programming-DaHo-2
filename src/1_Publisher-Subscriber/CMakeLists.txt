cmake_minimum_required(VERSION 2.8.3)
project(pubser)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)



## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build publisher and subscriber
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})
add_dependencies(publisher pubser_generate_messages_cpp)

add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})
add_dependencies(subscriber pubser_generate_messages_cpp)
