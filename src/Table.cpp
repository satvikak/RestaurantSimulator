#include "../header/Table.h"

#include <iostream>
using namespace std;

Table::Table() {
    customerName = "";
    numSeats = 6;
    availableTable = true;
    billAmount = 0.0;
}

void Table::setCustomerName(string custName) {
    return;
}

const string& Table::getCustomerName() const {
    return customerName;
}

const int Table::getOrders() {
    return 0;
}

const int Table::getSeats() {
    return numSeats;
}

const bool Table::getAvailability() {
    return availableTable;
}

const double Table::getBill() {
    return billAmount;
}