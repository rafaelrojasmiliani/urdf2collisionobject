#ifndef URDF2COLLISIONOBJECT_H
#define URDF2COLLISIONOBJECT_H

// ROS
#include <ros/ros.h>
namespace urdf2collisionobject
{
    
class Urdf2CollisionObject
{
    

public:
    Urdf2CollisionObject(const ros::NodeHandle& nh);
    Urdf2CollisionObject();
    virtual ~Urdf2CollisionObject();

    void load();
private:

  ros::NodeHandle nh_;
  ros::NodeHandle nh_priv_;
};


} /* urdf2collisionobject */ 
#endif /* URDF2COLLISIONOBJECT_H */
