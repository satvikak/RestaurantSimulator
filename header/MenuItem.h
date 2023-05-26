#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
using namespace std;

class MenuItem {
    public:
        MenuItem* next;
        MenuItem();
        MenuItem(int mNumber, string fType, string fItem, double fPrice);

        int getMenuNumber() const;
        string getFoodType() const;
        string getFoodItem() const;
        void setFoodPrice(double newFoodPrice);
        double getFoodPrice() const;
        void printMenuItem() const;

    private:
        int menuNumber;
        string foodType;
        string foodItem;
        double foodPrice;
};

#endif