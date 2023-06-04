#ifndef CHEF_H
#define CHEF_H

#include "../header/Employee.h"

#include <iostream>

using namespace std;

class Chef : public Employee {
    public:
        Chef();
        int getMistakes();
        void MCGame(string type);
        void typingGame(string type);
        void printCharacterDetails();
    
    private:
        int numMistakes;
};

#endif