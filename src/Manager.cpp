#include "../header/Manager.h"
#include "../header/Employee.h"

#include <iostream>
using namespace std;

Manager::Manager() {

}

void Manager::menuAdd() {

}

void Manager::menuDelete() {

}

void Manager::changeMenuPrice() {

}

void Manager::printCharacterDetails() {
    string name;
    cout << "Enter your manager name: ";
    getline(cin, name);
    Employee::setEmployeeName(name);
    cout << endl << "You are officially Manager " << name << "!" << endl;
}