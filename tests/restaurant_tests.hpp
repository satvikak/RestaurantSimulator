#ifndef RESTAURANT_TESTS_HPP
#define RESTAURANT_TESTS_HPP

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../header/Restaurant.h"

using ::testing::InSequence;

// Getters and setters
TEST(RestaurantTests, getName) {
    Restaurant rest;
    string name = rest.getRestaurantName();
    EXPECT_EQ(name, "");
}

TEST(RestaurantTests, setName) {
    Restaurant rest;
    string name = "...";
    rest.setRestaurantName(name);
    EXPECT_EQ(rest.getRestaurantName(), "...");
}

TEST(RestaurantTests, getBalance) {
    Restaurant rest;
    double balance = rest.getBalance();
    EXPECT_DOUBLE_EQ(balance, 100.0);
}

TEST(RestaurantTests, setBalance) {
    Restaurant rest;
    double balance = 50.0;
    rest.setBalance(balance);
    EXPECT_DOUBLE_EQ(rest.getBalance(), 50.0);
}

TEST(RestaurantTests, getRating) {
    Restaurant rest;
    double rate = rest.getRating();
    EXPECT_DOUBLE_EQ(rate, 5.0);
}

TEST(RestaurantTests, setRating) {
    Restaurant rest;
    double rate = 2.5;
    rest.setRating(rate);
    EXPECT_DOUBLE_EQ(rest.getRating(), 2.5);
}

/*
// Going to be way too complex (also changes often when we add steps)
class MockRestaurant : public Restaurant{
    public: 
    MOCK_METHOD(void, setRestaurantName, (string restName));
    MOCK_METHOD(string, getRestaurantName, ());
    MOCK_METHOD(double, getBalance, ());
    MOCK_METHOD(double, getRating, ());
    MOCK_METHOD(void, createFloorPlan, ());
};

TEST(RestaurantTests, simulateRestaurant) {
    MockRestaurant rest;
    string restaurantName = "";

    InSequence seq;
    EXPECT_CALL(rest, setRestaurantName(restaurantName));
    EXPECT_CALL(rest, getRating());
    EXPECT_CALL(rest, getBalance());
    EXPECT_CALL(rest, createFloorPlan());
    EXPECT_CALL(rest, getRestaurantName());
    EXPECT_CALL(rest, getRating());
    EXPECT_CALL(rest, getRestaurantName());
    EXPECT_CALL(rest, getBalance());

    rest.simulateRestaurant();
}
*/

#endif
