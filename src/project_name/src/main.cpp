#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>

#include <change.hpp>

int main(int argc, char** argv)
{
    ros::init (argc, argv, "talker");
    ros::NodeHandle n("~");

    std::string str;
    n.getParam("test_1", str);

    ros::Publisher pub = n.advertise<std_msgs::String>("/happy", 1);

    ros::Rate loop_rate(10);
    while (n.ok())
    {
        std_msgs::String msg;
        msg.data = str;

        ROS_INFO("%s", msg.data.c_str());

        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
