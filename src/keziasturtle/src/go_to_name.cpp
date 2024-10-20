#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <iostream>
#include <cmath>

void move(ros::Publisher& pub, double speed, double distance, bool isForward){
    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x = isForward ? speed : -speed;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;
    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0;

    double t0 = ros::Time::now().toSec();
    double current_distance = 0.0;

    ros::Rate loop_rate(100);
    do{
        pub.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_distance = speed * (t1-t0);
        ros::spinOnce();
        loop_rate.sleep();
    } while(current_distance < distance);

    vel_msg.linear.x = 0;
    pub.publish(vel_msg);
}

void rotate(ros::Publisher& pub, double angular_speed, double relative_angle, bool clockwise){
    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x = 0;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;
    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = clockwise ? -angular_speed : angular_speed;

    double t0 = ros::Time::now().toSec();
    double current_angle = 0.0;

    ros::Rate loop_rate(10);
    do{
        pub.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_angle = angular_speed * (t1-t0);
        ros::spinOnce();
        loop_rate.sleep();
     } while(current_angle < relative_angle);

    vel_msg.angular.z = 0;
    pub.publish(vel_msg);
}

void drawK(ros::Publisher& pub) {
    geometry_msgs::Twist vel_msg;

    //Move backwards
    move(pub, 1.0, 5.0, false); 

    //Move upwards
    vel_msg.linear.y = 2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);
    
    //Move downwards
    vel_msg.linear.y = -2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

    //Rotate
    vel_msg.angular.z = M_PI/4;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move backward
    vel_msg.linear.x = -2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Rotate
    vel_msg.angular.z = -M_PI/2;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move backward
    vel_msg.linear.x = -2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Rotate
    vel_msg.angular.z = M_PI/4;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move downward
    vel_msg.linear.y = -2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

}

void drawE(ros::Publisher& pub){
    geometry_msgs::Twist vel_msg;

    //Move forward
    vel_msg.linear.x = 2.0;
    pub.publish(vel_msg);
    ros::Duration(3.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move upwards
    vel_msg.linear.y = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move backward
    vel_msg.linear.x = -1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move downward
    vel_msg.linear.y = -1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move backward
    vel_msg.linear.x = -1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move downward
    vel_msg.linear.y = -1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);
}

void drawZ(ros::Publisher& pub){
    geometry_msgs::Twist vel_msg;

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move upwards
    vel_msg.linear.y = 1.0;
    pub.publish(vel_msg);
    ros::Duration(4.0).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Rotate
    vel_msg.angular.z = M_PI/3;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move backward
    vel_msg.linear.x = -3.0;
    pub.publish(vel_msg);
    ros::Duration(6.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Rotate
    vel_msg.angular.z = -M_PI/3;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    }

void drawI(ros::Publisher& pub){
    geometry_msgs::Twist vel_msg;

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Move upwards
    vel_msg.linear.y = 2.0;
    pub.publish(vel_msg);
    ros::Duration(2.0).sleep();
    vel_msg.linear.y = 0;
    pub.publish(vel_msg);

}

void drawA(ros::Publisher& pub){
    geometry_msgs::Twist vel_msg;

    //Move forward
    vel_msg.linear.x = 1.0;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);  

    //Rotate
    vel_msg.angular.z = M_PI/2.5;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 2.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);

    //Rotate
    vel_msg.angular.z = -M_PI/1.25;
    pub.publish(vel_msg);
    ros::Duration(1.0).sleep();
    vel_msg.angular.z = 0;
    pub.publish(vel_msg);

    //Move forward
    vel_msg.linear.x = 2.0;
    pub.publish(vel_msg);
    ros::Duration(1.5).sleep();
    vel_msg.linear.x = 0;
    pub.publish(vel_msg);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "draw_keziasturtle");
    ros::NodeHandle n;

    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate loop_rate(0.5);

    drawK(vel_pub);
    loop_rate.sleep();
    drawE(vel_pub);
    loop_rate.sleep();
    drawZ(vel_pub);
    loop_rate.sleep();
    drawI(vel_pub);
    loop_rate.sleep();
    drawA(vel_pub);
    loop_rate.sleep();

    ROS_INFO("Kezia's Turtle Signing Out...");

    ros::spinOnce();

    return 0;
}

