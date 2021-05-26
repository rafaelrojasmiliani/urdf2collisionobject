cmake_minimum_required(VERSION 3.0.2)
project(urdf2collisionobject)

find_package(
  catkin REQUIRED
  COMPONENTS moveit_core
             moveit_ros_planning_interface
             moveit_visual_tools
             roscpp
             rospy
             urdf
             robot_state_publisher
             kdl_parser)

find_package(Eigen3 REQUIRED)

catkin_package(
  LIBRARIES
  ${PROJECT_NAME}
  CATKIN_DEPENDS
  geometry_msgs
  message_runtime
  moveit_msgs
  moveit_visual_tools
  rosparam_shortcuts
  std_msgs
  trajectory_msgs
  urdf
  robot_state_publisher
  kdl_parser
  INCLUDE_DIRS
  include
  DEPENDS
  EIGEN3)

include_directories(${catkin_INCLUDE_DIRS} ${Eigen3_INCLUDE_DIRS})

set(LIB_SOURCES src/lib/urdf2collisionobject.cpp)

target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES}
                      ${Eigen3_LIBRARIES})
