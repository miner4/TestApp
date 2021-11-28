/*
 * Vehicle.h
 *
 *  Created on: 28.11.2021
 *      Author: bvez
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <vector>

class Vehicle {
public:
	Vehicle(int fuelCapacity);
	virtual ~Vehicle();

public:
	virtual int vFunc() = 0;
	int getFuelCapacity();
	void pushStuff(int j);

	std::vector<int>& getV();

private:
	std::vector<int> v;
	int fuelCapacity;

};

#endif /* VEHICLE_H_ */
