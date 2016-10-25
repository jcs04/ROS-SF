#include "ros/ros.h"
#include <iomanip>
#include "adns3080_msg/Adns3080.h"
#include <visualization_msgs/Marker.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Point.h>
#include <cmath>

double x = 0.0;
double y = 0.0;


class adns3080_trajectory {
	public:
		void get_point();
	private:
		void callback(const adns3080_msg::Adns3080& msg);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
		visualization_msgs::Marker pointx, line_strip;
};



void adns3080_trajectory::get_point() {
	
	pub = n.advertise<visualization_msgs::Marker>("/trajectory_adns3080", 10);
	sub = n.subscribe("/adns3080", 1000, &adns3080_trajectory::callback, this);
				
	
	pointx.header.frame_id = line_strip.header.frame_id = "/adns3080_view";
	pointx.header.stamp = line_strip.header.stamp = ros::Time::now();
	pointx.ns = line_strip.ns = "points_and_lines";
	pointx.action = line_strip.action = visualization_msgs::Marker::ADD;
	pointx.pose.orientation.w = line_strip.pose.orientation.w = 1.0;

	pointx.id = 0;
	line_strip.id = 1;
	pointx.type = visualization_msgs::Marker::SPHERE_LIST;
	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
	pointx.scale.x = 5;
	pointx.scale.y = 5;
	line_strip.scale.x = 20;

	line_strip.color.r = 0.780392;
	line_strip.color.g = 0.0823529;
	line_strip.color.b = 0.521569;
	line_strip.color.a = 1.0;

	pointx.color.r = 0.780392;
	pointx.color.g = 0.0823529;
        pointx.color.b = 0.521569;
	pointx.color.a = 1.0;
	
	
}



void adns3080_trajectory::callback(const adns3080_msg::Adns3080& msg) {
	geometry_msgs::Point point;
	x = x + msg.flow_x;
	point.x = x;
	y = y + msg.flow_y;
	point.y = y;
	point.z = msg.distance;



	pointx.points.push_back(point);
	line_strip.points.push_back(point);


	pub.publish(pointx);
	//pub.publish(line_strip);

}

int main (int argc, char **argv) {

	ros::init(argc, argv, "trajectory_adns3080_view");
	adns3080_trajectory my_trajectory;
	my_trajectory.get_point();
	ros::spin();
}
