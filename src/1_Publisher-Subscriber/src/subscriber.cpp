#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Subcriber Receive: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "subscriber");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  
  ros::Rate loop_rate(60);
  
  while(ros::ok()){
  	chatterCallback;
  	ros::spinOnce();
  	loop_rate.sleep();
  }
  

  return 0;
}
