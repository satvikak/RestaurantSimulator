#ifndef MANAGER_TESTS_HPP
#define MANAGER_TESTS_HPP

#include "gtest/gtest.h"
#include "../header/Manager.h"
#include "../header/MenuItem.h"

TEST(ManagerConstructorTest, NoNodes) {
    Manager m = Manager();
    EXPECT_TRUE(m.isEmpty());
}

TEST(ManagerEmptyMenuTest, OneNodeFull) {
    Manager m = Manager();
    MenuItem* newNode = new MenuItem(1, "a", "salad", 4.50);
    m.menuAdd(newNode);
    EXPECT_FALSE(m.isEmpty());
    delete newNode;
}

TEST(ManagerEmptyMenuTest, TwoNodeEmpty) {
    Manager m = Manager();
    MenuItem* newNode = new MenuItem(1, "m", "pasta", 8.50);
    MenuItem* newNodeTwo = new MenuItem(2, "d", "cake", 2.00);
    m.menuAdd(newNode);
    m.menuAdd(newNodeTwo);
    m.clearFullMenu();
    EXPECT_TRUE(m.isEmpty());
}

TEST(ManagerPriceChangeTest, ChangeMenuPrice) {
    Manager m = Manager();
    MenuItem* newNode = new MenuItem(1, "m", "burrito", 11.50);
    m.menuAdd(newNode);
    m.changeMenuPrice(1, 6.50);
    EXPECT_DOUBLE_EQ(newNode->getFoodPrice(), 6.50);
    delete newNode;
}

TEST(ManagerMenuNumTest, LastMenuNumber) {
    Manager m = Manager();
    MenuItem* newNode = new MenuItem(1, "m", "pizza", 9.50);
    MenuItem* newNodeTwo = new MenuItem(2, "a", "bread", 1.50);
    MenuItem* newNodeThree = new MenuItem(3, "d", "ice cream", 3.00);
    m.menuAdd(newNode);
    m.menuAdd(newNodeTwo);
    m.menuAdd(newNodeThree);
    EXPECT_EQ(m.getLastMenuNumber(), 3);
    delete newNode;
    delete newNodeTwo;
    delete newNodeThree;
}

#endif