#include<ros/ros.h>
#include<urdf2collisionobject/urdf2collisionobject.hpp>

int main(int argc, char **argv) {
  // ---------------------------------------
  // 1. Ros node initialization
  // ---------------------------------------
  std::string planning_frame;
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle nh;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  urdf2collisionobject::Urdf2CollisionObject u2c;

  u2c.load();

  ros::shutdown();
  return 0;
}
