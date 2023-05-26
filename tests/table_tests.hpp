#ifndef TABLE_TESTS_HPP
#define TABLE_TESTS_HPP

#include "gtest/gtest.h"
#include "../header/Table.h"

//#include "../header/Table.h"

TEST(TableConstructorTests, noParameters) {
    Table* myTable = new Table();
    EXPECT_EQ(myTable->getSeats(), 6);
    EXPECT_TRUE(myTable->getAvailability());
    EXPECT_DOUBLE_EQ(myTable->getBill(), 0.0);
    EXPECT_TRUE(myTable->getCustomerGroup() == nullptr);
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
    delete myCustomer;
}

TEST(TableAvailablityTests, partiallyNotAvailable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(4);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_FALSE(myTable->getAvailability());
    EXPECT_TRUE(myTable->getCustomerGroup() != nullptr);
    delete myTable;
    delete myCustomer;
}

TEST(TableAvailablityTests, fullyNotAvailable) {
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(6);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_FALSE(myTable->getAvailability());
    EXPECT_TRUE(myTable->getCustomerGroup() != nullptr);
    delete myTable;
    delete myCustomer;
}

TEST(TableBillTests, twoItemsOrdered) {         //Not yet implemented
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(4);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_TRUE(myTable->getBill()>0);
}

TEST(TableBillTests, fourItemsOrdered) {        //Not yet implemented
    Table* myTable = new Table();
    Customer* myCustomer = new Customer();
    myTable->setCustomerGroup(myCustomer);
    myCustomer->setGroupSize(4);
    myTable->adjustLeftoverSeats(myCustomer->getGroupSize());
    EXPECT_TRUE(myTable->getBill()>0);
}

#endif