/*
 * Account.cpp
 *
 *  Created on: 29.11.2021
 *      Author: bvez
 */

#include "Account.h"
#include "Util.h"
#include <string>
#include <iostream>
#include <chrono>
#include <math.h>

Account::Account(const std::string &Name) {
	Label = Name;

}

Account::~Account() {
}

float Account::getTotal() {
	return Util::roundTo2Digits(Total);
}

bool Account::saveTransaction(Transaction &t, bool isDebit) {
	if (TransactionIdMap.count(t.getId())) {
		return false;

	} else {

		TransactionIdMap.insert( { t.getId(), isDebit });

		size_t numOfTransactions = Transactions.size();

		auto now = std::chrono::system_clock::now();
		std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

		t.setTimestamp(timestamp);
		Transactions.push(t);

		size_t newNumOfTransactions = Transactions.size();
		return numOfTransactions < newNumOfTransactions;
	}
}

bool Account::applyCreditTransaction(Transaction &t) {
	std::lock_guard<std::mutex> guard(Mutex);

	if (0 <= Util::roundTo2Digits(Total - t.getAmount())) {
		if (saveTransaction(t, false)) {
			Total = Util::roundTo2Digits(Total - t.getAmount());

			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool Account::applyDebitTransaction(Transaction &t) {
	std::lock_guard<std::mutex> guard(Mutex);

	if (saveTransaction(t, true)) {
		Total = Util::roundTo2Digits(Total + t.getAmount());

		return true;
	} else {
		return false;
	}
}

void Account::getHistory() {
	std::queue<Transaction> tmp_q = Transactions;

	while (!tmp_q.empty()) {
		Transaction q_element = tmp_q.front();
		std::cout << q_element.getAmount() << "\n"; // TODO get trans type from map and print nice history
		tmp_q.pop();
	}
}

