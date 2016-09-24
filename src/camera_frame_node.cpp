#include <ros/ros.h>

#include <tf/transform_broadcaster.h>
#include <tf_conversions/tf_eigen.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>


int main(int argc, char** argv){
  ros::init(argc, argv, "camera_frame_node");

  tf::TransformBroadcaster tf_broadcaster;
  geometry_msgs::TransformStamped camera_tf;

  camera_tf.header.frame_id = "base_link";
  camera_tf.child_frame_id = "camera";


  // Set the translational part of the static transform
  double cam_x, cam_y, cam_z;

  ros::param::get("/cam_x", cam_x);
  ros::param::get("/cam_y", cam_y);
  ros::param::get("/cam_z", cam_z);

  camera_tf.transform.translation.x = cam_x;
  camera_tf.transform.translation.y = cam_y;
  camera_tf.transform.translation.z = cam_z;


  // Set the Rotational part the the static transform
  double cam_roll, cam_pitch, cam_yaw;

  // set the camera_tf rotation 
  // you will need to convert from RPY to quaternion representation here
  // TODO

  ros::Rate rate(20); // hz
  while(ros::ok() )
  {
  	camera_tf.header.stamp = ros::Time::now();
  	tf_broadcaster.sendTransform(camera_tf);
  	rate.sleep();
  	ros::spinOnce();
  }
  return 0;
}