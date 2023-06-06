#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <chrono>
#include "../header/Customer.h"

using namespace std;

class Table {
    public:
        Table();
        ~Table();
        void setCustomerGroup(Customer* group);
        const Customer* getCustomerGroup();
        const int getOrders(); //delete? repetitive with takeOrder() in Server.h
        const int getSeats() const;
        void setSeats(int freeSeats);
        const int getTableNum() const;
        void setTableNum(int tableNum);
        void adjustLeftoverSeats(int availableSeats);
        const bool getAvailability();
        const double getBill() const;
        void setBillAmount(int value);
        using time = decltype(chrono::steady_clock::now());
        void setEntryTime(time comeTime);
        auto getEntryTime() const;
        void setExitTime(time leaveTime);
        auto getExitTime() const;
        unsigned int getTotalTime() const;

    private:
        //string customerName;
        Customer* customerGroup;
        int numSeats;
        bool availableTable;
        double billAmount; 
        int tableNumber;
        time enterTime;
        time exitTime;
};

#endif