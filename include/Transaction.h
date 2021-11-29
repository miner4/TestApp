/*
 * Transaction.h
 *
 *  Created on: 29.11.2021
 *      Author: bvez
 */

#ifndef SRC_TRANSACTION_H_
#define SRC_TRANSACTION_H_

#include <stdint.h>
#include <chrono>

class Transaction {
	friend class Account;

public:
	Transaction(float TransactionAmount);
	virtual ~Transaction();

	float getAmount() {
		return Amount;
	}
	uint64_t getId() {
		return Id;
	}
	bool operator<(const Transaction &rhs) const;

private:
	void setTimestamp(std::time_t &timestamp);

private:
	uint64_t Id;
	std::time_t Timestamp;
	float Amount;
};

#endif /* SRC_TRANSACTION_H_ */
