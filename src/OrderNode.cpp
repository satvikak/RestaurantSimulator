#include "../header/OrderNode.h"

#include <iostream>

using namespace std;

OrderNode::OrderNode() {
    itemNumber = 0;
    customerName = "";
}

void OrderNode::printOrder() {
    cout << this->getCustomerName() << " ordered menu item " << this->getItemNumber() << "." << endl;
}

int OrderNode::getItemNumber() const {
    return itemNumber;
}

void OrderNode::setItemNumber(int randNum) {
    itemNumber = randNum;
}

string OrderNode::getCustomerName() const {
    return customerName;
}

void OrderNode::setCustomerName(string randName) {
    customerName = randName;
}