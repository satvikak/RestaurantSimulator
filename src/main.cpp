#include "../header/Chef.h"
#include "../header/Customer.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
#include "../header/Order.h"
#include "../header/Restaurant.h"
#include "../header/Server.h"
#include "../header/Table.h"

using namespace std;

int main() {
    cout << endl << "Welcome to your new restaurant!" << endl;
    cout << "Enter 'QUIT' at any time to end the game" << endl << endl;

    //initial restaurant setup
    Restaurant r = Restaurant();
    string restaurantName;
    cout << "Enter a name for your restaurant: ";
    getline(cin, restaurantName);
    r.setName(restaurantName);

    while (r.getBalance() > 0 && r.getRating() > 0) {
        //manager screen
            Manager m = Manager();
            m.printCharacterDetails();

            //create menu
            cout << "Time to create a menu for your restaurant! "; //replace with restaurantName variable
            cout << "What would you like your customers to have?" << endl << endl;

            Manager* myMenu = new Manager();

            int _menuNumber = 0;
            string _foodType;
            string _foodItem;
            double _foodPrice;
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

                MenuNode* newMenuItem = new MenuNode(_menuNumber, _foodType, _foodItem, _foodPrice);
                myMenu->menuAdd(newMenuItem);

                cout << "Add another item? ('y' = yes, 'n' = no): ";
                cin >> userInput;
                cout << endl << endl;
            }

            myMenu->viewFullMenu(); //print full menu (can be used later by the server to display the menu)

        //server screen
            Server s = Server();
            s.printCharacterDetails();

            //display floorplan


            //seat a customer


            //display menu


            //take orders (feel free to edit this later, I was just compiler testing the Order class)
            int numOrders;
            int customerOrder;
            Order* myOrder = new Order(); //pointer object?

            cout << "Time to order your food! First, how many things would you like to order?" << endl;
            cout << "Enter a number: ";
            cin >> numOrders;
            cout << endl;

            cout << "Great! Now, enter the menu number (1 - " << _menuNumber << ") of what you'd like to order!" << endl;
            cout << "My Order:" << endl;

            for (int i = 1; i <= numOrders; ++i) {
                cout << i << ") ";
                cin >> customerOrder;
                myOrder->addOrder(customerOrder);
            }

            cout << endl;
            cout << "Thanks for ordering! Your food will be right up!" << endl;

        //chef screen
            Chef c = Chef();
            c.printCharacterDetails();

            //view list of orders (feel free to edit this later, I was just compiler testing the Order class)
            myOrder->viewAllOrders();
            cout << endl;

            //make customers' orders


            //remove orders from pending orders list

        //server screen
            cout << "You are now Server " << s.Employee::getEmployeeName() << "!" << endl;

            //serve customers their food in correct order


        //evaluate results (check balance, rating, etc) and go back to start if results pass
        cout << r.getRestaurantName() << "Review: " << r.getRating() << "/5 Stars." << endl;
        cout << r.getRestaurantName() << "Balance: " << r.getBalance() << "$" << endl;
    }

//delete anything allocated with new or any objects in the end
    delete myMenu;
    //delete myOrder;
    //delete newMenuItem; //compiler error when trying to delete

    return 0;
}