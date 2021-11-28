/*
 * Vehicle.cpp
 *
 *  Created on: 28.11.2021
 *      Author: bvez
 */

#include "Vehicle.h"

Vehicle::Vehicle(int fuelCapacity) {
	this->fuelCapacity = fuelCapacity;
}

Vehicle::~Vehicle() {
	// TODO Auto-generated destructor stub
}

int Vehicle::getFuelCapacity() {
	return fuelCapacity;
}

void Vehicle::pushStuff(int j) {
	this->v.push_back(j);
}
std::vector<int>& Vehicle::getV() {
	return this->v;
}
