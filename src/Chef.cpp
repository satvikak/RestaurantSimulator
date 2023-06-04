#include "../header/Chef.h"
#include "../header/Employee.h"
#include "../header/Order.h" //include Order.h to work with various Order functions

#include <iostream>
using namespace std;

Chef::Chef() {

}

void Chef::MCGame(string type) {
    cout << "Here are the tasks you need to complete. Type them out in the correct order." << endl;
    string entry;
    string answer;
    int numTries = 1;

    if (type == "appetizer") {

    }
    else if (type == "main course") {

    }
    else if (type == "dessert") {
        cout << "a) Preheat the oven" << endl;
        cout << "b) Get small serving plate" << endl;
        cout << "c) Get the sugar" << endl;
        cout << "d) Get out mixing bowls" << endl;
        answer = "adcb";
    }
    else if (type == "clean") {
        cout << "a) Wash dishes" << endl;
        cout << "b) Clean your station" << endl;
        cout << "c) Mop the floor" << endl;
        cout << "d) Prep for the next day" << endl;
        answer = "bacd";
    }

    while (numTries <= 2) {
        cout << "Answer: " << endl;
        cin >> entry;
        if (answer == entry) {
            cout << "That's Correct!" << endl;
            break;
        }
        else if (numTries == 2) {
            cout << "That's Incorrect. Balance Decreased." << endl;
            // Multiply restaurant balance by 0.9
            break;
        }
        else if (numTries == 1) {
            cout << "That's Incorrect. Try Again." << endl;
            numTries++;
        }
    }
}

void Chef::typingGame(string type) {
    cout << endl << "Let's get to work!" << endl;
    if (type == "appetizer") {

    }
    else if (type == "main course") {

    }
    else if (type == "dessert") {
        string dessertEntry;
        cout << "Enter \"Bake\" to bake the dessert: ";
        cin >> dessertEntry;
        if (dessertEntry == "Bake" || dessertEntry == "bake") {
            cout << "Baking..." << endl;
        }
        else {
            cout << "That's Incorrect. Balance Decreased." << endl;
        }
        
        cout << "Enter \"Decorate\" to decorate the dessert: ";
        cin >> dessertEntry;
        if (dessertEntry == "Decorate" || dessertEntry == "decorate") {
            cout << "Decorating..." << endl;
        }
        else {
            cout << "That's Incorrect. Balance Decreased." << endl;
        }
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