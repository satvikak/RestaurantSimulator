#include "../header/Restaurant.h"

//#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    cout << endl << "Welcome to your new restaurant! 🍽️" << endl;

    Restaurant r = Restaurant();
    r.simulateRestaurant();

    return 0;
}