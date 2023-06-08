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
* Input - As the manager, the user will be able to enter a name for the restaurant, add items to the menu (item type, item name, and item price), and change the price of items on the menu. As the server, the user will be able to enter a table number to seat a group of customers, take orders, serve customers, and collect payments. As the chef, the user will be able to receive a list of pending orders, prepare orders, and mark them as completed.
* Output - The program will display various forms of output as the user enters information into the game. As the manager, the user will be able to view the full restaurant menu once they have added items to it. As the server, the user can see a visual display of the floor plan representing seats at the restaurant. As the chef, the user can view what items have been ordered by the customer. At the end of the game, the user can view the overall rating and balance of the restaurant.

## Class Diagram
![Final Restaurant UML Diagram](https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/129975596/edfeff0c-7958-495c-b163-2f491221960e)

* The Restaurant class holds the major functionality to run the game that the user will see in the terminal. It includes a function to set the name of the restaurant. The setBalance() function takes the customer’s bill (based on prices set up in the menu) and adds that to the total balance of the restaurant. The setRating() function sets the restaurant’s overall rating based on a random generator in the Customer class. The floorplan is displayed to the terminal by a 2d array of pointers to Table objects developed in createFloorPlan(). The method for this function is protected to allow all employees to have access to it, especially the server. The purpose of createFloorPlan() is to allow the server to seat customers at an open table and keep track of which tables are occupied. Each table is given a number that is used to keep track of which orders are from which group of customers. Most importantly, simulateRestaurant() runs the user through each cycle of the game through a series of inputs and outputs as they transition from manager, to server, to chef, and then back to server. This is where the user will be able to add items to the menu as the manager, seat customers at a table as the server, send orders to the chef, and serve customers with their completed order. The simulateRestaurant() function ends with an evaluation of the restaurant’s balance and rating, which if passed, allows the user to play the game again.
 
* The Table class is utilized by the Restaurant class and the Server class to store information about table availability and customer groups at a specific table. The setCustomerGroup() function is responsible for maintaining details about a customer group at a specific table. The getAvailability() function checks the number of available seats at a table and returns that information to the server to seat their customers. The Server class further implements the functionality of this class when taking the customers’ orders and calculating the bill. Overall, this class is used for organizational purposes for other classes.
 
* The Customer class is the main competition the user faces in the game. It is implemented as a robot with randomly generated values and reviews, mocking how a real customer would behave in a restaurant. The generateRandomOrder() function randomly generates orders from the menu and assigns them to each customer in the group. The generateRating() function produces a randomly generated review (from 1 - 5) for the restaurant. The setRandomPartySize() function is responsible for creating a group with a random number of customers, while the setRandomNames() function randomly assigns each customer of the group with a name from a list. The Customer class will also be utilized by the Table class in terms of group orders and group placement. Overall, the Customer class is a completely randomized, behind-the-scenes development where the user is in charge of pleasing their customers through the means of the restaurant’s employees.
 
* The Employee class serves as an abstract base class for the Server, Chef, and Manager classes. This class’s primary purpose is to provide the functionality to set the name of each employee. The printCharacterDetails() function is virtual so that it can be overridden by the derived classes, since the server, chef, and manager will each have their own information.
 
* The Manager class is responsible for the beginning of the game involving the setup of the restaurant. The menuAdd() function is used by the manager to add foods to the menu and set their prices. In subsequent cycles of the game, the changeMenuPrice() function is called if the manager wishes to alter any previously set prices of items on the menu. Once the manager has added all items to the menu that the user pleases, viewFullMenu() will display the full restaurant menu. The Manager class inherits from the Employee class to allow an object of Manager to set their own name.

* The MenuItem class works hand-in-hand with the Manager class to store some of the implementation of adding items to the menu in the form of a linked list. The parameterized MenuItem() constructor takes user input regarding the menu number, food type, food item, and food price and stores that information together as a node in the linked list. The printMenuItem() function is used to print an individual node (or menu item) from the menu list.

* The Order class stores the randomly generated orders from the Customer class using a list. The viewAllOrders() function can be used by the Chef class to see what has been ordered by the customers at a table. The removeAllOrders() function deletes each order from the list so that no previous orders remain in the list in future cycles of the game.

* The Server class includes functionality to seat customers and take their order. In order to seat a customer, the server has access to the Restaurant’s floorplan where they can select a suitable table to place the customer at. This means the Server class will aggregate the group size from the Customer class and make changes to the Restaurant class. To give the orders to their customers, the server inputs the correct order numbers to replicate serving their customers. The Server class inherits from the Employee class to allow an object of Server to set their own name.
 
* The Chef class is responsible for using the list of orders from the table to “make orders”. To view the orders list, the Chef class has access to a Table object in the Restaurant class’s floor plan. Before making each set of orders (appetizers, main course, and dessert), the chef will be given a list of tasks to complete and must type out the tasks in the correct order to proceed. 
To make the order itself, the chef will type what is prompted to the screen exactly as stated to mimic cooking the order. The Chef class inherits from the Employee class to allow an object of Chef to set their own name.

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
 Clone this repository using the following commands in the terminal:
 ```sh
$ git clone https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035.git
$ cd final-project-skamm006-sbhan020-schau062-vsing035
$ cmake .
$ make
```
Two executables will be created (test & play). Run the play executable to play the game:
 ```sh
$ ./play
```
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
