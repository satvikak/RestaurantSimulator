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
#include <string>

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
    
    int cycleNum = 1; //counter to keep track of number of cycles in game

    while (this->getRating() >= 2 && this->getBalance() > 0) {
        //manager screen
        if (cycleNum == 1) {
            m.printCharacterDetails();
            cout << endl;
        }
        else {
            cout << "You are now Manager " << m.Employee::getEmployeeName() << "! 🎉" << endl << endl;
        }
            //create menu
            if (cycleNum >= 2) {
                string makeChange;
                int _newFoodNum;
                double _newFoodPrice;

                cout << endl << "Would you like to change the price of any items on your menu? 💲" << endl;
                cout << "Type 'y' for yes, 'n' for no: ";
                cin >> makeChange;
                makeChange = validateStringInput(makeChange, 2);
                cout << endl;

                if (makeChange == "y") {
                    int lastNum = 0;

                    cout << "Enter the menu number (1 - ";
                    lastNum = m.getLastMenuNumber();
                    cout << lastNum << ") of the item's price to change: ";
                    cin >> _newFoodNum;

                    while (_newFoodNum > m.getLastMenuNumber() || _newFoodNum <= 0) {
                        cout << endl << "Uh-oh, that's not a valid menu number! Try again: ";
                        cin >> _newFoodNum;
                    }
                    cout << endl;

                    cout << "Enter the new price of the item: $";
                    cin >> _newFoodPrice;
                    _newFoodPrice = validateDoubleInput(_newFoodPrice, 1);
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
                string userInput = "y";

                while (userInput != "n") {
                    _menuNumber++;

                    cout << "Enter food type ('a' = appetizer, 'm' = main course, 'd' = dessert): ";
                    cin >> _foodType;
                    _foodType = validateStringInput(_foodType, 1);
                    cout << endl;

                    cout << "Enter food item: ";
                    cin.ignore();
                    getline(cin, _foodItem);
                    cout << endl;

                    cout << "Enter food price: $";
                    cin >> _foodPrice;
                    _foodPrice = validateDoubleInput(_foodPrice, 1);
                    cout << endl;

                    MenuItem* newMenuItem = new MenuItem(_menuNumber, _foodType, _foodItem, _foodPrice);
                    m.menuAdd(newMenuItem);

                    cout << "Add another item? ('y' = yes, 'n' = no): ";
                    cin >> userInput;
                    userInput = validateStringInput(userInput, 2);
                    cout << endl << endl;
                }
            }

            m.viewFullMenu(); //print full menu for each cycle

        //server screen
        if (cycleNum == 1) {
            s.printCharacterDetails();
            cout << endl;
        }
        else {
            cout << "You are now Server " << s.Employee::getEmployeeName() << "! 👱" << endl << endl;
        }

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
            string input = "y";
            do {
                cout<<"Enter a number corresponding to an open table: ";
                cin>>chosenTableNumber;
                chosenTableNumber = validateIntInput(chosenTableNumber, 1);
                cout << endl;
                cout<<"Open seats at Table #"<<chosenTableNumber<<": "<<myTables[chosenTableNumber-1]->getSeats()<<endl;
                if (!myTables[chosenTableNumber-1]->getAvailability()) {
                    cout << "This table is occupied. Choose another." << endl; 
                } else {
                    cout << "This table is free! Would you like to seat the group here? ('y' = yes, 'n' = no): ";
                    cin >> input;
                    input = validateStringInput(input, 2);
                }
            } while (!myTables[chosenTableNumber-1]->getAvailability() || input == "n");

            Table* chosenTable = myTables[chosenTableNumber-1];
            chosenTable->setCustomerGroup(newCustomers);

            // Take customer order
            cout << endl;
            cout << "Great! They love their seats. Your next job is to take their order. 📝" << endl;
            cout << "Type 'y' when you are ready: ";
            string enter;
            cin >> enter;
            enter = validateStringInput(enter, 3);
            cout << endl;

            // view orders
            cout << "You asked them for their order, this is what they want: " << endl << endl;
            Order customerOrders;
            newCustomers->generateOrders(customerOrders.getOrdersList());
            customerOrders.printOrders();

            cout << endl;
            cout << "Wonderful! Now that you have the orders, it's time for the chef to make the items... 🍲" << endl;

        //create bill
        int billTotalAmount = 0;
        int currentMenuItem = 0;
        int numberOfMenuItems = m.getLastMenuNumber();
        for (int i = 0; i < groupSize; i++) {
            currentMenuItem = customerOrders.getOrdersList().at(i).itemNumber;
            billTotalAmount += m.getPriceOfChosenMenuItem(currentMenuItem);
        }
        chosenTable->setBillAmount(billTotalAmount);


        //chef screen
        if (cycleNum == 1) {
            c.printCharacterDetails();
            cout << endl;
        }
        else {
            cout << "You are now Chef " << c.Employee::getEmployeeName() << "! 🍴" << endl << endl;
        }

            // Print orders with food type
            cout << "Here are the orders you need to prepare:" << endl;
            for (int i = 0; i < groupSize; i++) {
                int itemNumber = customerOrders.getOrdersList().at(i).itemNumber;
                string itemType = m.getItemType(itemNumber);
                cout << "Item #" << itemNumber << " is a " << itemType << endl;
            }
            cout << endl;

            // Prompt mc and typing game in order of appetizer, main course, and dessert
            for (int i = 0; i < groupSize; i++) {
                string itemType = m.getItemType(customerOrders.getOrdersList().at(i).itemNumber);
                
                if (itemType == "appetizer") {
                    c.MCGame(itemType);
                    c.typingGame(itemType);
                    break;
                }
            }

            for (int i = 0; i < groupSize; i++) {
                string itemType = m.getItemType(customerOrders.getOrdersList().at(i).itemNumber);

                if (itemType == "main course") {
                    c.MCGame(itemType);
                    c.typingGame(itemType);
                    break;
                }
            }

            for (int i = 0; i < groupSize; i++) {
                string itemType = m.getItemType(customerOrders.getOrdersList().at(i).itemNumber);
                
                if (itemType == "dessert") {
                    c.MCGame(itemType);
                    c.typingGame(itemType);
                    break;
                }
            }

            // Prompt typing game for clean-up
            cout << "You're done prepping the meals! Time to clean up! 🧹" << endl;
            c.MCGame("clean");
            cout << endl;

            // Adjust restaurant balance for chef's mistakes
            for (int i = 0; i < c.getMistakes(); i++) {
                this->setBalance(this->getBalance() * 0.9);
                if (this->getRating() >= 0.1) {
                    this->setRating(this->getRating() - 0.1);
                }
            }

        //server screen
        cout << "You are now Server " << s.Employee::getEmployeeName() << "! 👱" << endl << endl;
        cout << "Now that the food is prepared, it is time to serve your table..." << endl;
        cout << "Do you remember what menu item each person ordered?" << endl << endl;

            //serve customers their food in correct order
            int enteredMenuItem = 0;
            cout  << "Serve the customers by entering what menu item they ordered: " << endl;

        
        //pay bill
        cout << "Looks like the party just finished their meal and paid the bill..." << endl;
        cout << "Congrats! You made $" << billTotalAmount << " dollars for your restaurant. 💰" << endl << endl;
        this->setBalance(this->getBalance() + billTotalAmount);
            

            //evaluate results (check balance, rating, etc) and go back to start if results pass
            cout << this->getRestaurantName() << " Review: " << this->getRating() << "/5 Stars ⭐" << endl;
            cout << this->getRestaurantName() << " Balance: $" << this->getBalance() << " 💵" << endl << endl;

 
        //display message based on whether results pass or fail
        if (this->getRating() >= 2 && this->getBalance() > 0) {
                string userChoice;
                cycleNum++;

                cout << "Congratulations! Your first day at your new restaurant was a success! 👏" << endl;
                cout << "Would you like to continue or quit? ('c' = continue, 'q' = quit): ";
                cin >> userChoice;
                userChoice = validateStringInput(userChoice, 4);
                cout << endl;

                if (userChoice == "q") {
                    cout << "Hope you had fun role-playing in a restaurant! Until next time! 👋" << endl << endl;
                    m.clearFullMenu();

                    for(unsigned int row=0; row<numTables; ++row) {
                        delete myTables[row];
                    }
                    delete[] myTables;

                    delete newCustomers;

                    return; //end game
                }
                else if (userChoice == "c") {
                    cout << "TIME FOR ROUND " << cycleNum << "! GOOD LUCK! 🍀" << endl << endl;
                }
        }
        else {
            cout << "Oh no! Seems like your restaurant didn't do too well. 🙁" << endl;
            cout << "Thanks for playing, better luck next time! 👋" << endl << endl;
            m.clearFullMenu();

            for(unsigned int row=0; row<numTables; ++row) {
                delete myTables[row];
            }
            delete[] myTables;

            delete newCustomers;

            return; //end game
        }
    }
}

