#include "ros/ros.h"
#include <iomanip>
#include "px_comm/OpticalFlow.h"
#include <cmath>
#include "px4flow_normalized_trajectory/Px4flow_trajectory.h"

double x = 0.0;
double y = 0.0;
double usec_time_before = 0.0;

class px4flow_norm_trajectory {
	public:
		void normalize_data();
	private:
		void callback(const px_comm::OpticalFlow& msg);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
		px4flow_normalized_trajectory::Px4flow_trajectory data;
};



void px4flow_norm_trajectory::normalize_data() {
	
	pub = n.advertise<px4flow_normalized_trajectory::Px4flow_trajectory>("/px4flow_normalized_trajectory", 10);
	sub = n.subscribe("/px4flow/opt_flow", 1000, &px4flow_norm_trajectory::callback, this);
	
}



void px4flow_norm_trajectory::callback(const px_comm::OpticalFlow& msg) {
	x = x + ( ( msg.velocity_x * (msg.flow_time_usec - usec_time_before) ) / 1000000);
	data.x = -1 * x;
	y = y + ( ( msg.velocity_y * (msg.flow_time_usec - usec_time_before) ) / 1000000);
	data.y = y;
	data.z = msg.ground_distance;
	usec_time_before = msg.flow_time_usec;
	data.header = msg.header;
	data.q = msg.quality;
	pub.publish(data);

}

int main (int argc, char **argv) {

	ros::init(argc, argv, "normalized_trajectory_px4flow");
	px4flow_norm_trajectory my_trajectory;
	my_trajectory.normalize_data();
	ros::spin();
}
