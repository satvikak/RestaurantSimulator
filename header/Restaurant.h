#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>

#include "../header/Table.h"
#include "../header/Manager.h"
#include "../header/Server.h"
#include "../header/Chef.h"

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
        void createFloorPlan();
        void simulateRestaurant();
        const double getRating();
    
    private:
        string restaurantName;
        vector<string> names{"Angelica", "Ben", "Angel", "Ryan", "Sophia", "Ruby", "Carly", "Lexi", "Joshua", "Ken", "Raquel", "Beth", "Rio", "Fiona", "Richard"};
        double restaurantBalance;
        double rating;
        int numTables;
        Manager m;
        Server s;
        Chef c;
    
    protected:
        string menuList; //linked list
        Table **myTables;
};

#endif