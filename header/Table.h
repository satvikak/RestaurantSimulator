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
        Customer* getCustomerGroup() const;
        const int getSeats() const;
        void setSeats(int freeSeats);
        const int getTableNum() const;
        void setTableNum(int tableNum);
        void adjustLeftoverSeats(int takenSeats);
        const bool getAvailability();
        const double getBill() const;
        void setBillAmount(double value);
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