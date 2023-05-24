#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "../header/Order.h"
#include "../header/OrderNode.h"
#include <iostream>
#include<vector>
using namespace std;

class Customer {
    public:
        Customer();
        Customer(vector<string>& names, int menuItemsNum);
        Customer(int numPeople, vector<string>& names, int menuItemsNum);
        void generateOrders(vector<OrderNode>& listOfOrders);     
        int payBill();                  // TO-DO
        double generateRating(bool good);
        const int getGroupSize();
        void setGroupSize(int value);
        void setRandomPartySize();
        void setRandomNames(vector<string>& names);
        void setNumberofMenuItems(int num);
    
    private:
        int groupSize;
        int numMenuItems;                 // Used internally
        vector<string> customerNames;     // list of random names for customers

        //Private helper methods
        OrderNode generateRandomOrder(string name);

};

/* Example usage of Customer and Order class

    Customer group1(4, customerNames, 10);
    Order group1order;

    group1.generateOrders(group1order.getOrdersList());
    group1order.viewAllOrders();

*/

#endif