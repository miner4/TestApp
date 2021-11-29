/*
 * Util.cpp
 *
 *  Created on: 29.11.2021
 *      Author: bvez
 */

#include "Util.h"

#include <math.h>

float Util::roundTo2Digits(float f) {
	float rounded = ceilf(f * 100) / 100;
	return ((int) (f * 100 + .5) / 100.0);
}

