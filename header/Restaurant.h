#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
using namespace std;

class Restaurant {
    public:
        Restaurant();
        const string& getRestaurantName() const;
        void setName(string restName);
        const double getBalance();
        void setBalance(double restBalance);
        const double getRating();
        void setRating(double restRating);
    
    private:
        string restaurantName;
        double restaurantBalance;
        double rating;
    
    protected:
        char floorPlan[][]; //char array?
        string menuList; //linked list
};

#endif