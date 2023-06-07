#ifndef SERVER_H
#define SERVER_H

#include "../header/Employee.h"
#include "../header/Table.h"
#include "../header/OrderNode.h"

#include <iostream>

using namespace std;

class Server : public Employee  {
    public:
        Server();
        ~Server();
        void setChosenTable(Table* myTable);
        Table* getChosenTable() const;
        Table** getMyTables() const;
        vector<OrderNode> getOrder() const;
        void setOrder(vector<OrderNode>& ordersList);
        void seatCustomer(int itemsForCustomer, int userNumTables);
        vector<OrderNode>& takeOrder();
        void serveCustomer(int customerNum, string nameItem);
        void printCharacterDetails();
        void openUpTables(int userNum);
        void clearUsedTables();
        void printCustomerOrders(vector<OrderNode>& ordersList);
        void billTable(double totalPrice);
        void removeOrders();
        int getMistakes() const;
        void addMistakes(int mistakes);
    
    private:
        Table** myTables;
        Table* chosenTable;
        vector<int> tablesToClear;
        vector<string> names{"Angelica", "Ben", "Angel", "Ryan", "Sophia", "Ruby", "Carly", "Lexi", "Joshua", "Ken", "Raquel", "Beth", "Rio", "Fiona", "Richard"};
        vector<OrderNode> ordersCreation;
        int numTables;
        int numMistakes;
};

#endif