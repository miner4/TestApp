/*
 * Transaction.cpp
 *
 *  Created on: 29.11.2021
 *      Author: bvez
 */

#include <stdint.h>
#include <math.h>

#include "Transaction.h"
#include "Util.h"

Transaction::Transaction(float TransactionAmount) {
	Amount = Util::roundTo2Digits(TransactionAmount);
	Id = reinterpret_cast<uint64_t>(this);
}

Transaction::~Transaction() {
	// TODO Auto-generated destructor stub
}

void Transaction::setTimestamp(std::time_t &timestamp) {
	Timestamp = timestamp;
}

bool Transaction::operator<(const Transaction &rhs) const {
	return Id < rhs.Id;
}
