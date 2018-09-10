//練習—走直線 搭配 turtlebot_gazebo turtlebot_world.launch 用 20180816
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "go_straight");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1000);
	ros::Rate loop_rate(10);
	  while (ros::ok())
	  {
	    geometry_msgs::Twist twist;
            twist.linear.x = 0.2; twist.linear.y = 0; twist.linear.z = 0;
            twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = 0;

	    chatter_pub.publish(twist);
	    ros::spinOnce();
	    loop_rate.sleep();
	  }
  	return 0;
}
