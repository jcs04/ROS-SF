#include "ros/ros.h"
#include <iomanip>
#include "px_comm/OpticalFlow.h"
#include <visualization_msgs/Marker.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Point.h>

int x = 0;
int y = 0;

class px4flow_trajectory {
	public:
		void get_point();
	private:
		void callback(const px_comm::OpticalFlow& msg);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
		visualization_msgs::Marker pointx, line_strip;
};



void px4flow_trajectory::get_point() {
	
	pub = n.advertise<visualization_msgs::Marker>("/trajectory_px4flow", 10);
	sub = n.subscribe("/px4flow/opt_flow", 1000, &px4flow_trajectory::callback, this);
				
	
	pointx.header.frame_id = line_strip.header.frame_id = "/px4flow_view";
	pointx.header.stamp = line_strip.header.stamp = ros::Time::now();
	pointx.ns = line_strip.ns = "points_and_lines";
	pointx.action = line_strip.action = visualization_msgs::Marker::ADD;
	pointx.pose.orientation.w = line_strip.pose.orientation.w = 1.0;


	pointx.id = 0;
	line_strip.id = 1;
	pointx.type = visualization_msgs::Marker::SPHERE_LIST;
	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
	pointx.scale.x = 200;
	pointx.scale.y = 200;
	line_strip.scale.x = 1000;
	//Points light blue
	pointx.color.r = 0;
	pointx.color.g = 0.74902;
        pointx.color.b = 1;
	pointx.color.a = 1.0;

	//Line green
	line_strip.color.g = 1.0;
	line_strip.color.a = 1.0;
	
	
}



void px4flow_trajectory::callback(const px_comm::OpticalFlow& msg) {
	geometry_msgs::Point point;
	x = x - msg.flow_x;
	point.x = x;
	y = y - msg.flow_y;
	point.y = y;
	point.z = msg.ground_distance;
	


	pointx.points.push_back(point);
	line_strip.points.push_back(point);


	pub.publish(pointx);
	//pub.publish(line_strip);

}

int main (int argc, char **argv) {

	ros::init(argc, argv, "trajectory_px4flow");
	px4flow_trajectory my_trajectory;
	my_trajectory.get_point();
	ros::spin();
}
