#include "../header/Restaurant.h"

#include <iostream>
using namespace std;

Restaurant::Restaurant() {
    restaurantName = "";
    restaurantBalance = 100.0;
    rating = 5.0;
}

Restaurant::~Restaurant() {
    
}

const string& Restaurant::getRestaurantName() const {
    return restaurantName;
}

void Restaurant::setRestaurantName(string restName) {
    restaurantName = restName;
}

const double Restaurant::getBalance() {
    return restaurantBalance;
}

void Restaurant::setBalance(double restBalance) {
    restaurantBalance = restBalance;
}

const double Restaurant::getRating() {
    return rating;
}

void Restaurant::setRating(double restRating) {
    rating = restRating;
}