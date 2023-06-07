#include "../header/Chef.h"
#include "../header/Employee.h"

#include <iostream>
using namespace std;

Chef::Chef() {
    numMistakes = 0;
}

int Chef::getMistakes() {
    return numMistakes;
}

void Chef::MCGame(string type) {
    string answer;
    string entry;
    int numTries = 1;

    cout << "Here are your tasks! Type them out (by letter) in the correct order." << endl;
    cout << "Example: \"cbda\"" << endl << endl;

    if (type == "appetizer") {
        cout << "For the appetizer..." << endl;
        cout << "a) Turn on the stove" << endl;
        cout << "b) Gather ingredients" << endl;
        cout << "c) Get small serving plates" << endl;
        cout << "d) Wash your hands" << endl;

        answer = "dbac";
    }
    else if (type == "main course") {
        cout << "For the main course..." << endl;
        cout << "a) Chop up the ingredients" << endl;
        cout << "b) Get big serving plates" << endl;
        cout << "c) Get out pans" << endl;
        cout << "d) Take out spices" << endl;
        cout << "e) Wash vegetables" << endl;

        answer = "edcab";
    }
    else if (type == "dessert") {
        cout << "For the dessert..." << endl;
        cout << "a) Preheat the oven" << endl;
        cout << "b) Get small serving plate" << endl;
        cout << "c) Get the sugar" << endl;
        cout << "d) Take out mixing bowls" << endl;

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
        cout << "Answer: ";
        cin >> entry;
        cout << endl;

        if (answer == entry) {
            cout << "That's Correct! ✅" << endl;
            break;
        }
        else if (numTries == 2) {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
            break;
        }
        else if (numTries == 1) {
            cout << "That's Incorrect. Try Again. 👎" << endl;
            numTries++;
        }
    }
}

void Chef::typingGame(string type) {
    cout << endl << "Let's get to work! Chop chop! ⏲️" << endl;

    if (type == "appetizer") {
        string appEntry;

        cout << "Enter 'Chop' to chop the ingredients: ";
        cin >> appEntry;
        cout << endl;

        if (appEntry == "Chop" || appEntry == "chop") {
            cout << "Chopping...🔪" << endl;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
        }
        
        cout << "Enter 'Cook' to cook the appetizer: ";
        cin >> appEntry;
        cout << endl;

        if (appEntry == "Cook" || appEntry == "cook") {
            cout << "Cooking..." << endl << endl;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
        }
    }
    else if (type == "main course") {
        string mainEntry;

        cout << "Enter 'Mix' to mix the ingredients: ";
        cin >> mainEntry;
        cout << endl;

        if (mainEntry == "Mix" || mainEntry == "mix") {
            cout << "Mixing...🥣" << endl;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
        }
        
        cout << "Enter 'Sizzle' to cook the main course: ";
        cin >> mainEntry;
        cout << endl;

        if (mainEntry == "Sizzle" || mainEntry == "sizzle") {
            cout << "Sizzling...🔥" << endl << endl;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
        }

    }
    else if (type == "dessert") {
        string dessertEntry;

        cout << "Enter 'Bake' to bake the dessert: ";
        cin >> dessertEntry;
        cout << endl;

        if (dessertEntry == "Bake" || dessertEntry == "bake") {
            cout << "Baking..." << endl;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
        }
        
        cout << "Enter 'Decorate' to decorate the dessert: ";
        cin >> dessertEntry;
        cout << endl;

        if (dessertEntry == "Decorate" || dessertEntry == "decorate") {
            cout << "Decorating..." << endl << endl;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            numMistakes++;
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