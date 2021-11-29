#include <chrono>
#include <thread>

#include "gtest/gtest.h"
#include "Account.h"
#include "Transaction.h"

TEST(transactionUniqueness_sameType, test1) {
	Account acc("test_acc");
	Transaction initialTrans(50.0);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), true);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), false);
}

TEST(transactionUniqueness_differentType, test2) {
	Account acc("test_acc");
	Transaction initialTrans(50.0);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), true);

	Transaction secondTrans(10.0);

	EXPECT_EQ(acc.applyCreditTransaction(secondTrans), true);

	EXPECT_EQ(acc.applyDebitTransaction(secondTrans), false);
}
