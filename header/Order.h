#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <list>
using namespace std;

class Order {
    public:
        Order();
        ~Order();
        void addOrder(int orderNum);
        void removeOrder();
        void removeAllOrders();
        void viewAllOrders();

    private:
        list<int> ordersList;
        //list<int>& ordersList; //compiler error when trying to initialize pass-by-ref list
};

#endif