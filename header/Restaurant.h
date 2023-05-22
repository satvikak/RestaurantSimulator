#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>

#include "../header/Table.h"

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
        void createFloorPlan();
        void simulateRestaurant();

    private:
        string restaurantName;
        double restaurantBalance;
        double rating;
        int numTables;
    
    protected:
        string menuList; //linked list
        Table **myTables;
};

#endif