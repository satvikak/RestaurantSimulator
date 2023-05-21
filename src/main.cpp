#include "../header/Chef.h"
#include "../header/Customer.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
//#include "../header/Order.h"
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

    //server screen
        Server s = Server();
        s.printCharacterDetails();

    //chef screen
        Chef c = Chef();
        c.printCharacterDetails();

    //server screen
        cout << "You are now Server " << s.Employee::getEmployeeName() << "!" << endl;

    //evaluate results (check balance, rating, etc) and go back to start if results pass
    cout << r.getRestaurantName() << "Review: " << r.getRating() << "/5 Stars." << endl;
    cout << r.getRestaurantName() << "Balance: " << r.getBalance() << "$" << endl;
}

    //delete anything allocated with new or any objects in the end
        //delete myMenu;
        //delete myOrder;
        //delete newMenuItem; //compiler error when trying to delete

    return 0;
}