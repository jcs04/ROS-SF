#include "ros/ros.h"
#include <iomanip>
#include "adns3080_normalized_trajectory/Adns3080_trajectory.h"
#include "adns3080_msg/Adns3080.h"
#include <cmath>
#include <list>
using namespace std; 

double x = 0.0;
double y = 0.0;
double pi = 3.14159265358;
double num = (11.6 * pi);
double den = 180.0 * 30.0;
double prom = 0.0;




class adns3080_norm_trajectory {
	public:
		void normalize_data();
	private:
		void callback(const adns3080_msg::Adns3080& msg);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
		adns3080_normalized_trajectory::Adns3080_trajectory data;
		list<double> L;
		list<double>::iterator i;

};


void adns3080_norm_trajectory::normalize_data() {
	
	pub = n.advertise<adns3080_normalized_trajectory::Adns3080_trajectory>("/Adns3080_normalized_trajectory", 10);
	sub = n.subscribe("/adns3080", 1000, &adns3080_norm_trajectory::callback, this);

}

void adns3080_norm_trajectory::callback(const adns3080_msg::Adns3080& msg) {
	
	if (L.size() < 30) {
		L.push_front(msg.distance);
		x = x + ((msg.flow_x * num * msg.distance) / den);
		y = y + ((msg.flow_y * num * msg.distance) / den);
		data.z = msg.distance;
	} else {
		L.push_front(msg.distance);
		L.pop_back();
		prom = 0.0;
		for(i=L.begin(); i != L.end(); ++i) {
			prom = prom + *i;
		}
		prom = prom / 30;
		x = x + ((msg.flow_x * num * prom) / den);
		y = y + ((msg.flow_y * num * prom) / den);
		data.z = prom;		
	}

	data.x = -1 *x;
	data.y = y;
	data.q = msg.quality * (255.0/169.0);
	data.header = msg.header;
	pub.publish(data);
}

int main (int argc, char **argv) {

	ros::init(argc, argv, "adns3080_normalized_trajectory");
	adns3080_norm_trajectory my_trajectory;
	my_trajectory.normalize_data();
	ros::spin();
}
