#include "../header/Manager.h"
#include "../header/Employee.h"

#include <iostream>
using namespace std;

//menu node class implementation
MenuNode::MenuNode() {
    menuNumber = 0;
    foodType = "";
    foodItem = "";
    foodPrice = 0.0;
    next = nullptr;
}

MenuNode::MenuNode(int mNumber, string fType, string fItem, double fPrice) {
    menuNumber = mNumber;
    foodItem = fItem;
    foodPrice = fPrice;

    //store foodType in node as full word, instead of just letter
    if (fType == "a") {
        foodType = "appetizer";
    }
    else if (fType == "m") {
        foodType = "main course";
    }
    else if (fType == "d") {
        foodType = "dessert";
    }
}

int MenuNode::getMenuNumber() const {
    return menuNumber;
}

string MenuNode::getFoodType() const {
    return foodType;
}

string MenuNode::getFoodItem() const {
    return foodItem;
}

double MenuNode::getFoodPrice() const {
    return foodPrice;
}

//print a singular menu item
void MenuNode::printMenuNode() const {
    cout << "Menu Number: " << menuNumber << endl;
    cout << "Food Type:   " << foodType << endl;
    cout << "Food Item:   " << foodItem << endl;
    cout << "Food Price:  $" << foodPrice << endl;
}

//manager class implementation
Manager::Manager() {
    head = nullptr;
    tail = nullptr;
}

Manager::~Manager() {
    while (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            MenuNode* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
    }
}

//add an item to the menu
void Manager::menuAdd(MenuNode* newNode) {
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

//change the price of an item on the menu with the newly requested price (need to test)
void Manager::changeMenuPrice(int itemNumber, double newPrice) {
    MenuNode* curr = head;

    if (isEmpty()) {
        cout << "Menu is empty" << endl; //throw?
        return;
    }

    while (curr != nullptr) {
        if (curr->menuNumber == itemNumber) {
            curr->foodPrice = newPrice;
        }

        curr = curr->next;
    }

    delete curr;
    curr = nullptr;
}

//print the full menu
void Manager::viewFullMenu() {
    MenuNode* curr = head;

    if (isEmpty()) {
        cout << "Menu is empty" << endl; //throw?
        return;
    }

    cout << "--RESTAURANT MENU--" << endl;

    while (curr != nullptr) {
        curr->printMenuNode();
        cout << endl;

        curr = curr->next;
    }

    delete curr;
    curr = nullptr;
}

//check if menu is empty
bool Manager::isEmpty() {
    return ((head == nullptr) && (tail == nullptr));
}

//print manager name prompt
void Manager::printCharacterDetails() {
    string name;
    cout << "Enter your manager name: ";
    getline(cin, name);
    Employee::setEmployeeName(name);
    cout << endl << "You are officially Manager " << name << "!" << endl;
}