#include "../header/Restaurant.h"

#include <iostream>
using namespace std;

int main() {
    cout << endl << "Welcome to your new restaurant!" << endl;
    cout << "Enter 'QUIT' at any time to end the game" << endl << endl;

    Restaurant* myRestaurant = new Restaurant();

    myRestaurant->simulateRestaurant();


    return 0;
}