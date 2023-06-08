#ifndef ORDER_NODE_H
#define ORDER_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class OrderNode {
    public:
        OrderNode();
        void printOrder();
        int getItemNumber() const;
        void setItemNumber(int randNum);
        string getCustomerName() const;
        void setCustomerName(string randName);

    private:
        int itemNumber;
        string customerName;
};

#endif