#include "../header/Table.h"

#include <iostream>
#include <chrono>

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

const int Table::getSeats() const {
    return numSeats;
}

void Table::setSeats(int freeSeats) {
    numSeats = freeSeats;
}

const int Table::getTableNum() const {
    return tableNumber;
}

void Table::setTableNum(int tableNum) {
    tableNumber = tableNum;
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

const double Table::getBill() const {
    return billAmount;
}

void Table::setBillAmount(int value) {
    billAmount = value;
}

void Table::setEntryTime(time comeTime) {
    enterTime = comeTime;
}

auto Table::getEntryTime() const {
    return enterTime;
}

void Table::setExitTime(time leaveTime) {
    exitTime = leaveTime;
}

auto Table::getExitTime() const {
    return exitTime;
}

unsigned int Table::getTotalTime() const {
    return chrono::duration_cast<chrono::seconds>(getExitTime()-getEntryTime()).count();
}