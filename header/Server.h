#ifndef SERVER_H
#define SERVER_H

#include "../header/Employee.h"

#include <iostream>
using namespace std;

class Server : public Employee  {
    public:
        Server();
        ~Server();
        void seatCustomer();
        void displayMenu();
        void takeOrder();
        void serveCustomer();
        void printCharacterDetails();
    
    private:

};

#endif