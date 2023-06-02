#ifndef ORDERNODE_H
#define ORDERNODE_H

#include <iostream>
#include<vector>
using namespace std;

struct OrderNode {
    int itemNumber;
    string customerName;

    const void printOrder() {
        cout << customerName << " ordered menu item " << itemNumber << "." << endl;
    }

    
};

#endif