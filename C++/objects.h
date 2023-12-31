#pragma once

#include <iostream>
#define PI 3.14159265

class Charge {
public:
    Charge(double c);
private:
    double charge;
};

class Entity {
public:
    Entity(double m);
    void setVelocity(double vel);
    void setAcceleration(double acc);
    double getVelocity();
    double getAcceleration();
    double momentum();
    double force();
    double work(double space);
private:
    double mass;
    double velocity;
    double acceleration;
};
