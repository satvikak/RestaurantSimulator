#ifndef CUSTOMER_TESTS_HPP
#define CUSTOMER_TESTS_HPP

#include "gtest/gtest.h"

#include "../header/Customer.h"

TEST(CustomerConstructor, ThreeParameters) {
    vector<string> names{"sam", "paula", "carl"};
    Customer customer(3, names, 10);
    EXPECT_EQ(customer.getGroupSize(), 3);   
}

TEST(CustomerRandomTests, GenerateOneRandomOrder) {
    vector<string> names{"sam", "paula", "carl", "john", "pam"};
    Customer customer(5, names, 20);
    OrderNode newOrderObject = customer.generateRandomOrder("sam");
    int itemNumber = newOrderObject.getItemNumber();
    string itemName = newOrderObject.getCustomerName();
    EXPECT_TRUE(itemNumber >= 1);
    EXPECT_TRUE(itemNumber <= 20);
    EXPECT_TRUE(itemName == "sam");
}

TEST(CustomerRandomTests, GenerateListOfRandomOrders) {
    vector<string> names{"sam", "paula", "carl", "john", "pam", "josh"};
    vector<OrderNode> ordersList;
    Customer customer(6, names, 25);
    customer.generateOrders(ordersList);
    EXPECT_TRUE(ordersList.size() == 6);
}

TEST(CustomerGetterSetterTests, getGroupSizeTest) {
    vector<string> names{"sam", "paula", "carl", "john", "pam", "josh", "Naveen", "Jason", "Paul", "Fiona"};
    Customer customer(10, names, 25);
    int groupSize = customer.getGroupSize();
    EXPECT_TRUE(groupSize == 10);

    vector<string> twoNames{"sam", "paula"};
    Customer customer2(2, names, 25);
    int groupSize2 = customer2.getGroupSize();
    EXPECT_TRUE(groupSize2 == 2);
}

TEST(CustomerConstructor, TwoParameters) {
    vector<string> names{"sam", "paula", "carl", "john", "pam", "josh", "Naveen", "Jason", "Paul", "Fiona"};
    Customer customer(names, 25);
    int partySize = customer.getGroupSize();
    EXPECT_TRUE(partySize <= 6);
    EXPECT_TRUE(partySize >= 1);
}

TEST(CustomerGetterSetterTests, setNumberofMenuItems) {
    vector<string> names{"sam", "paula", "carl", "john", "pam", "josh", "Naveen", "Jason", "Paul", "Fiona"};
    Customer customer(names, 25);
    customer.setNumberofMenuItems(15);
    EXPECT_TRUE(customer.getNumberOfMenuItems() == 15);
}




#endif