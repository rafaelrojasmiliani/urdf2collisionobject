
#include<urdf2collisionobject/urdf2collisionobject.hpp>

#include <robot_state_publisher/robot_state_publisher.h>

#include <xmlrpcpp/XmlRpcValue.h>
#include <urdf/model.h>
#include <kdl_parser/kdl_parser.hpp>
namespace urdf2collisionobject
{

Urdf2CollisionObject::Urdf2CollisionObject(const ros::NodeHandle& _nh): nh_(_nh){
 Urdf2CollisionObject();
}
    
Urdf2CollisionObject::Urdf2CollisionObject():nh_priv_("~"){
}

void Urdf2CollisionObject::load(){
    XmlRpc::XmlRpcValue my_list;
    nh_priv_.hasParam("my_param"); // existence
    nh_.getParam("my_list", my_list);//
    my_list.getType() == XmlRpc::XmlRpcValue::TypeArray; // test correctness

    urdf::Model model;
    KDL::Tree my_tree;
      if (!model.initFile("")){
              ROS_ERROR("Failed to parse urdf file");
                  return -1;
                    }

      kdl_parser::treeFromUrdfModel(my_model, my_tree);

      rsp= RobotStatePublisher(my_tree);
      rsp.publishFixedTransforms();

}
} /* urdf2collisionobject */ 
