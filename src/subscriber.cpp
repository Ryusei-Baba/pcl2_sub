#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <sensor_msgs/PointCloud2.msg>
#include "minimal_subscriber.hpp"

void MinimalSubscriber::_topic_callback(const sensor_msgs::PointCloud2.msg::SharedPtr msg){
  RCLCPP_INFO(this->get_logger(), "%d", msg->field[]);
}

MinimalSubscriber::MinimalSubscriber(
  const rclcpp::NodeOptions& options
): MinimalSubscriber("",options){}

MinimalSubscriber::MinimalSubscriber(
  const std::string& name_space, 
  const rclcpp::NodeOptions& options
): Node("pcl2sub", name_space, options){
  _subscription = this->create_subscription<sensor_msgs::PointCloud2.msg>(
    "/camera/depth/color/points",
    rclcpp::QoS(10),
    std::bind(&MinimalSubscriber::_topic_callback, this, std::placeholders::_1)
  );
}