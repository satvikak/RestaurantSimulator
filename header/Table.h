#ifndef TABLE_H
#define TABLE_H

#include <iostream>
using namespace std;

class Table {
    public:
        Table();
        void setCustomerName(string custName);
        const string& getCustomerName() const;
        const int getOrders(); //list<int>& ordersList
        const int getSeats();
        const bool getAvailability();
        const double getBill();

    private:
        string customerName;
        int ordersList; //list<int>& ordersList
        int numSeats;
        bool availableTable;
        double billAmount;

};

#endif