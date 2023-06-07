#ifndef TABLE_TESTS_HPP
#define TABLE_TESTS_HPP

#include "gtest/gtest.h"
#include <chrono>
#include <unistd.h>

#include "../header/Table.h"
#include "../header/Server.h"

TEST(TableGetterTests, getSeats) {
    Table* myTable = new Table();
    int numSeats = myTable->getSeats();
    EXPECT_EQ(numSeats, 6);
    delete myTable;
}

TEST(TableGetterTests, getTableNum) {
    Table* myTable = new Table();
    int tableNum = myTable->getTableNum();
    EXPECT_EQ(tableNum, 0);
    delete myTable;
}

TEST(TableGetterTests, getCustomerGroup) {
    Table* myTable = new Table();
    Customer* myGroup = myTable->getCustomerGroup();
    EXPECT_EQ(myGroup, nullptr);
    delete myTable; 
}

TEST(TableSetterTests, setSeats) {
    Table* myTable = new Table();
    myTable->setSeats(4);
    EXPECT_EQ(myTable->getSeats(), 4);
    delete myTable;
}

TEST(TableSetterTests, setTableNum) {
    Table* myTable = new Table();
    myTable->setTableNum(8);
    EXPECT_EQ(myTable->getTableNum(), 8);
    delete myTable;
}

TEST(TableSetterTests, setCustomerGroup) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();  //deleted by table class destructor
    myTable->setCustomerGroup(myCustomer);
    EXPECT_NE(myTable->getCustomerGroup(), nullptr);
    delete myTable;
}

TEST(TableConstructorTests, noParameters) {
    Table* myTable = new Table();
    EXPECT_EQ(myTable->getSeats(), 6);
    EXPECT_EQ(myTable->getTableNum(), 0);
    EXPECT_TRUE(myTable->getAvailability());
    EXPECT_DOUBLE_EQ(myTable->getBill(), 0.0);
    EXPECT_TRUE(myTable->getCustomerGroup() == nullptr);
    delete myTable;
}

TEST(TableLeftoverSeatsTests, emptyTable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(0);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_EQ(myTable->getSeats(), 6);
    delete myTable;
}

TEST(TableLeftoverSeatsTests, takenTable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setRandomPartySize();
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_LT(myTable->getSeats(), 6);
    delete myTable;
}

TEST(TableAvailablityTests, fullyAvailable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(0);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_TRUE(myTable->getAvailability());
    EXPECT_TRUE(myTable->getCustomerGroup() != nullptr);
    delete myTable;
}

TEST(TableAvailablityTests, partiallyNotAvailable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(4);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_FALSE(myTable->getAvailability());
    EXPECT_NE(myTable->getCustomerGroup(), nullptr);
    delete myTable;
}

TEST(TableAvailablityTests, fullyNotAvailable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(6);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_FALSE(myTable->getAvailability());
    EXPECT_NE(myTable->getCustomerGroup(), nullptr);
    delete myTable;
}

TEST(TableBillTests, intBill) {
    Table* myTable = new Table();
    Server s = Server();
    s.setChosenTable(myTable);
    s.billTable(50.00);
    EXPECT_DOUBLE_EQ(myTable->getBill(), 50.00);
    delete myTable;
}

TEST(TableBillTests, doubleBill) {
    Table* myTable = new Table();
    Server s = Server();
    s.setChosenTable(myTable);
    s.billTable(50.25);
    EXPECT_DOUBLE_EQ(myTable->getBill(), 50.25);
    delete myTable;
}

TEST(TableTimeTests, positiveDuration) {
    Table* myTable = new Table();
    myTable->setEntryTime(chrono::steady_clock::now());
    usleep(1000000);
    myTable->setExitTime(chrono::steady_clock::now());
    EXPECT_GT(myTable->getTotalTime(), 0);
    delete myTable;
}

#endif