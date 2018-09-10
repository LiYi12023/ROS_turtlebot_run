//練習—讀取bumper 搭配 turtlebot_gazebo turtlebot_world.launch 用 20180816
#include <ros/console.h>
#include <ros/ros.h>
#include <kobuki_msgs/BumperEvent.h>

void bumperCallback(const kobuki_msgs::BumperEvent Bumperinf)
{
	ROS_INFO("bumper hit = [%d]", Bumperinf.bumper);
}

int main(int argc,char **argv)
{
	ros::init(argc,argv, "try_getinf");
	ros::NodeHandle n;
	ros::Subscriber bumperSubscriber = n.subscribe("/mobile_base/events/bumper", 1, bumperCallback);
	ros::spin();
	return 0;
}

