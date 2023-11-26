#pragma once

#include "objects.h"

class RectilinearMotion {
public:
	RectilinearMotion(Entity& e, double elapsed, double already_travelled, double horizontal_component, double vertical_component, double inclination);
	void refreshVelocity(double new_velocity);
	void refreshAcceleration(double new_acceleration);
	void setTravelledSpace(double already_travelled);
	void setInclination(double inclination_rad);
	void setElapsedTime(double elapsed);
	void moveForward(double actual_time, double angle_rad);
	double getTravelledSpace();
	double getElapsedTime();
	double getInclination();
private:
	Entity& object;					// Entity in movement
	double elapsed_time;			// Elapsed time from starting moving
	double travelled;				// Travelled space until now
	double x_travelled;				// Travelled space along x axis
	double y_travelled;				// Travelled space along y axis
	double global_theta;			// Angle as compared to x axis
};