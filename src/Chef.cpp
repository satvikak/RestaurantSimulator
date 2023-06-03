#include "../header/Chef.h"
#include "../header/Employee.h"
#include "../header/Order.h" //include Order.h to work with various Order functions

#include <iostream>
using namespace std;

Chef::Chef() {

}

void Chef::MCGame(string type) {
    cout << "Here are the tasks you need to complete. Type them out in the correct order." << endl;
    if (type == "appetizer") {

    }
    else if (type == "main course") {

    }
    else if (type == "dessert") {

    }
    else if (type == "clean") {
        
    }
}

void Chef::typingGame(string type) {
    if (type == "appetizer") {

    }
    else if (type == "main course") {

    }
    else if (type == "dessert") {

    }
}

void Chef::printCharacterDetails() {
    string name;
    cout << "Enter your chef name: ";
    cin.ignore();
    getline(cin, name);
    Employee::setEmployeeName(name);
    cout << endl << "You are officially Chef " << name << "! 🍴" << endl;
}