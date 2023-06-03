#include "../header/Table.h"

#include <iostream>
using namespace std;

Table::Table() {
    //customerName = "";
    numSeats = 6;
    availableTable = true;
    billAmount = 0.0;
    customerGroup = nullptr;
}

Table::~Table() {
    
}

void Table::setCustomerGroup(Customer* group) {
    customerGroup = group;
}

const Customer* Table::getCustomerGroup() {
    return customerGroup;
}

const int Table::getOrders() {
    return 0;
}

const int Table::getSeats() {
    return numSeats;
}

void Table::adjustLeftoverSeats(int availableSeats) {
    numSeats = numSeats-availableSeats;
}

const bool Table::getAvailability() {
    if(this->getSeats()<6) {
        availableTable = false;
    }
    else {
        availableTable = true;
    }
    return availableTable;
}

const double Table::getBill() {
    return billAmount;
}

void Table::setBillAmount(int value) {
    billAmount = value;
}