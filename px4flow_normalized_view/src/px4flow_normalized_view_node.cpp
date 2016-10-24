#include "ros/ros.h"
#include <iomanip>
#include "px4flow_normalized_trajectory/Px4flow_trajectory.h"
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Point.h>
#include <cmath>

bool first = true;
bool second = false;
bool third = false;

class px4flow_trajectory_view {
	public:
		void draw_point();
	private:
		void callback(const px4flow_normalized_trajectory::Px4flow_trajectory& msg);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
		visualization_msgs::Marker pointx, line_strip;
};



void px4flow_trajectory_view::draw_point() {
	
	pub = n.advertise<visualization_msgs::Marker>("/normalized_trajectory_px4flow_view", 10);
	sub = n.subscribe("/px4flow_normalized_trajectory", 1000, &px4flow_trajectory_view::callback, this);
				
	
	pointx.header.frame_id = line_strip.header.frame_id = "/norm_view";
	pointx.header.stamp = line_strip.header.stamp = ros::Time::now();
	pointx.ns = line_strip.ns = "points_and_lines";
	pointx.action = line_strip.action = visualization_msgs::Marker::ADD;
	pointx.pose.orientation.w = line_strip.pose.orientation.w = 1.0;

	pointx.id = 0;
	line_strip.id = 1;
	pointx.type = visualization_msgs::Marker::SPHERE_LIST;
	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
	pointx.scale.x = 0.03;
	pointx.scale.y = 0.03;
	line_strip.scale.x = 0.01;

	//Points white
	pointx.color.r = 0;
	pointx.color.g = 0.74902;
        pointx.color.b = 1;
	pointx.color.a = 1.0;

	//Line green
	line_strip.color.r = 1;
	line_strip.color.g = 0.843137;
	line_strip.color.b = 0;
	line_strip.color.a = 1.0;
	
	
}



void px4flow_trajectory_view::callback(const px4flow_normalized_trajectory::Px4flow_trajectory& msg) {
	geometry_msgs::Point point;
	point.x = msg.x;
	point.y = msg.y;
	point.z = msg.z;

	geometry_msgs::Point point_baseline;
	point_baseline.x = 0;
	point_baseline.y = 0;
	point_baseline.z = 0;
	line_strip.points.push_back(point_baseline);
	point_baseline.x = -0.425;
	point_baseline.y = 0;
	point_baseline.z = 0;
	line_strip.points.push_back(point_baseline);


	/***point_baseline.x = -1;
	point_baseline.y = 1.5;
	point_baseline.z = 0;
	line_strip.points.push_back(point_baseline);
	point_baseline.x = -1;
	point_baseline.y = 0;
	point_baseline.z = 0;
	line_strip.points.push_back(point_baseline);
	point_baseline.x = 0;
	point_baseline.y = 0;
	point_baseline.z = 0;
	line_strip.points.push_back(point_baseline);***/
		




	pointx.points.push_back(point);
	


	pub.publish(pointx);
	pub.publish(line_strip);

}

int main (int argc, char **argv) {

	ros::init(argc, argv, "trajectory_px4flow_norm_view");
	px4flow_trajectory_view my_trajectory;
	my_trajectory.draw_point();
	ros::spin();
}
