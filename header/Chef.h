#ifndef CHEF_H
#define CHEF_H

#include "../header/Employee.h"

#include <iostream>
using namespace std;

class Chef : public Employee {
    public:
        Chef();
        ~Chef();
        string viewOrdersList();
        bool makeOrder();
        void removeOrder();
        void printCharacterDetails();
    
    private:

};

#endif