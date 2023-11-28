#include "objects.h"
#include "motions.h"

RectilinearMotion::RectilinearMotion(Entity& e, double elapsed, double already_travelled, double horizontal_component, double vertical_component, double inclination) : object(e) {
	travelled = already_travelled;
	elapsed_time = elapsed;
	x_end = horizontal_component;
	y_end = vertical_component;
	degree = inclination;
	x_start = 0;
	y_start = 0;
}

void RectilinearMotion::refreshVelocity(double new_velocity) {
	object.setVelocity(new_velocity);
}

void RectilinearMotion::refreshAcceleration(double new_acceleration) {
	object.setAcceleration(new_acceleration);
}

void RectilinearMotion::refreshTime(double new_time) {
	elapsed_time = new_time;
}

void RectilinearMotion::setTravelledSpace(double already_travelled) {
	travelled = already_travelled;
}

void RectilinearMotion::setElapsedTime(double elapsed) {
	elapsed_time = elapsed;
}

void RectilinearMotion::setInclination(double inclination_rad) {
	degree = inclination_rad;
}

void RectilinearMotion::moveForward(double actual_time) {
	double radiant = degree / 57.2958;
	// bisogna valutare quando detrarre una certa quantità di coordinata x o y in caso si torni indietro 
	x_end += (travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2)) * cos(radiant);
	y_end += (travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2)) * sin(radiant);
	
	travelled += travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2);
	refreshTime(actual_time);
	refreshVelocity(object.getVelocity() + object.getAcceleration() * (actual_time - elapsed_time));
}

double RectilinearMotion::getCurrentX() {
	return x_end;
}
double RectilinearMotion::getCurrentY() {
	return y_end;
}

double RectilinearMotion::getTravelledSpace() {
	return travelled;
}

double RectilinearMotion::getElapsedTime() {
	return elapsed_time;
}

double RectilinearMotion::getInclination() {
	return degree;
}

void RectilinearMotion::display() {
	std::cout << "Total space travelled: " << travelled << "m.\n";
	std::cout << "X: " << x_end << "m.\n";
	std::cout << "Y: " << y_end << "m.\n";
	std::cout << "Elapsed time: " << elapsed_time << "s.\n";
	std::cout << "Degree: " << degree << "°.\n";
}