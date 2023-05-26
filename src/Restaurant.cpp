#include "../header/Restaurant.h"
#include "../header/Chef.h"
#include "../header/Customer.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
#include "../header/Server.h"
#include "../header/Table.h"
#include "../header/Order.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

Restaurant::Restaurant() {
    restaurantName = "";
    restaurantBalance = 100.0;
    rating = 5.0;
    numTables = 15;
    m = Manager();
    s = Server();
    c = Chef();
}

Restaurant::~Restaurant() {

}

const string& Restaurant::getRestaurantName() const {
    return restaurantName;
}

void Restaurant::setRestaurantName(string restName) {
    restaurantName = restName;
}

const double Restaurant::getBalance() {
    return restaurantBalance;
}

void Restaurant::setBalance(double restBalance) {
    restaurantBalance = restBalance;
}

const double Restaurant::getRating() {
    return rating;
}

void Restaurant::setRating(double restRating) {
    rating = restRating;
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
        
        for(unsigned int numSpaces=0; numSpaces<3; ++numSpaces) {       //Creates "seats" for table
            int iterations = 0;
            int columnNumber = 1;
            while(iterations<tablesPerRow) {
                if(numSpaces==1) {                          //Writes down table number
                    if(tableNumber<10) {
                        cout<<"| "<<tableNumber<<" |";
                    }
                    else {
                        cout<<"| "<<tableNumber<<"|";
                    }
                    if(iterations!=tablesPerRow-1) {        //Adjusts spacing issues if necessary
                        cout<<setw(7);
                    }
                    tableNumber++;
                }
                else {
                    cout<<"|   |";
                    if(iterations!=tablesPerRow-1) {        //Formats area without table number
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

    myTables = new Table*[numTables];            //Creates pointer to array of Table objects
    for(unsigned int i=0; i<numTables; ++i) {
        myTables[i] = new Table();              //Initializes Table objects
    }
}

void Restaurant::simulateRestaurant() {         //Simulates Restaurant game
    srand(time(NULL));

    //initial restaurant setup
    string restaurantName = "";
    cout << "Enter a name for your restaurant: ";
    getline(cin, restaurantName);
    this->setRestaurantName(restaurantName);
    cout << endl;
    
    //Manager* m = new Manager();
    int cycleNum = 1; //counter to keep track of number of cycles in game

    while (this->getRating() >= 2 && this->getBalance() > 0) {
        //manager screen
        m.printCharacterDetails();

            //create menu
            if (cycleNum >= 2) {
                char makeChange;
                int _newFoodNum;
                double _newFoodPrice;

                cout << "Would you like to change the price of any items on your menu?" << endl;
                cout << "Type 'y' for yes, 'n' for no: ";
                cin >> makeChange;
                cout << endl << endl;

                if (makeChange == 'y') {
                    cout << "Enter the menu number of the item's price to change: ";
                    cin >> _newFoodNum;
                    cout << endl;

                    cout << "Enter the new price of the item: $";
                    cin >> _newFoodPrice;
                    cout << endl << endl;

                    m.changeMenuPrice(_newFoodNum, _newFoodPrice);
                    cout << "Here is the updated menu!" << endl << endl;
                }
            }
            else {
                cout << "Time to create a menu for " << restaurantName << "! ";
                cout << "What would you like your customers to have? 📝" << endl << endl;

                int _menuNumber = 0;
                string _foodType = "x";
                string _foodItem = "x";
                double _foodPrice = 0.0;
                char userInput = 'y';

                while (userInput != 'n') {  //include user input validation
                    _menuNumber++;

                    cout << "Enter food type ('a' = appetizer, 'm' = main course, 'd' = dessert): ";
                    cin >> _foodType;
                    cout << endl;

                    cout << "Enter food item: ";
                    cin.ignore();
                    getline(cin, _foodItem);
                    cout << endl;

                    cout << "Enter food price: $";
                    cin >> _foodPrice;
                    cout << endl;

                    MenuItem* newMenuItem = new MenuItem(_menuNumber, _foodType, _foodItem, _foodPrice);
                    m.menuAdd(newMenuItem);

                    cout << "Add another item? ('y' = yes, 'n' = no): ";
                    cin >> userInput;
                    cout << endl << endl;
                }
            }

            m.viewFullMenu(); //print full menu for each cycle

        //server screen
        s.printCharacterDetails();

            //display floorplan
            cout<<"Here is the floorplan for your restaurant: "<<endl << endl;
            this->createFloorPlan();

            //seat a customer
            int totalMenuItems = m.getLastMenuNumber();

            Customer* newCustomers = new Customer(names, totalMenuItems);
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
            char input = 'y';
            do {
                cout<<"Enter a number corresponding to an open table: ";
                cin>>chosenTableNumber;
                cout << endl;
                cout<<"Open seats at Table #"<<chosenTableNumber<<": "<<myTables[chosenTableNumber-1]->getSeats()<<endl;
                if (!myTables[chosenTableNumber-1]->getAvailability()) {
                    cout << "This table is occupied. Choose another." << endl; 
                } else {
                    cout << "This table is free! Would you like to seat the group here? ('y' = yes, 'n' = no): ";
                    cin >> input;
                }
            } while (!myTables[chosenTableNumber-1]->getAvailability() || input == 'n');

            Table* chosenTable = myTables[chosenTableNumber-1];
            chosenTable->setCustomerGroup(newCustomers);

            // Take customer order
            cout << endl;
            cout << "Great! They love their seats. Your next job is to take their order." << endl;
            cout << "Type 'y' when you are ready: ";
            char enter;
            cin >> enter;
            cout << endl;

            // view orders
            cout << "You asked them for their order, this is what they want: " << endl << endl;
            Order customerOrders;
            newCustomers->generateOrders(customerOrders.getOrdersList());
            customerOrders.printOrders();

            cout << endl;
            cout << "Wonderful! Now that you have the orders, it's time for the chef to make the items... 🍲" << endl;


        //chef screen
        c.printCharacterDetails();

            //make customers' orders
            cout << endl;


            //remove orders from pending orders list

        //server screen
        cout << "You are now Server " << s.Employee::getEmployeeName() << "! 👱" << endl;

            //serve customers their food in correct order
            

            //evaluate results (check balance, rating, etc) and go back to start if results pass
            cout << this->getRestaurantName() << " Review: " << this->getRating() << "/5 Stars ⭐" << endl;
            cout << this->getRestaurantName() << " Balance: $" << this->getBalance() << " 💵" << endl << endl;

        //delete anything allocated with new
            //delete newMenuItem; //compiler error when trying to delete (Valgrind looks fine)
        
        //display message based on whether results pass or fail
        if (this->getRating() >= 2 && this->getBalance() > 0) {
                char userChoice;
                cycleNum++;

                cout << "Congratulations! Your first day at your new restaurant was a success!" << endl;
                cout << "Would you like to continue or quit? ('c' = continue, 'q' = quit): ";
                cin >> userChoice;
                cout << endl << endl;

                if (userChoice == 'q') {
                    cout << "Hope you had fun role-playing in a restaurant! Until next time!" << endl << endl;
                    m.clearFullMenu();

                    for(unsigned int row=0; row<numTables; ++row) {
                        delete myTables[row];
                    }
                    delete[] myTables;

                    return; //end game
                }
                else if (userChoice == 'c') {
                    cout << "Time for round " << cycleNum << "!" << endl << endl;
                }
        }
        else {
            cout << "Oh no! Seems like your restaurant didn't do too well :(" << endl;
            cout << "Thanks for playing, better luck next time!" << endl << endl;
            m.clearFullMenu();

            for(unsigned int row=0; row<numTables; ++row) {
                delete myTables[row];
            }
            delete[] myTables;

            return; //end game
        }
    }
}