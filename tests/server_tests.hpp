#ifndef SERVER_TESTS_HPP
#define SERVER_TESTS_HPP

#include "gtest/gtest.h"

#include "../header/Server.h"
#include "../header/Table.h"
#include "../header/OrderNode.h"

TEST(ServerConstructorTests, noParameters) {
    Server myServer = Server();
    EXPECT_EQ(myServer.getChosenTable(), nullptr);
    EXPECT_EQ(myServer.getEmployeeName(), "");
    EXPECT_EQ(myServer.getMistakes(), 0);
}

TEST(ServerGetterTests, getChosenTable) {
    Server myServer = Server();
    Table* myTable = myServer.getChosenTable();
    EXPECT_EQ(myTable, nullptr);
}

TEST(ServerGetterTests, getMyTables) {
    Server myServer = Server();
    Table** returnTables = myServer.getMyTables();
    EXPECT_EQ(returnTables, nullptr);
}

TEST(ServerGetterTests, getOrder) {
    vector<OrderNode> myOrders;
    OrderNode orderOne = OrderNode();
    myOrders.push_back(orderOne);
    Server myServer = Server();
    myServer.setOrder(myOrders);
    int returnVectorSize = (myServer.getOrder()).size();
    EXPECT_EQ(returnVectorSize, 1);
}

TEST(ServerGetterTests, getMistakes) {
    Server myServer = Server();
    myServer.addMistakes(5);
    int resultMistakes = myServer.getMistakes();
    EXPECT_EQ(resultMistakes, 5);
}

TEST(ServerSetterTests, setChosenTable) {
    Server myServer = Server();
    Table* myTable = new Table();
    myServer.setChosenTable(myTable);
    EXPECT_EQ(myServer.getChosenTable(), myTable);
    delete myTable;
}

TEST(ServerSetterTests, setOrder) {
    vector<OrderNode> myOrders;
    OrderNode orderOne = OrderNode();
    OrderNode orderTwo = OrderNode();
    myOrders.push_back(orderOne);
    myOrders.push_back(orderTwo);
    Server myServer = Server();
    myServer.setOrder(myOrders);
    EXPECT_EQ((myServer.getOrder()).size(), myOrders.size());
}

TEST(ServerSetterTests, setMistakes) {
    Server myServer = Server();
    myServer.addMistakes(4);
    EXPECT_EQ(myServer.getMistakes(), 4);
}

TEST(ServerRemoveOrdersTests, emptyOrder) {
    vector<OrderNode> myOrders;
    Server myServer = Server();
    int previousSize = myOrders.size();
    myServer.setOrder(myOrders);
    myServer.removeOrders();
    EXPECT_EQ((myServer.getOrder().size()), previousSize);
}

TEST(ServerRemoveOrdersTests, semiFullOrder) {
    vector<OrderNode> myOrders;
    OrderNode orderOne = OrderNode();
    OrderNode orderTwo = OrderNode();
    myOrders.push_back(orderOne);
    myOrders.push_back(orderTwo);
    Server myServer = Server();
    myServer.setOrder(myOrders);
    myServer.removeOrders();
    EXPECT_EQ((myServer.getOrder().size()), 0);
}

TEST(ServerBillTableTests, intBill) {
    Server myServer = Server();
    Table* myTable = new Table();
    myServer.setChosenTable(myTable);
    myServer.billTable(51.00);
    EXPECT_DOUBLE_EQ(myTable->getBill(), 51.00);
    delete myTable;
}

TEST(ServerBillTableTests, doubleBill) {
    Server myServer = Server();
    Table* myTable = new Table();
    myServer.setChosenTable(myTable);
    myServer.billTable(6.30);
    EXPECT_DOUBLE_EQ(myTable->getBill(), 6.30);
    delete myTable;
}

TEST(ServerOpenTablesTest, openTables) {
    Server myServer = Server();
    myServer.openUpTables(5);
    EXPECT_NE(myServer.getMyTables(), nullptr);
}

#endif