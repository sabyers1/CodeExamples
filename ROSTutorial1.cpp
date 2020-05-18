//#include <iostream>
#include <ros/ros.h>
#include <signal.h>

using namespace std;

void mySigintHandler(int sig){
    // custom action as required
    // For example, publish a stop message to some other node

    //All the default sigint handler does is call shutdown()
    ros::shutdown();
}

int main(int argc, char** argv){

    ros::init(argc, argv, "sim",ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;

    // Override the default ros sigint handler.
    // This must be set after the first NodeHandle is created
    signal(SIGINT, mySigintHandler);


    //...
    std::cout<<"ROS Tutorial - spinning"<<std::endl;
    ros::spin();
    std::cout<<"ROS Tutorial - done"<<std::endl;

    return 0;
}