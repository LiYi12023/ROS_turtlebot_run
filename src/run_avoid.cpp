//練習—碰碰車 搭配 turtlebot_gazebo turtlebot_world.launch 用 20180816
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>

bool hit = false;
int ti = 0;
void bumperCallback(const kobuki_msgs::BumperEvent Bumperinf)
{
	ROS_INFO("bumper hit = [%d]", Bumperinf.bumper);
	hit = true;
}
int main(int argc, char **argv)
{
	ros::init(argc, argv, "run_avoid");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1000);
        hit = false;
	ros::Subscriber bumperSubscriber = n.subscribe("/mobile_base/events/bumper", 1, bumperCallback);
	ros::Rate loop_rate(10);
	ros::Rate wait_ti(1000000);
	  while (ros::ok())
	  {
	    ti =0;
	    geometry_msgs::Twist twist;
	    if (hit)
	    {
		twist.linear.x = -1; twist.linear.y = 0; twist.linear.z = 0;
		twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = 5;
		//wait_ti.sleep();
		ros::Duration(1).sleep(); //時間延遲用 20180816
		hit = false;
            } 
	    else
	    {
		twist.linear.x = 0.2; twist.linear.y = 0; twist.linear.z = 0;
		twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = 0;
	    }
	    chatter_pub.publish(twist);
	    ros::spinOnce();
	    loop_rate.sleep();
	  }
  	return 0;
}


