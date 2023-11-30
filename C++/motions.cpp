#include "objects.h"
#include "motions.h"

// mini-function to neglect full rotations
int base4(int n) {
	if (n > 3) {
		return n % 4;
	}
}

// CONSTRUCTOR
RectilinearMotion::RectilinearMotion(Entity& e, double elapsed, double already_travelled, double inclination) : object(e) {
	past_travelled = already_travelled;		// it is not requested to know specifics about precedent movements... if you want to know those, you can reuse
											// this program starting with other data (however, for now it isn't my purpose, maybe into another more advanced version)
	travelled = 0;					// this variable refers to the space travelled in that instance of motion, neglecting other specifics of past motions
	elapsed_time = elapsed;
	while (inclination >= 360) {
		inclination -= 360;
	}
	degree = inclination;
	if (degree >= 0 && degree < 90) {
		start_quadrant = 0;
	}
	else if (degree >= 90 && degree < 180) {
		start_quadrant = 1;
	}
	else if (degree >= 180 && degree < 270) {
		start_quadrant = 2;
	}
	else {
		start_quadrant = 3;
	}
	phase_displacement = 0;		// because at the start of the movement it is clear that the phase displacement cannot exist
	x_start = 0;
	y_start = 0;
	x_end = 0;					// these values will be assigned after calculations, so 0 is a tmp value
	y_end = 0;					// these values will be assigned after calculations, so 0 is a tmp value
}

// SET
void RectilinearMotion::setPastTravelledSpace(double already_travelled) {
	past_travelled = already_travelled;
}
void RectilinearMotion::setElapsedTime(double elapsed) {
	elapsed_time = elapsed;
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
	return elapsed_time;
}
double RectilinearMotion::getInclination() {
	return degree;
}

// REFRESH
void RectilinearMotion::refreshVelocity(double new_velocity) {
	object.setVelocity(new_velocity);
}
void RectilinearMotion::refreshAcceleration(double new_acceleration) {
	object.setAcceleration(new_acceleration);
}
void RectilinearMotion::refreshTime(double new_time) {
	elapsed_time = new_time;
}
void RectilinearMotion::refreshInclination(double inclination) {
	degree += inclination;
}

// MOVEMENT
void RectilinearMotion::moveForward(double actual_time) {
	double radiant = degree / 57.2958;
	// bisogna valutare quando detrarre una certa quantità di coordinata x o y in caso si torni indietro 
	x_end += (travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2)) * cos(radiant);
	y_end += (travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2)) * sin(radiant);
	
	travelled += travelled + object.getVelocity() * (actual_time - elapsed_time) + 0.5 * object.getAcceleration() * pow((actual_time - elapsed_time), 2);
	refreshTime(actual_time + elapsed_time);
	refreshVelocity(object.getVelocity() + object.getAcceleration() * (actual_time - elapsed_time));
}

// STDOUT
void RectilinearMotion::display() {
	std::cout << "Total space travelled: " << travelled << " + " << past_travelled << "m.\n";
	std::cout << "X: " << x_end << "m.\n";
	std::cout << "Y: " << y_end << "m.\n";
	std::cout << "Elapsed time: " << elapsed_time << "s.\n";
	std::cout << "Degree: " << degree << "°.\n";
}