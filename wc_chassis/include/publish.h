#ifndef __PUBLISH__
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/Float32.h>
#include <tf/message_filter.h>
#include <tf/transform_broadcaster.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <diagnostic_msgs/KeyValue.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Range.h>
#include <autoscrubber_services/StopScrubber.h>
#include <autoscrubber_services/StartRotate.h>
#include <autoscrubber_services/StopRotate.h>
#include <autoscrubber_services/CheckRotate.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sched.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define __PUBLISH__

 void PublishYaw(ros::Publisher &yaw_pub, double yaw);
 void PublishDIO(ros::Publisher &dio_pub);
 void PublishOdom(tf::TransformBroadcaster* odom_broadcaster,ros::Publisher &odom_pub );
 void publishDeviceStatus(ros::Publisher &device_pub);
 void PublishRemoteCmd(ros::Publisher &remote_cmd_pub,unsigned char cmd, unsigned short index);
 void publish_ultrasonic(ros::Publisher& publisher, const char* frame_id, int recv_int,unsigned int ultrasonic_offset, double& ultra_range);
 void PublishUltrasonic(ros::Publisher ultrasonic_pub[]);
 void publish_protector_status(ros::Publisher &protector_pub);
 void UpdateDeviceStatus(void);
 void publish_protector_value(ros::Publisher &protector_pub);
#endif
