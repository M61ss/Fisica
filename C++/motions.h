#pragma once

#include "objects.h"

class RectilinearMotion {
public:
	RectilinearMotion(Entity& e, double elapsed, double already_travelled, double inclination);
	void refreshVelocity(double new_velocity);
	void refreshAcceleration(double new_acceleration);
	void refreshTime(double new_time);
	void refreshInclination(double inclination);
	void setPastTravelledSpace(double already_travelled);
	void setElapsedTime(double elapsed);
	void moveForward(double actual_time);
	double getCurrentX();
	double getCurrentY();
	double getTravelledSpace();
	double getElapsedTime();
	double getInclination();
	void display();
private:
	Entity& object;					// Entity in movement
	double elapsed_time;			// Elapsed time from starting moving
	double past_travelled;			// Total space travelled before starting this istance of motion
	double travelled;				// Travelled space until now
	double x_end;					// X coord of the final point
	double y_end;					// Y coord of the final point
	double x_start;					// X coord of the start point
	double y_start;					// Y coord of the start point
	double degree;					// Angle as compared to x axis
	int start_quadrant;				// Starter quadrant
	int phase_displacement;			// Current relative position along the graphic
};