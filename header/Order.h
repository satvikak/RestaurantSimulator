#ifndef ORDER_H
#define ORDER_H

#include "../header/Customer.h"
#include "../header/OrderNode.h"
#include <iostream>
#include <list>
#include<vector>
using namespace std;

class Order {
    public:
        void removeOrder();
        void removeAllOrders();
        void viewAllOrders();
        vector<OrderNode>& getOrdersList();
        void printOrders();

    private:
        vector<OrderNode> ordersList;
        int numMenuItems;
};

#endif