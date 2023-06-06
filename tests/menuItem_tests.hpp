#ifndef MENU_ITEM_TESTS_HPP
#define MENU_ITEM_TESTS_HPP

#include "gtest/gtest.h"

#include "../header/MenuItem.h"

// Getters and setters
TEST(MenuItemGetters, getMenuNumber) {
    MenuItem dish;
    int number = dish.getMenuNumber();
    EXPECT_EQ(number, 0);
}

TEST(MenuItemGetters, getFoodType) {
    MenuItem dish;
    string type = dish.getFoodType();
    EXPECT_EQ(type, "");
}

TEST(MenuItemGetters, getFoodItem) {
    MenuItem dish;
    string item = dish.getFoodItem();
    EXPECT_EQ(item, "");
}

TEST(MenuItemGetters, getFoodPrice) {
    MenuItem dish;
    double price = dish.getFoodPrice();
    EXPECT_DOUBLE_EQ(price, 0.0);
}

TEST(MenuItemSetters, setFoodPrice) {
    MenuItem dish;
    double price = 19.99;
    dish.setFoodPrice(price);
    EXPECT_EQ(dish.getFoodPrice(), 19.99);
}

// Parameterized Constructor
TEST(MenuItemConstructor, paramConstructor) {
    MenuItem dish(1, "a", "...", 9.99);
    EXPECT_EQ(dish.getMenuNumber(), 1);
    EXPECT_EQ(dish.getFoodType(), "appetizer");
    EXPECT_EQ(dish.getFoodItem(), "...");
    EXPECT_DOUBLE_EQ(dish.getFoodPrice(), 9.99);
}

#endif