#ifndef TABLE_H
#define TABLE_H

#include "../header/Customer.h"

#include <iostream>

using namespace std;

class Table {
    public:
        Table();
        ~Table();
        void setCustomerGroup(Customer* group);
        const Customer* getCustomerGroup();
        const int getOrders(); //delete? repetitive with takeOrder() in Server.h
        const int getSeats();
        void adjustLeftoverSeats(int availableSeats);
        const bool getAvailability();
        const double getBill();
        void setBillAmount(int value);

    private:
        //string customerName;
        Customer* customerGroup;
        int numSeats;
        bool availableTable;
        double billAmount;    
};

#endif