string Restaurant::validateStringInput(string userInput, int num) {
    string newInput = userInput;

    if (num == 1) {
        while (newInput != "a" && newInput != "m" && newInput != "d") {
            cout << endl << "Invalid food type, try again: ";
            cin >> newInput;
        }
    }
    else if (num == 2) {
        while (newInput != "n" && newInput != "y") {
            cout << endl << "Invalid input, try again: ";
            cin >> newInput;
        }
    }
    else if (num == 3) {
        while (newInput != "y") {
            cout << endl << "Invalid input, try again: ";
            cin >> newInput;
        }
    }
    else if (num == 4) {
        while (newInput != "c" && newInput != "q") {
            cout << endl << "Invalid input, try again: ";
            cin >> newInput;
        }
    }

    return newInput;
}

int Restaurant::validateIntInput(int userInput, int num) {
    int newInput = userInput;

    if (num == 1) {
        while (newInput <= 0 || newInput > 15) {
            cout << endl << "Invalid table number, try again: ";
            cin >> newInput;
        }
    }

    return newInput;
}

double Restaurant::validateDoubleInput(double userInput, int num) {
    double newInput = userInput;

    if (num == 1) {
        while (newInput <= 0.0 || newInput > 1000.0) {
            cout << endl << "Invalid price, try again: $";
            cin >> newInput;
        }
    }

    return newInput;
}