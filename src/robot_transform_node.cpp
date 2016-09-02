#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <cmath> // M_PI

/** 
 *  @brief Class to manage robot state publishing
 *
 *  Style: Class names are all UpperCased
 */
class RobotTransformManager
{
public:

	nav_msgs::Odometry robot_odometry_; 
	ros::NodeHandle n_;
  	ros::Subscriber odom_sub_; ///< members are suffixed with '_'
  	tf::TransformBroadcaster tf_broadcaster_;

	RobotTransformManager()
	{
		odom_sub_ = n_.subscribe("/odom_abs", 0, &RobotTransformManager::updateRobot, this);
	}

private:
	/** 
	 *  @brief Callback for odometry message to update the transform of the robot
	 *
	 *  Style: All class methods should be camelCased
	 */
	void updateRobot(const nav_msgs::Odometry& msg)
	{
		// Hint: at a terminal use: 
		//      $ rosmsg show nav_msgs/Odometry 
		//
		// to display information about message
		robot_odometry_ = msg;
	    

	    //Create the transform message and stuff it with data
	    // Hint: at a terminal use: 
		//      $ rosmsg show geometry_msgs/TransformStamped
	    geometry_msgs::TransformStamped base_link_tf;
	    base_link_tf.header.stamp = ros::Time::now();
	    base_link_tf.header.frame_id = "world";
	    base_link_tf.child_frame_id = "base_link";

	    // Now to copy the translation part of the message
	    // TODO

	    // Finally, the rotation need to be copied over too
	    // TODO
	    

	    // Now send the message over the TF server
	    tf_broadcaster_.sendTransform(base_link_tf);
		
	}
};

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_transform_node");
  RobotTransformManager robotManger;
  ros::spin();
  return 0;
}