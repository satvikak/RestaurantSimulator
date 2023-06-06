#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee {
    public:
        Employee();
        void setEmployeeName(string empName);
        const string& getEmployeeName() const;
        virtual void printCharacterDetails() = 0;
    
    private:
        string employeeName;

};

#endif