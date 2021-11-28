/*
 * Bus.h
 *
 *  Created on: 28.11.2021
 *      Author: bvez
 */

#ifndef BUS_H_
#define BUS_H_

#include "Vehicle.h"

class Bus: public Vehicle {
public:
	Bus();
	virtual ~Bus();

	int vFunc() override;
};

#endif /* BUS_H_ */
