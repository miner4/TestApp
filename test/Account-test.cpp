#include <chrono>
#include <thread>

#include "gtest/gtest.h"
#include "Account.h"
#include "Transaction.h"

TEST(accountTotalnotLessThanZero, test1) {
	Account acc("test_acc");
	Transaction initialTrans(50.0);

	EXPECT_EQ(acc.applyCreditTransaction(initialTrans), false);
}

TEST(accountTotalnotLessThanZero, test2) {
	Account acc("test_acc");
	Transaction initialTrans(50.0);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), true);

	Transaction secondTrans(25.0);

	EXPECT_EQ(acc.applyCreditTransaction(secondTrans), true);
}

TEST(accountTotalnotLessThanZero, test3) {
	Account acc("test_acc");
	Transaction initialTrans(50.0);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), true);

	Transaction secondTrans(50.0);

	EXPECT_EQ(acc.applyCreditTransaction(secondTrans), true);
}

TEST(accountBalance2digitPrecision, test4) {
	Account acc("test_acc");

	EXPECT_EQ(acc.getTotal(), 0.00);

	Transaction initialTrans(50.00);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), true);

	EXPECT_EQ(acc.getTotal(), 50.00);

	Transaction secondTrans(25.89);

	EXPECT_EQ(acc.applyCreditTransaction(secondTrans), true);

	EXPECT_NEAR(acc.getTotal(), 24.11, 0.01);

	Transaction thirdTrans(12.05);

	EXPECT_EQ(acc.applyCreditTransaction(thirdTrans), true);

	EXPECT_NEAR(acc.getTotal(), 12.06, 0.01);

	Transaction fourthTrans(12.06);

	EXPECT_EQ(acc.applyCreditTransaction(fourthTrans), true);

	EXPECT_NEAR(acc.getTotal(), 0.00, 0.01);
}

TEST(accountHistory, test5) {
	Account acc("test_acc");

	Transaction initialTrans(50.00);

	EXPECT_EQ(acc.applyDebitTransaction(initialTrans), true);

	acc.getHistory();
}
