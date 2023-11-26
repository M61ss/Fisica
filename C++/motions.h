#pragma once

#include "objects.h"

class RectilinearMotion {
public:
	RectilinearMotion(Entity& e);
	RectilinearMotion(Entity& e, double elapsed);
	RectilinearMotion(Entity& e, double already_travelled, double horizontal_component, double vertical_component);
	RectilinearMotion(Entity& e, double elapsed, double already_travelled, double horizontal_component, double vertical_component);
	void refreshVelocity(double new_velocity);
	void refreshAcceleration(double new_acceleration);
	void setTravelledSpace(double already_travelled);
	void setElapsedTime(double elapsed);
	void moveForward(double actual_time, double angle_rad);
	double getTravelledSpace();
	double getElapsedTime();
private:
	Entity& object;
	double elapsed_time;
	double travelled;
	double horizontal_travelled;
	double vertical_travelled;
};