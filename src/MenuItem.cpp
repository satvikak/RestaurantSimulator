#include "../header/Manager.h"
#include "../header/MenuItem.h"

#include <iostream>

using namespace std;

//menu node class implementation
MenuItem::MenuItem() {
    menuNumber = 0;
    foodType = "";
    foodItem = "";
    foodPrice = 0.0;
    next = nullptr;
}

MenuItem::MenuItem(int mNumber, string fType, string fItem, double fPrice) {
    menuNumber = mNumber;
    foodItem = fItem;
    foodPrice = fPrice;
    next = nullptr;

    //store foodType in node as full word, instead of just letter
    if (fType == "a") {
        foodType = "appetizer";
    }
    else if (fType == "m") {
        foodType = "main course";
    }
    else if (fType == "d") {
        foodType = "dessert";
    }
}

int MenuItem::getMenuNumber() const {
    return menuNumber;
}

string MenuItem::getFoodType() const {
    return foodType;
}

string MenuItem::getFoodItem() const {
    return foodItem;
}

void MenuItem::setFoodPrice(double newFoodPrice) {
    foodPrice = newFoodPrice;
}

double MenuItem::getFoodPrice() const {
    return foodPrice;
}

//print a singular menu item
void MenuItem::printMenuItem() const {
    cout << "Menu Number: " << menuNumber << endl;
    cout << "Food Type:   " << foodType << endl;
    cout << "Food Item:   " << foodItem << endl;
    cout << "Food Price:  $" << foodPrice << endl;
}