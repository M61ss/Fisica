#include "objects.h"
#include "motions.h"

RectilinearMotion::RectilinearMotion(Entity& e) : travelled(0), object(e), elapsed_time(0), horizontal_travelled(0), vertical_travelled(0) {}
RectilinearMotion::RectilinearMotion(Entity& e, double elapsed) : travelled(0), object(e), elapsed_time(elapsed), horizontal_travelled(0), vertical_travelled(0) {}
RectilinearMotion::RectilinearMotion(Entity& e, double already_travelled, double horizontal_component, double vertical_component) : travelled(already_travelled), object(e), elapsed_time(0), horizontal_travelled(horizontal_component), vertical_travelled(vertical_component) {}
RectilinearMotion::RectilinearMotion(Entity& e, double elapsed, double already_travelled, double horizontal_component, double vertical_component) : travelled(already_travelled), object(e), elapsed_time(elapsed), horizontal_travelled(horizontal_component), vertical_travelled(vertical_component) {}

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

void RectilinearMotion::moveForward(double actual_time, double angle_rad) {
	travelled = (travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2)) * cos(angle_rad);
	refreshVelocity(object.getVelocity() + object.getAcceleration() * (actual_time - elapsed_time));
}

double RectilinearMotion::getTravelledSpace() {
	return travelled;
}

double RectilinearMotion::getElapsedTime() {
	return elapsed_time;
}