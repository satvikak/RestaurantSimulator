#include "../header/Restaurant.h"
#include "../header/Chef.h"
#include "../header/Customer.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
#include "../header/Server.h"
#include "../header/Table.h"

#include <iostream>
#include <iomanip>
using namespace std;

Restaurant::Restaurant() {
    restaurantName = "";
    restaurantBalance = 0.0;
    rating = 0.0;
    numTables = 15;
}

const string& Restaurant::getRestaurantName() const {
    return restaurantName;
}

void Restaurant::setName(string restName) {
    return;
}

const double Restaurant::getBalance() {
    return 0.0;
}

void Restaurant::setBalance(double restBalance) {
    return;
}

const double Restaurant::getRating() {
    return 0.0;
}

void Restaurant::setRating(double restRating) {
    return;
}

void Restaurant::createFloorPlan() { 
    int tableNumber = 1;
    int numRows = 0;
    int tablesPerRow = 5;

    if(numTables%5==0) {                    //Checks if tables can be split evenly into 5 rows
        numRows = numTables/5;
    }
    else {                                  //Handles cases where tables can be split evenly into 5 rows
        if(numTables<5) {
            numRows = 1;
        }
        numRows = numTables/5+1;
    }

    for(int i=0; i<numRows; ++i) {          //Makes tables given number of rows
        if(numTables%5!=0) {                //Makes adjustments for last row if unevenly distributed
            if(i==numRows-1) {
                tablesPerRow = numTables%5;
            }
        }
        
        for(unsigned int numDashes=0; numDashes<tablesPerRow; ++numDashes) {    //Creates table head
            if(numDashes<tablesPerRow-1) {
                cout<<"-----"<<setw(10);
            }
            else {
                cout<<"-----";
            }
        }
        cout<<endl;
        
        for(unsigned int numSpaces=0; numSpaces<3; ++numSpaces) {               //Creates "seats" for table
            int iterations = 0;
            int columnNumber = 1;
            while(iterations<tablesPerRow) {
                if(numSpaces==1) {                                              //Writes down table number
                    if(tableNumber<10) {
                        cout<<"| "<<tableNumber<<" |";
                    }
                    else {
                        cout<<"| "<<tableNumber<<"|";
                    }
                    if(iterations!=tablesPerRow-1) {                            //Adjusts spacing issues if necessary
                        cout<<setw(7);
                    }
                    tableNumber++;
                }
                else {
                    cout<<"|   |";
                    if(iterations!=tablesPerRow-1) {                            //Formats area without table number
                        cout<<setw(10);
                    }
                }
                iterations++;
                columnNumber++;
            }
            cout<<endl;
        }
        
        for(unsigned int numDashes=0; numDashes<tablesPerRow; ++numDashes) {    //Creates table end
            if(numDashes<tablesPerRow-1) {
                cout<<"-----"<<setw(10);
            }
            else {
                cout<<"-----";
            }
        }
        cout<<endl;
    }

    myTables = new Table*[numTables];                                           //Creates pointer to array of Table objects
    for(unsigned int i=0; i<numTables; ++i) {
        myTables[i] = new Table();                                              //Initializes Table objects
    }
}

void Restaurant::simulateRestaurant() {                                         //Simulates Restaurant game
    //Manager Screen
    Manager* myManager = new Manager();
    this->createFloorPlan();
    
    //Server Screen
    Server* myServer = new Server();
    int chosenTable = -1;
    cout<<"Enter a number corresponding to an open table: ";
    cin>>chosenTable;
    cout<<"Open seats at Table #"<<chosenTable<<": "<<myTables[chosenTable-1]->getSeats()<<endl;
}