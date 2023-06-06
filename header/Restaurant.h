#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "../header/Table.h"
#include "../header/Manager.h"
#include "../header/Server.h"
#include "../header/Chef.h"
#include "../header/Employee.h"

#include <iostream>
#include <vector>

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
        void displayFloorPlan(int userNum);
        //void createTablesArray(int userNum);
        void simulateRestaurant();
        const double getRating();
        string validateStringInput(string userInput, int num);
        int validateIntInput(int userInput, int num, int upperBound);
        double validateDoubleInput(double userInput, int num);
    
    private:
        string restaurantName;
        //vector<string> names{"Angelica", "Ben", "Angel", "Ryan", "Sophia", "Ruby", "Carly", "Lexi", "Joshua", "Ken", "Raquel", "Beth", "Rio", "Fiona", "Richard"};
        double restaurantBalance;
        double rating;
        Manager m;
        Server s;
        Chef c;
    
    protected:
        string menuList; //linked list
};

#endif