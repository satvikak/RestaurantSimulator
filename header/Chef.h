#ifndef CHEF_H
#define CHEF_H

#include <iostream>
using namespace std;

class Chef {
    public:
        Chef();
        ~Chef();
        string viewOrdersList();
        bool makeOrder();
        void removeOrder(); 
    
    private:

};

#endif