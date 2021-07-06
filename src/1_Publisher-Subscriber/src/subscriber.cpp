// TODO: implementasi subscriber.cpp


#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class MsgSubscriber{
	private:
		ros::NodeHandle n;
		ros::Subscriber sub;
		int counter;
		
	public:
		MshSubscriber(){
			sub = n.subscribe<std_msgs::String>("chatter", 1000, &MsgSubscriber::chatterCallback,this)
		}
		
		void chatterCallback(const std_msgs::String::ConstPtr& msg){
			msg->data.c_str();
		}
			
		void print(){
			cout<<"counter: "<<counter <<endl;
		}
};

int main(int argc, char **argv) {

    ros::init(argc, argv, "subscriber");

    MsgSubscriber ns;

    ROS_INFO("subscriber running...");

    ros::Rate rate(60);

    while(ros::ok()) {
        ns.print();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
