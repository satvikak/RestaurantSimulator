#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
using namespace std;

class Restaurant {
    public:
        Restaurant();
        ~Restaurant();
        void setRestaurantName(string restName);
        const string& getRestaurantName() const;
        void setBalance(double restBalance);
        const double getBalance();
        void setRating(double restRating);
        const double getRating();
    
    private:
        string restaurantName;
        double restaurantBalance;
        double rating;
    
    protected:
        //char floorPlan[][]; //char array?
};

#endif