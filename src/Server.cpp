#include "../header/Server.h"
#include "../header/Employee.h"

#include <iostream>
using namespace std;

Server::Server() {

}

void Server::seatCustomer() {
    
}

void Server::displayMenu() {

}

void Server::takeOrder() {

}

void Server::serveCustomer() {

}

void Server::printCharacterDetails() {
    string name;
    cout << "Enter your server name: ";
    getline(cin, name);
    Employee::setEmployeeName(name);
    cout << endl << "You are officially Server " << name << "!" << endl;
}