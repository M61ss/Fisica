#pragma once

#include "objects.h"

class RectilinearMotion {
public:
	RectilinearMotion(Entity& e, double elapsed, double already_travelled, double inclination);
	void refreshVelocity(double new_velocity);
	void refreshAcceleration(double new_acceleration);
	void refreshInclination(double inclination);
	void setPastTravelledSpace(double already_travelled);
	void setDelayTime(double elapsed);
	void moveForward(double motion_time);
	void airDistance();
	double getCurrentX();
	double getCurrentY();
	double getTravelledSpace();
	double getElapsedTime();
	double getInclination();
	void display();
private:
	Entity& object;					// Entity in movement
	double total_time;				// This is the total time elapsed moving in space after the start
	double past_travelled;			// Total space travelled before starting this istance of motion
	double travelled;				// Travelled space until now
	double distance;				// This is the distance by air between two points
	double x_end;					// X coord of the final point
	double y_end;					// Y coord of the final point
	double x_start;					// X coord of the start point
	double y_start;					// Y coord of the start point
	double radiant;					// Angle as compared to x axis (in radiant)
};