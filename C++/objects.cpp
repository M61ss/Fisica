#include "objects.h"

Charge::Charge(double c) : charge(c) {}

Entity::Entity(double m) : mass(m) {
    velocity = 0;
    acceleration = 0;
}

void Entity::setVelocity(double new_velocity) {
    velocity = new_velocity;
}

void Entity::setAcceleration(double new_acceleration) {
    acceleration = new_acceleration;
}

double Entity::getVelocity() {
    return velocity;
}

double Entity::getAcceleration() {
    return acceleration;
}

double Entity::momentum() {
    return mass * velocity;
}

double Entity::force() {
    return mass * acceleration;
}

double Entity::work(double space) {
    return force() * space;
}
