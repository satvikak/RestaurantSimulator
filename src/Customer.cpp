#include "../header/Customer.h"
#include "../header/OrderNode.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Customer::Customer() {
    
}

Customer::Customer(vector<string>& names, int menuItemsNum) {
    setRandomPartySize();
    setRandomNames(names);
    numMenuItems = menuItemsNum;

}

Customer::Customer(int numPeople, vector<string>& names, int menuItemsNum) {
    groupSize = numPeople;
    numMenuItems = menuItemsNum;
    // copy names into customerNames
    for (int i = 0; i < names.size(); i++) {
        customerNames.push_back(names.at(i));
    }
}

OrderNode Customer::generateRandomOrder(string name) {
    int randomOrderNumber = rand() % numMenuItems + 1;      // random number from 1 to largest menuItem number
    OrderNode newOrder;
    newOrder.setCustomerName(name);
    newOrder.setItemNumber(randomOrderNumber);
    return newOrder;
    
}
 
void Customer::generateOrders(vector<OrderNode>& listOfOrders) {
    for (int i = 0; i < groupSize; i++) {
        string currentName = customerNames.at(i);
        OrderNode nextOrder = generateRandomOrder(currentName);
        listOfOrders.push_back(nextOrder);
    }
}

const int Customer::getGroupSize() {
    return groupSize;
}

void Customer::setGroupSize(int value) {
    groupSize = value;
}

void Customer::setRandomPartySize() {
    int partySize = rand() % 6 + 1;        // random int from 1 - 6
    groupSize = partySize;
}

void Customer::setRandomNames(vector<string>& names) {
    vector<int> chosenValues;
    for (int i = 0; i < groupSize; i++) {
        int nameIndex = 0;
        bool duplicate = false;
        do {
            duplicate = false;
            nameIndex = rand() % names.size();
            for (int i = 0; i < chosenValues.size(); i++) {
                if (nameIndex == chosenValues.at(i)) {
                    duplicate = true;
                    break;
                }
            }
        } while (duplicate);
        customerNames.push_back(names.at(nameIndex));
        chosenValues.push_back(nameIndex);
    }
}

void Customer::setNumberofMenuItems(int num) {
    numMenuItems = num;
}

const int Customer::getNumberOfMenuItems() {
    return numMenuItems;
}
