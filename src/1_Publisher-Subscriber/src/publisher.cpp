// TODO: implementasi publisher.cpp

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

class MsgPublisher {
	private :
		ros::NodeHandle n;
		ros:: Publisher chatter_pub;
	
	public:
		MsgPublisher(){
			chatter_pub = n.advertise <std_msgs::String>("chatter",1000);
		}
		
		void process(String word){
			std_msgs::String msg;
			msg.data = data;
			chatter_pub.publish(msg);
		}
		
};



int main(int argc, char **argv){
	
ros::init(argc, argv, "publisher");

    MsgPublisher np;

    ROS_INFO("publisher running...");

    ros::Rate loop_rate(60);

    while (ros::ok()) {

        np.process("Hello, World!");

        loop_rate.sleep();
    }

    return 0;
}
