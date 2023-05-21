#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
    public:
        int groupSize;

        Customer();
        ~Customer();
        int generateOrders();
        int payBill();
        double generateRating();
    
    private:

};

#endif