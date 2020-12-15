#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>

#include <change.hpp>

int main(int argc, char** argv)
{
    ros::init (argc, argv, "talker");
    ros::NodeHandle n("~");

    std::string output_topic;
    n.getParam("output_topic", output_topic);

    ros::Publisher pub = n.advertise<std_msgs::String>(output_topic, 1);

    ros::Rate loop_rate(10);
    while (n.ok())
    {
        std_msgs::String msg;
        msg.data = "Hi";

        ROS_INFO("%s", msg.data.c_str());

        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
