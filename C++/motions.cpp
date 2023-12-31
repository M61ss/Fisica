#include "objects.h"
#include "motions.h"
#include "math_functions.h"

double toRadiant(double deg) {
	return deg / 57.2958;
}
double toDegree(double rad) {
	return rad * 57.2958;
}

// CONSTRUCTOR
RectilinearMotion::RectilinearMotion(Entity& e, double elapsed, double already_travelled, double inclination) : object(e) {
	past_travelled = already_travelled;		// it is not requested to know specifics about precedent movements... if you want to know those, you can reuse
											// this program starting with other data (however, for now it isn't my purpose, maybe into another more advanced version)
	travelled = 0;					// this variable refers to the space travelled in that instance of motion, neglecting other specifics of past motions
	distance = 0;
	total_time = elapsed;
	radiant = toRadiant(inclination);
	x_start = 0;
	y_start = 0;
	x_end = 0;					// these values will be assigned after calculations, so 0 is a tmp value
	y_end = 0;					// these values will be assigned after calculations, so 0 is a tmp value
}

// SET
void RectilinearMotion::setPastTravelledSpace(double already_travelled) {
	past_travelled = already_travelled;
}
void RectilinearMotion::setDelayTime(double elapsed) {
	total_time += elapsed;
}

// GET
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
	return total_time;
}
double RectilinearMotion::getInclination() {
	return toDegree(radiant);
}

// REFRESH
void RectilinearMotion::refreshVelocity(double new_velocity) {
	object.setVelocity(new_velocity);
}
void RectilinearMotion::refreshAcceleration(double new_acceleration) {
	object.setAcceleration(new_acceleration);
}
void RectilinearMotion::refreshInclination(double inclination) {
	radiant = toRadiant(inclination);
}

// MOVEMENT
void RectilinearMotion::moveForward(double motion_time) {
	x_start = x_end;
	y_start = y_end;

	x_end += (object.getVelocity() * motion_time + 0.5 * object.getAcceleration() * pow(motion_time, 2)) * cos(radiant);
	y_end += (object.getVelocity() * motion_time + 0.5 * object.getAcceleration() * pow(motion_time, 2)) * sin(radiant);
	
	travelled += travelled + object.getVelocity() * motion_time + 0.5 * object.getAcceleration() * pow(motion_time, 2);
	setDelayTime(motion_time);
	refreshVelocity(object.getVelocity() + object.getAcceleration() * motion_time);
	airDistance();
}
void RectilinearMotion::airDistance() {
	distance = Pitagora(x_end, y_end);
}

// DISPLAY
void RectilinearMotion::display() {
	std::cout << "Total space travelled: " << travelled << " + " << past_travelled << "m.\n";
	std::cout << "X: " << x_end << "m.\n";
	std::cout << "Y: " << y_end << "m.\n";
	std::cout << "Distance between two points: " << distance << "m.\n";
	std::cout << "Total motion time: " << total_time << "s.\n";
	std::cout << "Degree: " << toDegree(radiant) << "�.\n";
}