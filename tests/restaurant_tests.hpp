#ifndef RESTAURANT_TESTS_HPP
#define RESTAURANT_TESTS_HPP

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../header/Restaurant.h"

using ::testing::InSequence;

// Getters and setters
TEST(RestaurantGetters, getName) {
    Restaurant rest;
    string name = rest.getRestaurantName();
    EXPECT_EQ(name, "");
}

TEST(RestaurantSetters, setName) {
    Restaurant rest;
    string name = "...";
    rest.setRestaurantName(name);
    EXPECT_EQ(rest.getRestaurantName(), "...");
}

TEST(RestaurantGetters, getBalance) {
    Restaurant rest;
    double balance = rest.getBalance();
    EXPECT_DOUBLE_EQ(balance, 100.0);
}

TEST(RestaurantSetters, setBalance) {
    Restaurant rest;
    double balance = 50.0;
    rest.setBalance(balance);
    EXPECT_DOUBLE_EQ(rest.getBalance(), 50.0);
}

TEST(RestaurantGetters, getRating) {
    Restaurant rest;
    double rate = rest.getRating();
    EXPECT_DOUBLE_EQ(rate, 5.0);
}

TEST(RestaurantSetters, setRating) {
    Restaurant rest;
    double rate = 2.5;
    rest.setRating(rate);
    EXPECT_DOUBLE_EQ(rest.getRating(), 2.5);
}

// Input Validation
TEST(RestaurantStringValid, foodType) {
    Restaurant rest;
    string appetizer = "a";
    string main = "m";
    string dessert = "d";
    EXPECT_EQ(rest.validateStringInput(appetizer, 1), "a");
    EXPECT_EQ(rest.validateStringInput(main, 1), "m");
    EXPECT_EQ(rest.validateStringInput(dessert, 1), "d");
}

TEST(RestaurantStringValid, yesNo) {
    Restaurant rest;
    string yes = "y";
    string no = "n";
    EXPECT_EQ(rest.validateStringInput(yes, 2), "y");
    EXPECT_EQ(rest.validateStringInput(no, 2), "n");
}

TEST(RestaurantStringValid, yes) {
    Restaurant rest;
    string yes = "y";
    EXPECT_EQ(rest.validateStringInput(yes, 3), "y");
}

TEST(RestaurantStringValid, contQuit) {
    Restaurant rest;
    string cont = "c";
    string quit = "q";
    EXPECT_EQ(rest.validateStringInput(cont, 4), "c");
    EXPECT_EQ(rest.validateStringInput(quit, 4), "q");
}

TEST(RestaurantIntValid, lowerBound) {
    Restaurant rest;
    int input = 1;
    EXPECT_EQ(rest.validateIntInput(input, 1, 5), 1);
}

TEST(RestaurantIntValid, upperBound) {
    Restaurant rest;
    int input = 5;
    EXPECT_EQ(rest.validateIntInput(input, 1, 5), 5);
}

TEST(RestaurantDoubleValid, lowerBound) {
    Restaurant rest;
    double input = 0.01;
    EXPECT_EQ(rest.validateDoubleInput(input, 1), 0.01);
}

TEST(RestaurantDoubleValid, upperBound) {
    Restaurant rest;
    double input = 1000.0;
    EXPECT_EQ(rest.validateDoubleInput(input, 1), 1000.0);
}

#endif
