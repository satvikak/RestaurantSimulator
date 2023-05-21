#ifndef TABLE_H
#define TABLE_H

#include <iostream>
using namespace std;

class Table {
    public:
        Table();
        ~Table();
        void setCustomerName(string custName);
        const string& getCustomerName() const;
        const int getOrders(); //delete? repetitive with takeOrder() in Server.h
        const int getSeats();
        const bool getAvailability();
        const double getBill();

    private:
        string customerName;
        int numSeats;
        bool availableTable;
        double billAmount;    
};

#endif