#include <iostream>

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl/common/common.h>
#include <pcl_ros/point_cloud.h>


class CloudPublisher
{
public:
  ros::NodeHandle nh_;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr in_cloud_;
  ros::Publisher cloud_publisher_;
  ros::Subscriber cloud_subscriber_;

  CloudPublisher():
    in_cloud_(new pcl::PointCloud<pcl::PointXYZRGB>)
  {
    ROS_INFO("Initialized CloudPublisher Class");

    // Initialize the publisher and subscriber 
    cloud_publisher_ = nh_.advertise<sensor_msgs::PointCloud2>("/out_cloud", 1);
    cloud_subscriber_ = nh_.subscribe("/camera/depth_registered/points_throttle", 1, &CloudPublisher::cloudCallback, this);
  }

  void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg)
  {
    
    pcl::fromROSMsg(*msg, *in_cloud_);

    // assign the pointcloud to the camera frame and publish
    // TODO

  }

}; // Class Definition


int main(int argc, char** argv)
{
  ros::init(argc, argv, "pointcloud_node");
  CloudPublisher CP;
  ros::spin();
  return 0;
}