#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <iostream>
using namespace std;

class MenuItem {
    public:
        MenuItem* next;
        int menuNumber;
        double foodPrice;

        MenuItem();
        MenuItem(int mNumber, string fType, string fItem, double fPrice);

        int getMenuNumber() const;
        string getFoodType() const;
        string getFoodItem() const;
        double getFoodPrice() const;
        void printMenuItem() const;

    private:
        string foodType;
        string foodItem;
};

#endif