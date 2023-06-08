#ifndef ORDER_NODE_TESTS_HPP
#define ORDER_NODE_TESTS_HPP

#include "gtest/gtest.h"

#include "../header/OrderNode.h"

TEST(OrderNodeConstructorTests, noParameters) {
    OrderNode myOrder = OrderNode();
    EXPECT_EQ(myOrder.getItemNumber(), 0);
    EXPECT_EQ(myOrder.getCustomerName(), "");
}

TEST(OrderNodeGetterTests, getItemNumber) {
    OrderNode myOrder = OrderNode();
    int resultNumber = myOrder.getItemNumber();
    EXPECT_EQ(resultNumber, 0);
}

TEST(OrderNodeGetterTests, getCustomerName) {
    OrderNode myOrder = OrderNode();
    string resultName = myOrder.getCustomerName();
    EXPECT_EQ(resultName, "");
}

TEST(OrderNodeSetterTests, setItemNumber) {
    OrderNode myOrder = OrderNode();
    myOrder.setItemNumber(6);
    EXPECT_EQ(myOrder.getItemNumber(), 6);
}

TEST(OrderNodeSetterTests, setCustomerName) {
    OrderNode myOrder = OrderNode();
    myOrder.setCustomerName("Joel");
    EXPECT_EQ(myOrder.getCustomerName(), "Joel");
}

#endif