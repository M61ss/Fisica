#include "objects.h"
#include "motions.h"

RectilinearMotion::RectilinearMotion(Entity& e, double elapsed, double already_travelled, double horizontal_component, double vertical_component, double inclination) : object(e) {
	travelled = already_travelled;
	elapsed_time = elapsed;
	x_travelled = horizontal_component;
	y_travelled = vertical_component;
	global_theta = inclination;
}

void RectilinearMotion::refreshVelocity(double new_velocity) {
	object.setVelocity(new_velocity);
}

void RectilinearMotion::refreshAcceleration(double new_acceleration) {
	object.setAcceleration(new_acceleration);
}

void RectilinearMotion::setTravelledSpace(double already_travelled) {
	travelled = already_travelled;
}

void RectilinearMotion::setElapsedTime(double elapsed) {
	elapsed_time = elapsed;
}

void RectilinearMotion::setInclination(double inclination_rad) {
	global_theta = inclination_rad;
}

void RectilinearMotion::moveForward(double actual_time, double angle_rad) {
	double new_global_theta = angle_rad + global_theta;
	while (new_global_theta > (2 * PI) || new_global_theta < ((-PI) * 2)) {
		// In this case I have to remove complete rounds that do not matter
		if (new_global_theta < 0) {
			new_global_theta += PI * 2;
		}
		else {
			new_global_theta -= PI * 2;
		}
	}

	bool x_go_back = false;
	bool y_go_back = false;
	if (new_global_theta > PI || new_global_theta < (-PI)) {
		// In this case the path returns back as compared to y axis direction
		y_go_back = true;
	}
	if (new_global_theta > (PI / 2) || new_global_theta < ((-PI) / 2)) {
		// If this condition is verified, the path returns back as compared to x axis direction
		x_go_back = true;
	}
	travelled = (travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2));
	refreshVelocity(object.getVelocity() + object.getAcceleration() * (actual_time - elapsed_time));
	global_theta += angle_rad;
}

double RectilinearMotion::getTravelledSpace() {
	return travelled;
}

double RectilinearMotion::getElapsedTime() {
	return elapsed_time;
}

double RectilinearMotion::getInclination() {
	return global_theta;
}