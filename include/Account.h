/*
 * Account.h
 *
 *  Created on: 29.11.2021
 *      Author: bvez
 */

#ifndef INCLUDE_ACCOUNT_H_
#define INCLUDE_ACCOUNT_H_

#include <string>
#include <stdint.h>
#include <mutex>
#include <map>
#include <queue>
#include "Transaction.h"

class Account {
public:
	Account(const std::string &name);
	virtual ~Account();

	std::string& getLabel() {
		return Label;
	}
	float getTotal();

	bool applyCreditTransaction(Transaction &t); //OUT
	bool applyDebitTransaction(Transaction &t); //IN
	virtual void getHistory();

private:
	bool saveTransaction(Transaction &t, bool isDebit);

private:
	std::mutex Mutex;
	std::string Label;
	float Total = 0.00;
	std::map<uint64_t, bool> TransactionIdMap;
	std::queue<Transaction> Transactions;
};

#endif /* INCLUDE_ACCOUNT_H_ */
