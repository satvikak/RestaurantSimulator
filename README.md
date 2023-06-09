[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10870110&assignment_repo_type=AssignmentRepo)

# Restaurant Simulator 
 > Authors: [Suhani Bhanvadia](https://github.com/suhanihb), [Suhani Chaudhary](https://github.com/suhanic44), [Satvi Kammula](https://github.com/Satvi-Kammula), [Vaneesha Singh](https://github.com/vsingh9)

## Project Overview
**General Description:**

This project is a terminal-based restaurant simulator game. The user gets to experience being in the shoes of various roles in a restaurant and perform the respective day to day tasks for each character. The three major roles that this game will take the user through are the Manager, the Server, and the Chef. The user starts off as the Manager where they conduct the initial setup of the restaurant and the creation of a menu. The user then transitions to become the Server, where a visual floor plan is displayed to assist the Server in seating their customers at an open table. After the group is seated, the Server takes the order for their customers. A random generator is used to randomly assign items from the menu as orders for each customer. Then, the user transitions into the Chef, who is responsible for “cooking” the orders they received from the Server. Once the orders have been cooked, the user transitions back into the Server to deliver each customer their appropriate meal. After the customer has finished dining, they pay their bill and leave a rating of their experience. The game concludes with an evaluation of the restaurant’s overall balance and rating, which if exceeds a certain criteria, allows the user to play another cycle of the game.
 
**Why It's Important:**

This project is important for our group because we have all grown up playing role-playing computer games similar to this. The idea of being able to code a terminal-based game using the skills we currently possess piqued our interest, encouraging us to formulate a project that others could find entertaining as well. In addition, since some of the members in our group have experience with working in the food industry, we aimed to put the user in the shoes of various employees to demonstrate the complexity of completing such tasks. We hope this game can illustrate to the user that many different roles and responsibilities are involved behind the scenes in the actual day to day functioning of a restaurant.
 
**Languages/Tools/Technologies:**
* C++ - The backend of our project will be entirely programmed using C++.

* Visual Studio Code - This is the code editor we will be using to develop and test our code.

* Git - This is the version control system we will be using in our project to coordinate working with multiple users. Using Git allows us to seamlessly develop, commit, and push changes from our local repository. It also lets us submit pull requests to approve code changes made by other members.

* GitHub - This web-based hosting service goes hand-in-hand with Git. Current and past versions of our code can be viewed here. GitHub will also store the Kanban Board used by our team to keep track of who completes what tasks and the current status of each task.

* CMake - This is a tool we implemented to compile our code into executables that easily run our program and unit tests.

* Google Test Framework - This C++ testing framework made by Google allows us to write and run unit tests for the different functions in our code. Such testing will ensure that our program runs as expected and handles edge cases appropriately.

* Valgrind - This is a dynamic analysis tool to manage memory used by the program and keep track of any memory leaks or errors with memory allocation. This tool will ensure we have properly deleted all memory at the end of the program’s lifetime.

**Input/Output:**
* Input - As the manager, the user will be able to enter a name for the restaurant, add items to the menu (item type, item name, and item price), change the price of items on the menu, and pick the number of tables they want at their restaurant. As the server, the user will be able to enter a table number to seat a group of customers, take orders, serve customers their order, and collect the bill. As the chef, the user will be able to receive a list of pending orders, complete steps to prepare each meal type, and type up prompts to imitate "cooking" the orders.
* Output - The program will display various forms of output as the user enters information into the game. As the manager, the user will be able to view the full restaurant menu once they have added items to it. As the server, the user can see a visual display of the floor plan representing seats at the restaurant. As the chef, the user can view what items have been ordered by the customer. At the end of the game, the user can view the overall rating and balance of the restaurant.

## Class Diagram
![Final Restaurant UML Diagram](https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/129975596/edfeff0c-7958-495c-b163-2f491221960e)

* The Restaurant class holds the major functionality to run the game that the user will see in the terminal. It includes a function to set the name of the restaurant. The setBalance() function takes the customer’s bill (based on prices set up in the menu) and adds that to the total balance of the restaurant. The setRating() function sets the restaurant’s overall rating based on a random generator in the Customer class. The floorplan is displayed to the terminal by a 2d array of pointers to Table objects developed in displayFloorPlan(). The purpose of displayFloorPlan() is to allow the server to seat customers at an open table and keep track of which tables are occupied. Each table is given a number that is used to keep track of which orders are from which group of customers. Most importantly, simulateRestaurant() runs the user through each cycle of the game through a series of inputs and outputs as they transition from manager, to server, to chef, and then back to server. This is where the user will be able to add items to the menu as the manager, seat customers at a table as the server, cook orders as the chef, and serve customers with their completed order. The simulateRestaurant() function ends with an evaluation of the restaurant’s balance and rating, which if passed, allows the user to play the game again.
 
* The Table class is utilized by the Restaurant class and the Server class to store information about table availability and customer groups at a specific table. The setCustomerGroup() function is responsible for maintaining details about a customer group at a specific table. The getAvailability() function checks the number of available seats at a table and returns that information to the server to seat their customers. The entryTime() and exitTime() functions are used to keep track of the time from start to end a customer group has spent at a table. The Server class further implements the functionality of this class when taking the customers’ orders and calculating the bill at a table. Overall, this class is used for organizational purposes for other classes.
 
* The Customer class is the main competition the user faces in the game. It is implemented as a robot with randomly generated values and reviews, mocking how a real customer would behave in a restaurant. The generateRandomOrder() function randomly generates orders from the menu and assigns them to each customer in the group. The setRandomPartySize() function is responsible for creating a group with a random number of customers, while the setRandomNames() function randomly assigns each customer of the group with a name from a list. The Customer class will also be utilized by the Table class in terms of group orders and group placement. Overall, the Customer class is a completely randomized, behind-the-scenes development where the user is in charge of pleasing their customers through the means of the restaurant’s employees.
 
* The Employee class serves as an abstract base class for the Server, Chef, and Manager classes. This class’s primary purpose is to provide the functionality to set the name of each employee. The printCharacterDetails() function is virtual so that it can be overridden by the derived classes, since the server, chef, and manager will each have their own information.
 
* The Manager class is responsible for the beginning of the game involving the setup of the restaurant. The menuAdd() function is used by the manager to add foods to the menu and set their prices. In subsequent cycles of the game, the changeMenuPrice() function is called if the manager wishes to alter any previously set prices of items on the menu. Once the manager has added all items to the menu that the user pleases, viewFullMenu() will display the full restaurant menu. The Manager class inherits from the Employee class to allow an object of Manager to set their own name.

* The MenuItem class works hand-in-hand with the Manager class to store some of the implementation of adding items to the menu in the form of a linked list. The parameterized MenuItem() constructor takes user input regarding the menu number, food type, food item, and food price and stores that information together as a node in the linked list. The printMenuItem() function is used to print an individual node (or menu item) from the menu list.

* The OrderNode class works hand-in-hand with the Server class to store information regarding the randomly generated orders from the Customer class. The printOrder() function prints an individual order from a customer. The getItemNumber() function correlates the order to the numbered item on the menu to keep track of customers' orders more easily.

* The Server class includes functionality to obtain table information, seat customers, take their order, serve their order, and collect a table's bill. The seatCustomer() function uses the group size to seat the customers at a table with enough open seats. The takeOrder() function takes an order from each customer through a call to the generateOrders() function and stores all orders in a vector. To serve orders, the server must input the exact name of the menu item within two tries to replicate serving their customers. The removeOrders() function deletes each order from the list so that no previous orders remain in future cycles of the game. The billTable() function sets the bill amount for a table based on prices set in the menu. Once the customer has finished eating their meal, clearUsedTables() is called to open up the table for a future group of customers. The Server class inherits from the Employee class to allow an object of Server to set their own name.
 
* The Chef class receives information about the food type for each order in order to "cook" orders. Before making each set of orders (appetizers, main course, and dessert), the MCGame() function prompts the chef with a list of tasks to complete and the user must type out the tasks in the correct order to proceed. To make the order itself, the chef will type what is prompted to the screen by the typingGame() function exactly as stated to mimic cooking the order. If any mistakes are made, the chef gets another try before the restaurant's balance and rating are decreased. The Chef class inherits from the Employee class to allow an object of Chef to set their own name.

## Navigation Diagram
<img width="517" alt="Screenshot 2023-06-06 at 2 52 11 PM" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/8ef10770-f7be-4788-98c3-2d7485956f43">

## Screen Layout
<img width="579" alt="1" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/afb4767d-3975-4ab2-953e-4377638d4e77">
<img width="579" alt="2" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/6b3d6a01-0f49-43f7-acdb-16a98492e693">
<img width="579" alt="3" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/ea56ffda-5398-45c8-a2b5-d81f00002dfc">
<img width="579" alt="4" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/1117024f-bf06-4497-add3-034cb67af889">

 ## SOLID Principle Changes
* For our first major change, we applied the Single Responsibility Principle (SRP). When first designing the UML diagram, we intended for the Server to have some type of implementation for taking a Customer’s order. However, we decided to take our TA’s suggestion of making a separate Order class since it is something that may be utilized by multiple classes. For instance, the Server class uses the Order class to keep track of the Customers’ orders, the Chef class uses it to make the dish, and the Server must use it to serve the Customers their respective dishes. Keeping this in mind, it did not make sense to implement the Order class within the Server class, so we developed a whole new class instead. This change was helpful in managing the tasks of each individual. The Server and Chef do not need to worry about implementing their own Order, but can now use the class while focusing on their respective tasks. In fact, now it is also easier for the Customers’ information and data to be passed between the Server and the Chef as it is a class that is accessible by the both of them.

* Our second major change was an application of the Open-Closed Principle. Initially, we had a MenuNode within the Manager class so that it could access the Menu aspects in an easier fashion. We had intended for the Manager class to only be able to update the floorplan and keep a general track of the menu. Keeping the MenuNode implementation within the Manager class meant that the Manager wasn’t doing our intended tasks. In other words, we had to modify the Menu class after implementing the Manager class, which meant that the Manager class wasn’t performing tasks solely for the Manager. This change helped make our Manager implementation open for extension, rather than for the Manager class to be responsible for the Menu attributes. With the two separate classes, each class in our program now has a specific purpose rather than trying to take on too many tasks. Also, our previous way of implementing the menu was to use Manager* myMenu = new Manager(). However, this did not make much sense considering that the menu is not a manager pointer. Now, an individual manager character holds a linked list of menuItem objects.

* For our third major change, we implemented the Dependency Inversion Principle in order to avoid changes in the subclass affecting any higher submodules. We initially planned to include functions within the Restaurant class that would set the names of the various employees in the restaurant game. However, this meant that any changes to character details would cause modifications to have to be made to the Restaurant class. To prevent this, we created an abstract class called Employee that contains a pure virtual function to set character details. Then, the respective character classes (Server, Chef, Manager) override this function with their specific character names. As a result, the higher-level modules depend on an abstraction rather than the lower-level modules.
 
 ## Screenshots
<img width="901" alt="ss1" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/92c18322-1ec1-40b4-be43-202d059e44b6">
<img width="901" alt="ss2" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/d9eb6f94-d8db-4298-85d8-a57d5aeae8dc">
<img width="901" alt="ss3" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/e8f19688-4a33-4669-b917-c7ed37375d1b">
<img width="901" alt="ss4" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/e24a75e6-a70b-4054-8362-b92472e688af">

 ## Installation/Usage
 Clone this repository and use the following commands in the terminal:
 ```
$ git clone https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035.git
$ cd final-project-skamm006-sbhan020-schau062-vsing035
$ cmake .
$ make
```
Two executables will be created (play & test). Run the play executable to play the game and follow the prompts on the screen:
 ```
$ ./play
```
 ## Testing
After following the steps in the **Installation/Usage** section, the unit tests for this program can be run using `./test`. These tests are used to ensure that our various classes are working as we expect them to. In this project, we utilized a total of 69 tests across 35 different test suites. Each suite tests a specific function in its respective class.
 
We also utilized Valgrind to ensure that any memory allocated in the main program or the unit tests was properly deallocated. We ran Valgrind on the executable for our program, `./play`, as well as on the executable for our unit tests, `./test`. These checks can be run using `valgrind --leak-check=full ./play` or `valgrind --leak-check=full ./test` respectively. 
 
 <details><summary>Example of Valgrind results on main program</summary>
 <p>
  
 ```$ valgrind --leak-check=full ./play
==414788== Memcheck, a memory error detector
==414788== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==414788== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==414788== Command: ./play
==414788==

**Restaurant Gameplay**  

==414788== 
==414788== HEAP SUMMARY:
==414788==     in use at exit: 0 bytes in 0 blocks
==414788==   total heap usage: 29 allocs, 29 frees, 77,122 bytes allocated
==414788== 
==414788== All heap blocks were freed -- no leaks are possible
==414788== 
==414788== For lists of detected and suppressed errors, rerun with: -s
==414788== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
</details>
 
<details><summary>Example of Valgrind results on unit tests</summary>
<p>
  
 ```$ valgrind --leak-check=full ./test
==352733== Memcheck, a memory error detector
==352733== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==352733== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==352733== Command: ./test
==352733== 
[==========] Running 69 tests from 35 test suites.
[----------] Global test environment set-up.
[----------] 1 test from ChefConstructorTests
[ RUN      ] ChefConstructorTests.noParameters
[       OK ] ChefConstructorTests.noParameters (13 ms)
[----------] 1 test from ChefConstructorTests (20 ms total)

[----------] 1 test from ChefGetter
[ RUN      ] ChefGetter.getMistakes
[       OK ] ChefGetter.getMistakes (1 ms)
[----------] 1 test from ChefGetter (1 ms total)

[----------] 2 tests from CustomerConstructor
[ RUN      ] CustomerConstructor.ThreeParameters
[       OK ] CustomerConstructor.ThreeParameters (8 ms)
[ RUN      ] CustomerConstructor.TwoParameters
[       OK ] CustomerConstructor.TwoParameters (6 ms)
[----------] 2 tests from CustomerConstructor (14 ms total)

[----------] 2 tests from CustomerRandomTests
[ RUN      ] CustomerRandomTests.GenerateOneRandomOrder
[       OK ] CustomerRandomTests.GenerateOneRandomOrder (5 ms)
[ RUN      ] CustomerRandomTests.GenerateListOfRandomOrders
[       OK ] CustomerRandomTests.GenerateListOfRandomOrders (13 ms)
[----------] 2 tests from CustomerRandomTests (19 ms total)

[----------] 2 tests from CustomerGetterSetterTests
[ RUN      ] CustomerGetterSetterTests.getGroupSizeTest
[       OK ] CustomerGetterSetterTests.getGroupSizeTest (5 ms)
[ RUN      ] CustomerGetterSetterTests.setNumberofMenuItems
[       OK ] CustomerGetterSetterTests.setNumberofMenuItems (3 ms)
[----------] 2 tests from CustomerGetterSetterTests (8 ms total)

[----------] 1 test from ManagerConstructorTest
[ RUN      ] ManagerConstructorTest.NoNodes
[       OK ] ManagerConstructorTest.NoNodes (1 ms)
[----------] 1 test from ManagerConstructorTest (1 ms total)

[----------] 2 tests from ManagerEmptyMenuTest
[ RUN      ] ManagerEmptyMenuTest.OneNodeFull
[       OK ] ManagerEmptyMenuTest.OneNodeFull (3 ms)
[ RUN      ] ManagerEmptyMenuTest.TwoNodeEmpty
[       OK ] ManagerEmptyMenuTest.TwoNodeEmpty (4 ms)
[----------] 2 tests from ManagerEmptyMenuTest (7 ms total)

[----------] 1 test from ManagerPriceChangeTest
[ RUN      ] ManagerPriceChangeTest.ChangeMenuPrice
[       OK ] ManagerPriceChangeTest.ChangeMenuPrice (4 ms)
[----------] 1 test from ManagerPriceChangeTest (4 ms total)

[----------] 1 test from ManagerMenuNumTest
[ RUN      ] ManagerMenuNumTest.LastMenuNumber
[       OK ] ManagerMenuNumTest.LastMenuNumber (4 ms)
[----------] 1 test from ManagerMenuNumTest (4 ms total)

[----------] 4 tests from MenuItemGetters
[ RUN      ] MenuItemGetters.getMenuNumber
[       OK ] MenuItemGetters.getMenuNumber (1 ms)
[ RUN      ] MenuItemGetters.getFoodType
[       OK ] MenuItemGetters.getFoodType (2 ms)
[ RUN      ] MenuItemGetters.getFoodItem
[       OK ] MenuItemGetters.getFoodItem (1 ms)
[ RUN      ] MenuItemGetters.getFoodPrice
[       OK ] MenuItemGetters.getFoodPrice (1 ms)
[----------] 4 tests from MenuItemGetters (7 ms total)

[----------] 1 test from MenuItemSetters
[ RUN      ] MenuItemSetters.setFoodPrice
[       OK ] MenuItemSetters.setFoodPrice (2 ms)
[----------] 1 test from MenuItemSetters (2 ms total)

[----------] 1 test from MenuItemConstructor
[ RUN      ] MenuItemConstructor.paramConstructor
[       OK ] MenuItemConstructor.paramConstructor (4 ms)
[----------] 1 test from MenuItemConstructor (4 ms total)

[----------] 1 test from OrderNodeConstructorTests
[ RUN      ] OrderNodeConstructorTests.noParameters
[       OK ] OrderNodeConstructorTests.noParameters (2 ms)
[----------] 1 test from OrderNodeConstructorTests (2 ms total)

[----------] 2 tests from OrderNodeGetterTests
[ RUN      ] OrderNodeGetterTests.getItemNumber
[       OK ] OrderNodeGetterTests.getItemNumber (1 ms)
[ RUN      ] OrderNodeGetterTests.getCustomerName
[       OK ] OrderNodeGetterTests.getCustomerName (1 ms)
[----------] 2 tests from OrderNodeGetterTests (3 ms total)

[----------] 2 tests from OrderNodeSetterTests
[ RUN      ] OrderNodeSetterTests.setItemNumber
[       OK ] OrderNodeSetterTests.setItemNumber (1 ms)
[ RUN      ] OrderNodeSetterTests.setCustomerName
[       OK ] OrderNodeSetterTests.setCustomerName (2 ms)
[----------] 2 tests from OrderNodeSetterTests (4 ms total)

[----------] 3 tests from RestaurantGetters
[ RUN      ] RestaurantGetters.getName
[       OK ] RestaurantGetters.getName (18 ms)
[ RUN      ] RestaurantGetters.getBalance
[       OK ] RestaurantGetters.getBalance (1 ms)
[ RUN      ] RestaurantGetters.getRating
[       OK ] RestaurantGetters.getRating (1 ms)
[----------] 3 tests from RestaurantGetters (22 ms total)

[----------] 3 tests from RestaurantSetters
[ RUN      ] RestaurantSetters.setName
[       OK ] RestaurantSetters.setName (2 ms)
[ RUN      ] RestaurantSetters.setBalance
[       OK ] RestaurantSetters.setBalance (1 ms)
[ RUN      ] RestaurantSetters.setRating
[       OK ] RestaurantSetters.setRating (1 ms)
[----------] 3 tests from RestaurantSetters (6 ms total)

[----------] 4 tests from RestaurantStringValid
[ RUN      ] RestaurantStringValid.foodType
[       OK ] RestaurantStringValid.foodType (4 ms)
[ RUN      ] RestaurantStringValid.yesNo
[       OK ] RestaurantStringValid.yesNo (3 ms)
[ RUN      ] RestaurantStringValid.yes
[       OK ] RestaurantStringValid.yes (2 ms)
[ RUN      ] RestaurantStringValid.contQuit
[       OK ] RestaurantStringValid.contQuit (3 ms)
[----------] 4 tests from RestaurantStringValid (13 ms total)

[----------] 2 tests from RestaurantIntValid
[ RUN      ] RestaurantIntValid.lowerBound
[       OK ] RestaurantIntValid.lowerBound (1 ms)
[ RUN      ] RestaurantIntValid.upperBound
[       OK ] RestaurantIntValid.upperBound (1 ms)
[----------] 2 tests from RestaurantIntValid (3 ms total)

[----------] 2 tests from RestaurantDoubleValid
[ RUN      ] RestaurantDoubleValid.lowerBound
[       OK ] RestaurantDoubleValid.lowerBound (2 ms)
[ RUN      ] RestaurantDoubleValid.upperBound
[       OK ] RestaurantDoubleValid.upperBound (1 ms)
[----------] 2 tests from RestaurantDoubleValid (4 ms total)

[----------] 2 tests from RatingTests
[ RUN      ] RatingTests.generatePerfectCustomerRating
[       OK ] RatingTests.generatePerfectCustomerRating (2 ms)
[ RUN      ] RatingTests.generateImperfectCustomerRating
[       OK ] RatingTests.generateImperfectCustomerRating (5 ms)
[----------] 2 tests from RatingTests (7 ms total)

[----------] 1 test from RatingTest
[ RUN      ] RatingTest.generateLargeMistakeRating
[       OK ] RatingTest.generateLargeMistakeRating (3 ms)
[----------] 1 test from RatingTest (3 ms total)

[----------] 1 test from ServerConstructorTests
[ RUN      ] ServerConstructorTests.noParameters
[       OK ] ServerConstructorTests.noParameters (3 ms)
[----------] 1 test from ServerConstructorTests (3 ms total)

[----------] 4 tests from ServerGetterTests
[ RUN      ] ServerGetterTests.getChosenTable
[       OK ] ServerGetterTests.getChosenTable (1 ms)
[ RUN      ] ServerGetterTests.getMyTables
[       OK ] ServerGetterTests.getMyTables (1 ms)
[ RUN      ] ServerGetterTests.getOrder
[       OK ] ServerGetterTests.getOrder (7 ms)
[ RUN      ] ServerGetterTests.getMistakes
[       OK ] ServerGetterTests.getMistakes (2 ms)
[----------] 4 tests from ServerGetterTests (14 ms total)

[----------] 3 tests from ServerSetterTests
[ RUN      ] ServerSetterTests.setChosenTable
[       OK ] ServerSetterTests.setChosenTable (3 ms)
[ RUN      ] ServerSetterTests.setOrder
[       OK ] ServerSetterTests.setOrder (3 ms)
[ RUN      ] ServerSetterTests.setMistakes
[       OK ] ServerSetterTests.setMistakes (1 ms)
[----------] 3 tests from ServerSetterTests (8 ms total)

[----------] 2 tests from ServerRemoveOrdersTests
[ RUN      ] ServerRemoveOrdersTests.emptyOrder
[       OK ] ServerRemoveOrdersTests.emptyOrder (2 ms)
[ RUN      ] ServerRemoveOrdersTests.semiFullOrder
[       OK ] ServerRemoveOrdersTests.semiFullOrder (3 ms)
[----------] 2 tests from ServerRemoveOrdersTests (6 ms total)

[----------] 2 tests from ServerBillTableTests
[ RUN      ] ServerBillTableTests.intBill
[       OK ] ServerBillTableTests.intBill (2 ms)
[ RUN      ] ServerBillTableTests.doubleBill
[       OK ] ServerBillTableTests.doubleBill (2 ms)
[----------] 2 tests from ServerBillTableTests (4 ms total)

[----------] 1 test from ServerOpenTablesTest
[ RUN      ] ServerOpenTablesTest.openTables
[       OK ] ServerOpenTablesTest.openTables (3 ms)
[----------] 1 test from ServerOpenTablesTest (3 ms total)

[----------] 3 tests from TableGetterTests
[ RUN      ] TableGetterTests.getSeats
[       OK ] TableGetterTests.getSeats (1 ms)
[ RUN      ] TableGetterTests.getTableNum
[       OK ] TableGetterTests.getTableNum (1 ms)
[ RUN      ] TableGetterTests.getCustomerGroup
[       OK ] TableGetterTests.getCustomerGroup (1 ms)
[----------] 3 tests from TableGetterTests (5 ms total)

[----------] 3 tests from TableSetterTests
[ RUN      ] TableSetterTests.setSeats
[       OK ] TableSetterTests.setSeats (1 ms)
[ RUN      ] TableSetterTests.setTableNum
[       OK ] TableSetterTests.setTableNum (1 ms)
[ RUN      ] TableSetterTests.setCustomerGroup
[       OK ] TableSetterTests.setCustomerGroup (2 ms)
[----------] 3 tests from TableSetterTests (6 ms total)

[----------] 1 test from TableConstructorTests
[ RUN      ] TableConstructorTests.noParameters
[       OK ] TableConstructorTests.noParameters (3 ms)
[----------] 1 test from TableConstructorTests (3 ms total)

[----------] 2 tests from TableLeftoverSeatsTests
[ RUN      ] TableLeftoverSeatsTests.emptyTable
[       OK ] TableLeftoverSeatsTests.emptyTable (2 ms)
[ RUN      ] TableLeftoverSeatsTests.takenTable
[       OK ] TableLeftoverSeatsTests.takenTable (2 ms)
[----------] 2 tests from TableLeftoverSeatsTests (4 ms total)

[----------] 3 tests from TableAvailablityTests
[ RUN      ] TableAvailablityTests.fullyAvailable
[       OK ] TableAvailablityTests.fullyAvailable (2 ms)
[ RUN      ] TableAvailablityTests.partiallyNotAvailable
[       OK ] TableAvailablityTests.partiallyNotAvailable (2 ms)
[ RUN      ] TableAvailablityTests.fullyNotAvailable
[       OK ] TableAvailablityTests.fullyNotAvailable (2 ms)
[----------] 3 tests from TableAvailablityTests (8 ms total)

[----------] 2 tests from TableBillTests
[ RUN      ] TableBillTests.intBill
[       OK ] TableBillTests.intBill (2 ms)
[ RUN      ] TableBillTests.doubleBill
[       OK ] TableBillTests.doubleBill (2 ms)
[----------] 2 tests from TableBillTests (4 ms total)

[----------] 1 test from TableTimeTests
[ RUN      ] TableTimeTests.positiveDuration
[       OK ] TableTimeTests.positiveDuration (1003 ms)
[----------] 1 test from TableTimeTests (1004 ms total)

[----------] Global test environment tear-down
[==========] 69 tests from 35 test suites ran. (1323 ms total)
[  PASSED  ] 69 tests.
==352733== 
==352733== HEAP SUMMARY:
==352733==     in use at exit: 0 bytes in 0 blocks
==352733==   total heap usage: 1,980 allocs, 1,980 frees, 307,567 bytes allocated
==352733== 
==352733== All heap blocks were freed -- no leaks are possible
==352733== 
==352733== For lists of detected and suppressed errors, rerun with: -s
==352733== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
</detals>
