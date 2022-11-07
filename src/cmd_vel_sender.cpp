#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <geometry_msgs/Twist.h>

ros::Publisher  pub_omniwheel_velocity;

// float calc_wheels_k()
// {
//     //float wheels_k =  get joint value + wheel pos + etc~~
//     float wheels_k = 0.521500;
//     return wheels_k;
// }

float wheels_radius_ = 0.09;
float wheels_k_ = 0.521500;

void Callback_cmd_vel(const geometry_msgs::Twist& msg){
   //Using the callback function just for subscribing  
   //Subscribing the message and storing it in 'linx' and 'angZ'

    const double w0_vel = 1.0 / wheels_radius_ * (msg.linear.x - msg.linear.y - wheels_k_ * msg.angular.z);
    const double w1_vel = 1.0 / wheels_radius_ * (msg.linear.x + msg.linear.y - wheels_k_ * msg.angular.z);
    const double w2_vel = 1.0 / wheels_radius_ * (msg.linear.x - msg.linear.y + wheels_k_ * msg.angular.z);
    const double w3_vel = 1.0 / wheels_radius_ * (msg.linear.x + msg.linear.y + wheels_k_ * msg.angular.z);
    
    std_msgs::Float32MultiArray omniwheel_velocity;  
    omniwheel_velocity.data.push_back(w0_vel);
    omniwheel_velocity.data.push_back(w1_vel);
    omniwheel_velocity.data.push_back(w2_vel);
    omniwheel_velocity.data.push_back(w3_vel);
    pub_omniwheel_velocity.publish(omniwheel_velocity);

}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_vel_sender");
    ros::NodeHandle n;
    pub_omniwheel_velocity = n.advertise<std_msgs::Float32MultiArray>("/omniwheel/velocity", 10);
    ros::Subscriber sub = n.subscribe("/omniwheel_agv/omniwheel_velocity_controller/cmd_vel", 10, Callback_cmd_vel);
    ros::spin();
    return 0;
}