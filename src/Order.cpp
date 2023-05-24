#include "../header/Order.h"
#include "../header/Customer.h"

#include <iostream>
#include <list>
using namespace std;

//remove a single order from the front of the list
//can be used by chef or server when done cooking or serving meals, respectively
void Order::removeOrder() {
    if (ordersList.size() == 0) {
        cout << "List of orders is empty" << endl; //throw?
        return;
    }
    ordersList.erase(ordersList.begin());
}

//remove all orders from the list when the game resets
void Order::removeAllOrders() {
    while (ordersList.size() != 0) {
        removeOrder();
    }
}

vector<OrderNode>& Order::getOrdersList() {
    return ordersList;
}

void Order::viewAllOrders() {
    cout << "Current Orders: " << endl;
    printOrders();
}

void Order::printOrders() {
    for (int i = 0; i < ordersList.size(); i++) {
        ordersList.at(i).printOrder();
    }
}
