#ifndef MANAGER_H
#define MANAGER_H

#include "../header/Employee.h"

#include <iostream>
using namespace std;

class Manager : public Employee {
    public:
        Manager();
        void menuAdd();
        void menuDelete();
        void changeMenuPrice();
        void printCharacterDetails();
    
    private:

};

#endif