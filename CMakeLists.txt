cmake_minimum_required(VERSION 3.0.2)
project(cmd_vel_sender)
add_compile_options(-std=c++11)
#set(CMAKE_PREFIX_PATH "/opt/ros/melodic")
## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

# set(roscpp_DIR "/opt/ros/melodic/share/roscpp/cmake")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    urdf
    tf
    nav_msgs    
    roslib
    message_generation
)

# generate_messages(
#    DEPENDENCIES
#    std_msgs   
# )

catkin_package(
#     LIBRARIES
# 	INCLUDE_DIRS
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

set(cmd_vel_sender_sources 
  src/cmd_vel_sender.cpp
)

add_executable(${PROJECT_NAME}_node ${cmd_vel_sender_sources})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)


install(TARGETS ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)