#include "../header/Employee.h"

#include <iostream>

using namespace std;

Employee::Employee() {
    employeeName = "";
}

Employee::~Employee() {
    
}

void Employee::setEmployeeName(string empName) {
    employeeName = empName;
}

const string& Employee::getEmployeeName() const {
    return employeeName;
}