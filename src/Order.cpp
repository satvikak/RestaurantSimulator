#include "../header/Order.h"

#include <iostream>
#include <list>
using namespace std;

Order::Order() {

}

Order::~Order() {

}

//add order numbers from customer to ordersList
void Order::addOrder(int orderNum) {
    ordersList.push_back(orderNum);
}

//remove a single order from the front of the list
//can be used by chef or server when done cooking or serving meals, respectively
void Order::removeOrder() {
    if (ordersList.size() == 0) {
        cout << "List of orders is empty" << endl; //throw?
        return;
    }

    ordersList.pop_front(); //delete from front since it's a queue
}

//remove all orders from the list when the game resets
void Order::removeAllOrders() {
    while (ordersList.size() != 0) {
        removeOrder();
    }
}

void Order::viewAllOrders() {
    cout << "Current Orders: ";

    for (int i : ordersList) {
        cout << i << " ";
    }

    cout << endl;
}