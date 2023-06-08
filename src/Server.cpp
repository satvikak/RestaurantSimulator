#include "../header/Server.h"
#include "../header/Employee.h"
#include "../header/OrderNode.h"
#include "../header/Table.h"

#include <iostream>
#include <algorithm>

using namespace std;

Server::Server() {
    myTables = nullptr;
    chosenTable = nullptr;
    numTables = 0;
    numMistakes = 0;
}

Server::~Server() {
    for(unsigned int row=0; row<numTables; ++row) {
        delete myTables[row];
    }
    delete[] myTables;
}

Table** Server::getMyTables() const {
    return myTables;
}

Table* Server::getChosenTable() const {
    return chosenTable;
}

void Server::setChosenTable(Table* myTable) {
    chosenTable = myTable;
}

void Server::seatCustomer(int itemsForCustomer, int userNumTables) {
    Customer* newCustomers = new Customer(names, itemsForCustomer);
    int groupSize = newCustomers->getGroupSize();
    cout << endl;
    cout << "Your first task is to seat new customers. 🪑" << endl;
    cout << "Looks like there's a group of " << groupSize;
    if (groupSize < 2) {
        cout << " person ";
    } else {
        cout << " people ";
    }
    cout << "waiting to be seated!" << endl << endl;

    int chosenTableNumber = -1;
    string input = "y";
    do {
            cout << "Enter a number corresponding to an open table: ";
            cin >> chosenTableNumber;
            cout << endl;
            while(chosenTableNumber<=0 || chosenTableNumber>userNumTables) {
                cout << "Invalid input, try again: ";
                cin >> chosenTableNumber;
                cout <<endl;
            }
            cout<<"Open seats at Table #"<<chosenTableNumber<<": "<<myTables[chosenTableNumber-1]->getSeats()<<endl;
            if (!myTables[chosenTableNumber-1]->getAvailability()) {
                cout << "It looks like customers from the previous round are still chatting here! Choose another." << endl; 
            } else {
                cout << "This table is free! Would you like to seat the group here? ('y' = yes, 'n' = no): ";
                cin >> input;
                while(input!="n" && input!="y") {
                    cout<<"Invalid input, try again: ";
                    cin>>input;
                    cout<<endl;
                }
            }
        } while (!myTables[chosenTableNumber-1]->getAvailability() || input == "n");
        setChosenTable(myTables[chosenTableNumber-1]);
        getChosenTable()->setCustomerGroup(newCustomers);
        getChosenTable()->adjustLeftoverSeats(groupSize);
        getChosenTable()->setTableNum(chosenTableNumber);
        getChosenTable()->setEntryTime(chrono::steady_clock::now());
        tablesToClear.push_back((getChosenTable())->getTableNum());
}

vector<OrderNode>& Server::takeOrder() {
    cout << endl;
    cout << "Great! They love their seats. Your next job is to take their order. 📝" << endl;
    cout << "Type 'y' when you are ready: ";
    string enter = "n";
    cin >> enter;
    while(enter!="y") {
        cout<<"Invalid input. Try again: ";
        cin>>enter;
        cout<<endl;
    }
    cout << "You asked them for their order, this is what they want: " << endl << endl;
    chosenTable->getCustomerGroup()->generateOrders(ordersCreation);
    printCustomerOrders(ordersCreation);
    return ordersCreation;
}

vector<OrderNode> Server::getOrder() const {
    return ordersCreation;
}

void Server::setOrder(vector<OrderNode>& ordersList) {
    if(ordersCreation.size()>0) {
        removeOrders();
    }
    for(unsigned int i=0; i<ordersList.size(); ++i) {
        ordersCreation.push_back(ordersList.at(i));
    }
}

void Server::removeOrders() {
    while(ordersCreation.size()!=0) {
        ordersCreation.pop_back();
    }
}

void Server::printCustomerOrders(vector<OrderNode>& ordersList) {
    for (int i = 0; i < ordersList.size(); i++) {
        ordersList.at(i).printOrder();
    }
}
void Server::billTable(double totalPrice) {
    chosenTable->setBillAmount(totalPrice);
}

void Server::serveCustomer(int customerNum, string nameItem) {
    int numTries = 0;
    string userGuess = "";
    string userGuessLower = "";
    string nameItemLower = "";
    for(int i=0; i<nameItem.length(); ++i) {
        nameItemLower+=tolower(nameItem[i]);
    }
    cout<<"Enter the exact name of the Menu Item that "<<ordersCreation.at(customerNum).getCustomerName()<<" ordered: ";
    getline(cin, userGuess);
    while(numTries<=2) {
        numTries++;
        for(int i=0; i<userGuess.length(); ++i) {
            userGuessLower+=tolower(userGuess[i]);
        }
        if(userGuessLower==nameItemLower) {
            cout << "That's Correct! ✅" << endl;
            cout<<"Serving "<<(ordersCreation.at(customerNum)).getCustomerName()<<" their order!"<<endl<<endl;
            return;
        }
        else if(numTries == 1) {
            userGuess = "";
            userGuessLower = "";
            cout << "That's Incorrect. Try Again. 👎" << endl;
            cout<<"Item Name: ";
            getline(cin, userGuess);
            cout<<endl;
            addMistakes(1);
            numTries++;
        }
        else {
            cout << "That's Incorrect. Balance and Rating Decreased. ❌" << endl;
            addMistakes(1);
            numTries++;
            cout<<"Serving "<<(ordersCreation.at(customerNum)).getCustomerName()<<" their actual order."<<endl <<endl;
        }
    }
}

void Server::openUpTables(int userNum) {
    numTables = userNum;
    myTables = new Table*[numTables];            //Creates pointer to array of Table objects
    for(unsigned int i=0; i<numTables; ++i) {
        myTables[i] = new Table();              //Initializes Table objects
    }
}

void Server::clearUsedTables() {
    for(unsigned int i=0; i<tablesToClear.size(); ++i) {        //Checks if any tables need to be cleared
        Table* currentTable = myTables[tablesToClear.at(i)-1];
        currentTable->setExitTime(chrono::steady_clock::now());
        if(currentTable->getTotalTime()>120) {                  //Removes old customers every 120 seconds, can be changed to less if needed
            delete currentTable->getCustomerGroup();
            currentTable->setCustomerGroup(nullptr);
            currentTable->setSeats(6);
        }
    }
}

int Server::getMistakes() const {
    return numMistakes;
}

void Server::addMistakes(int mistakes) {
    numMistakes+=mistakes;
} 

void Server::printCharacterDetails() {
    string name;
    cout << "Enter your server name: ";
    cin.ignore();
    getline(cin, name);
    Employee::setEmployeeName(name);
    cout << endl << "You are officially Server " << name << "! 👱" << endl;
}