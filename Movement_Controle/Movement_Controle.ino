#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Servo.h>

Servo myservo1; // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

float joint1,joint2,joint3,joint4,joint5,joint6;

ros::NodeHandle nh;

void velCallback (const geometry_msgs::Twist& vel)
{
joint1 = vel.linear.x;
joint2 = vel.linear.y;
joint3 = vel.linear.z;
joint4 = vel.angular.x;
joint5 = vel.angular.y;
joint6 = vel.angular.z;
myservo1.write(joint1);
myservo2.write(joint2-40);
myservo3.write(joint3-30);
myservo4.write(joint4);
myservo5.write(joint5+40);
myservo6.write(joint6);

}

ros::Subscriber<geometry_msgs::Twist> sub("Servo",velCallback);

void setup() {
myservo1.attach(5); //done
myservo2.attach(6);//done // 30 50 80
myservo3.attach(7);//done
myservo4.attach(3);//done
myservo5.attach(4);//done
myservo6.attach(2);

nh.initNode();
nh.subscribe(sub);
myservo1.write(0);
myservo2.write(90);
myservo3.write(0);
myservo4.write(90);
myservo5.write(90);
myservo6.write(30);


}

void loop() {



nh.spinOnce();
//delay(10);
}
