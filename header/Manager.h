#ifndef MANAGER_H
#define MANAGER_H

#include "../header/Employee.h"
#include "../header/MenuItem.h"

#include <iostream>
using namespace std;

class Manager : public Employee {
    public:        
        Manager();
        ~Manager();
        void menuAdd(MenuItem* newNode);
        void changeMenuPrice(int itemNumber, double newPrice);
        int getLastMenuNumber();
        void viewFullMenu();
        void clearFullMenu();
        bool isEmpty();
        void printCharacterDetails();
        double getPriceOfChosenMenuItem(int menuNumber);
    
    private:
        MenuItem* head;
        MenuItem* tail;
};

#endif