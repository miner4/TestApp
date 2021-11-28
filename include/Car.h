/*
 * Car.h
 *
 *  Created on: 28.11.2021
 *      Author: bvez
 */

#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"

class Car: public Vehicle {
public:
	Car(int fuelCapacity);
	virtual ~Car();
};

#endif /* CAR_H_ */
