/*
 * Bus.cpp
 *
 *  Created on: 28.11.2021
 *      Author: bvez
 */

#include "Bus.h"
#include "Vehicle.h"

Bus::Bus() :
		Vehicle::Vehicle(10) {
}

Bus::~Bus() {
	// TODO Auto-generated destructor stub
}

int Bus::vFunc() {
	return 5;
}

