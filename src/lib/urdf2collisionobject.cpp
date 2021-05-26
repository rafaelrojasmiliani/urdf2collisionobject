
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
    XmlRpc::XmlRpcValue xmlval_path_array;
    std::vector<std::string> str_path_array;
    nh_priv_.hasParam("object_files"); // existence
    nh_.getParam("object_files", xmlval_path_array);//
    if(xmlval_path_array.getType() != XmlRpc::XmlRpcValue::TypeArray){
        return;
    }
    for(unsigned i=0; i < xmlval_path_array.size(); i++) {
        str_path_array.push_back(xmlval_path_array[i]);
    }

    /*
    urdf::Model model;
    KDL::Tree my_tree;
      if (!model.initFile("")){
              ROS_ERROR("Failed to parse urdf file");
                  return -1;
                    }

      kdl_parser::treeFromUrdfModel(my_model, my_tree);

      rsp= RobotStatePublisher(my_tree);
      rsp.publishFixedTransforms();*/

}
} /* urdf2collisionobject */ 
