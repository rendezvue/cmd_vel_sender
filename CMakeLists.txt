cmake_minimum_required(VERSION 3.0.2)
project(cmd_vel_sender)
set(CMAKE_PREFIX_PATH "/opt/ros/melodic")
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
	controller_interface
	urdf
	tf
	nav_msgs
	roslaunch
)

generate_messages(
   DEPENDENCIES
   std_msgs   
)


catkin_package(
    LIBRARIES
	INCLUDE_DIRS
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

set(cmd_vel_sender_sources 
  src/cmd_vel_sender.cpp
)

add_executable(cmd_vel_sender ${cmd_vel_sender_sources})
install(TARGETS cmd_vel_sender DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})