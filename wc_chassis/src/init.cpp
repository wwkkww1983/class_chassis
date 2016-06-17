#include "init.h"
#include "advertise_service.h"
#include "subscribe.h"
#include "parameter.h"

tf::TransformBroadcaster *p_odom_broadcaster;
WC_chassis_mcu *g_chassis_mcu;
ros::Rate *p_loop_rate;

ros::NodeHandle *p_n;
ros::NodeHandle *p_nh;
ros::NodeHandle *p_device_nh;

std::string *ultrasonic;
ros::ServiceServer start_rotate_srv;
ros::ServiceServer stop_rotate_srv;
ros::ServiceServer check_rotate_srv;
ros::Subscriber    Navi_sub;
ros::Subscriber    remote_ret_sub;
ros::Subscriber    gyro_update_state_sub;

/***
 * 初始化所有的Service和订阅服务
 */
void InitService(){
    start_rotate_srv = p_device_nh->advertiseService("start_rotate", &StartRotate);
    stop_rotate_srv  = p_device_nh->advertiseService("stop_rotate", &StopRotate);
    check_rotate_srv = p_device_nh->advertiseService("check_rotate", &CheckRotate);
    Navi_sub = p_n->subscribe("cmd_vel", 10, DoNavigationCallback);
    remote_ret_sub = p_device_nh->subscribe("/remote_ret", 10, RemoteRetCallback);
    gyro_update_state_sub = p_n->subscribe("/gyro_update_state", 10, GyroUpdateCallback);
}

/*  ros参数服务器参数的初始化*/
void InitParameter(){

    g_chassis_mcu = new WC_chassis_mcu();
    p_odom_broadcaster = new tf::TransformBroadcaster();
    double f_dia = 0;
    double b_dia = 0;
    double axle  = 0;
    int counts = 0;
    ultrasonic = new std::string();
    int reduction_ratio = 0;
    double speed_ratio = 1.0;
    double timeWidth = 0;
    std::string host_name;
    int port;
    std::string str_auto_topic;
    std::string str_odom = "odom";
    p_nh->param("odom", str_odom, str_odom);
    p_nh->param("WC_Auto_topic", str_auto_topic, std::string("WC_AUTO"));
    p_nh->param("max_cmd_interval", max_cmd_interval, 1.0);
    p_nh->param("F_DIA", f_dia, static_cast<double>(0.125));	// diameter of front wheel
    p_nh->param("B_DIA", b_dia, static_cast<double>(0.125));
    p_nh->param("AXLE", axle, static_cast<double>(0.383));		// length bettween two wheels
    p_nh->param("COUNTS", counts, 12);
    p_nh->param("REDUCTION_RATIO", reduction_ratio, 30);
    p_nh->param("SPEED_RATIO", speed_ratio, static_cast<double>(1.0));
    p_nh->param("TimeWidth", timeWidth, static_cast<double>(0.1));
    p_nh->param("ultral_effective_range", ultral_effective_range, static_cast<double>(0.4));
    p_nh->param("host_name", host_name, std::string("192.168.1.199"));
    p_nh->param("port", port, 5000);
    p_nh->param("acc_lim_th", ACC_LIM_TH, 3.0 / 2.0 * M_PI);
    p_nh->param("battery_full_level", battery_full_level, static_cast<double>(27.5));
    p_nh->param("battery_empty_level", battery_empty_level, static_cast<double>(20.0));
    p_nh->param("ultrasonic",*ultrasonic,std::string(" "));
    p_nh->param("ultrasonic_min_range",ultrasonic_min_range,static_cast<float>(0.04));
    p_nh->param("ultrasonic_max_range",ultrasonic_max_range,static_cast<float>(1.0));


    battery_full_level *= 100.0;
    battery_empty_level *= 100.0;

    pthread_mutex_init(&speed_mutex, NULL);
    g_chassis_mcu->Init(host_name, std::to_string(port), 0.975, f_dia, b_dia, axle, timeWidth, counts, reduction_ratio, speed_ratio);

}
/* chassis的初始化*/
bool InitChassis(int argc, char **argv,const char *node_name){

    ROS_INFO("[wc_chassis] init ros!");
    ros::init(argc, argv, node_name);
     p_n = new ros::NodeHandle();
     p_nh = new ros::NodeHandle("~");
     p_device_nh = new ros::NodeHandle("device");
     p_loop_rate =  new ros::Rate(10);

     InitService();
     InitParameter();
     return true;
}
