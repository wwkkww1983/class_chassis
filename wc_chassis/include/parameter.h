#ifndef __PARAMETER__
#define __PARAMETER__
#include <ros/ros.h>
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
#include <autoscrubber_services/CheckProtectorStatus.h>
#include <autoscrubber_services/CheckChargeStatus.h>
#include <autoscrubber_services/SetChargeCmd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <thread>
#include <sched.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
extern  double ultral_effective_range ;
extern  double g_odom_x   ;
extern  double g_odom_y   ;
extern  double g_odom_tha ;
extern  double g_odom_v ;
extern  double g_odom_w ;

enum Device_ID{
  Emergency_stop = 0,
  Mode,
  Battery,
  Mileage,
  Device_MAX
};
// Hardware ID
enum Hardware_ID {
  Main_board = 0,
  Pannel_board,
  Steering_board,
  Power_board,
  Ultrasonic_board,
  Motor_driver,
  Decoder,
  Motor,
  Ultrasonic,
  Hardware_MAX
};
extern unsigned int g_dio_count ;
extern unsigned int g_ret_count ;
extern unsigned int g_pc_control;
extern double last_cmd_vel_time ;
extern double max_cmd_interval ;
extern int current_v_index;
extern int current_w_index;
extern float m_speed_v;
extern float m_speed_w ;
extern float g_speed_v[3];
extern float g_speed_w[3];
extern float g_spe;
extern float g_angle;
extern unsigned int loop_count;
extern  int rotate_angle;
extern bool start_rotate_flag;
extern bool stop_rotate_flag;
extern bool is_rotate_finished;
extern unsigned int g_di_data_;
extern unsigned int g_do_data_;
extern unsigned int cur_emergency_status;
extern double battery_full_level;
extern double battery_empty_level;
extern unsigned int remote_ret_;
extern unsigned int remote_ret_cnt_;
extern unsigned char remote_cmd_;
extern unsigned short remote_index_;
extern std::string ultrasonic_str[15];
extern unsigned char special_ultrasonic_id[15];

extern std::vector<int> g_ultrasonic;
extern pthread_mutex_t speed_mutex;
extern int battery_count;
extern int display_battery_capacity ;
extern int sum_battery_capacity;


extern unsigned int connection_status; // mcu ethernet connection status: 0>bad 1>good
extern int ultrasonic_num;
extern float ultrasonic_min_range;  //超声检测的最小距离  默认值0.04
extern float ultrasonic_max_range;   //超声检测的最大距离  默认值1.0
extern float special_ultrasonic_offset_dismeter;
extern std::string *ultrasonic;
extern std::string *special_ultrasonic;
extern double max_speed_v;
extern double max_speed_w;
extern double speed_v_acc;
extern double speed_v_dec;
extern double speed_v_dec_zero;
extern double speed_w_acc;
extern double speed_w_dec;
extern double full_speed;
extern int    delta_counts_th;
extern int remote_speed_level_;
extern int battery_level_;
extern int remote_id ;
extern std::string hardware_id;
extern std::string router_ip;
extern std::string laser_ip;
extern std::string laser_connection_status;
extern std::string router_connection_status;
extern std::thread *checkConnectionThread;

extern unsigned char protector_service_call;
extern unsigned int protector_value;
extern double protector_start_time;
extern unsigned char protector_down;
extern int protector_num;
extern unsigned int protector_bits;
extern unsigned int ultrasonic_bits;
extern double inplace_rotating_theta;
extern bool ultrasonic_board_connection;

#endif
