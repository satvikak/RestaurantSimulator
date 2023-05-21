#ifndef MANAGER_H
#define MANAGER_H

#include "../header/Employee.h"

#include <iostream>
using namespace std;

class MenuNode {
    public:
        MenuNode* next;
        int menuNumber;
        double foodPrice;

        MenuNode();
        MenuNode(int mNumber, string fType, string fItem, double fPrice);

        int getMenuNumber() const;
        string getFoodType() const;
        string getFoodItem() const;
        double getFoodPrice() const;
        void printMenuNode() const;

    private:
        string foodType;
        string foodItem;
};

class Manager : public Employee {
    public:
        Manager();
        ~Manager();
        void menuAdd(MenuNode* newNode);
        void changeMenuPrice(int itemNumber, double newPrice);
        void viewFullMenu();
        bool isEmpty();
        void printCharacterDetails();
    
    private:
        MenuNode* head;
        MenuNode* tail;
};

#endif