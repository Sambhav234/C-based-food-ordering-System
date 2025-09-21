#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <memory>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;



// Helper function to convert string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}


// Structure for MenuItem to hold individual item details
struct MenuItem {
    int sr;
    string name;
    int price;

    // Constructor with member assignment in the body
    MenuItem(int no, string n, int p) {
        sr=no;
        name = n;
        price = p;
    }
};


// Structure for TreeNode (for Meal types like Breakfast, Lunch, etc.)
struct TreeNode {
    string category;
    vector<MenuItem> items;
    vector<TreeNode*> subCategories;

    // Constructor with member assignment in the body
    TreeNode(string cat) {
        category = cat;
    }
};


struct Customer {
    string name;
    int loyaltyPoints;
    vector<string> orderHistory;

    // Default constructor
    Customer() {
        loyaltyPoints = 0;
    }

    // Parameterized constructor
    Customer(string n) {
        name = n;
        loyaltyPoints = 0;
    }
};


// // Hash map for customer management
// unordered_map<string, Customer> customers;

// Function to create sample menu tree for Breakfast, Lunch, and Dinner
TreeNode* createSampleMenuTree() {

    //root node of a tree conataining menu for different restaurants.
    TreeNode* root = new TreeNode("Menu");

    // Indian restaurant menu
    TreeNode* indian = new TreeNode("Indian");

    //it creates tree node for indian breakfast
    TreeNode* indianBreakfast = new TreeNode("Breakfast");
    indianBreakfast->items.push_back(MenuItem(1, "Paratha", 50));
    indianBreakfast->items.push_back(MenuItem(2, "Poha", 40));
    indianBreakfast->items.push_back(MenuItem(3, "Idli", 30));
    indianBreakfast->items.push_back(MenuItem(4, "Dosa", 60));
    indianBreakfast->items.push_back(MenuItem(5, "Upma", 35));
    indian->subCategories.push_back(indianBreakfast);

    //creates lunch node for indian[which is a category].
    TreeNode* indianLunch = new TreeNode("Lunch");
    indianLunch->items.push_back(MenuItem(1, "Biryani", 150));
    indianLunch->items.push_back(MenuItem(2, "Paneer Butter Masala", 120));
    indianLunch->items.push_back(MenuItem(3, "Dal Makhani", 100));
    indianLunch->items.push_back(MenuItem(4, "Chole Bhature", 80));
    indianLunch->items.push_back(MenuItem(5, "Rajma Chawal", 90));
    indian->subCategories.push_back(indianLunch);

    //indian dinner node.
    TreeNode* indianDinner = new TreeNode("Dinner");
    indianDinner->items.push_back(MenuItem(1, "Dal Tadka", 80));
    indianDinner->items.push_back(MenuItem(2, "Roti", 10));
    indianDinner->items.push_back(MenuItem(3, "Butter Chicken", 150));
    indianDinner->items.push_back(MenuItem(4, "Palak Paneer", 120));
    indianDinner->items.push_back(MenuItem(5, "Aloo Gobi", 70));
    indian->subCategories.push_back(indianDinner);

    // Chinese restaurant menu
    TreeNode* chinese = new TreeNode("Chinese");
    TreeNode* chineseBreakfast = new TreeNode("Breakfast");
    chineseBreakfast->items.push_back(MenuItem(1, "Spring Rolls", 60));
    chineseBreakfast->items.push_back(MenuItem(2, "Dim Sum", 80));
    chineseBreakfast->items.push_back(MenuItem(3, "Baozi", 70));
    chineseBreakfast->items.push_back(MenuItem(4, "Congee", 50));
    chineseBreakfast->items.push_back(MenuItem(5, "Jianbing", 40));
    chinese->subCategories.push_back(chineseBreakfast);

    //Lunch node for chonese restaurants.
    TreeNode* chineseLunch = new TreeNode("Lunch");
    chineseLunch->items.push_back(MenuItem(1, "Fried Rice", 130));
    chineseLunch->items.push_back(MenuItem(2, "Manchurian", 100));
    chineseLunch->items.push_back(MenuItem(3, "Kung Pao Chicken", 150));
    chineseLunch->items.push_back(MenuItem(4, "Sweet and Sour Pork", 140));
    chineseLunch->items.push_back(MenuItem(5, "Mapo Tofu", 120));
    chinese->subCategories.push_back(chineseLunch);

    TreeNode* chineseDinner = new TreeNode("Dinner");

    //Dinner node for chinese restaurants which contains category menu items and subcategories

    chineseDinner->items.push_back(MenuItem(1, "Noodles", 120));
    chineseDinner->items.push_back(MenuItem(2, "Sweet and Sour", 150));
    chineseDinner->items.push_back(MenuItem(3, "Peking Duck", 200));
    chineseDinner->items.push_back(MenuItem(4, "Hot Pot", 180));
    chineseDinner->items.push_back(MenuItem(5, "Szechuan Chicken", 160));
    chinese->subCategories.push_back(chineseDinner);

    // Italian restaurant menu
    TreeNode* italian = new TreeNode("Italian");

    //breakfast node for italian restaurants.

    TreeNode* italianBreakfast = new TreeNode("Breakfast");
    italianBreakfast->items.push_back(MenuItem(1, "Pizza", 200));
    italianBreakfast->items.push_back(MenuItem(2, "Frittata", 150));
    italianBreakfast->items.push_back(MenuItem(3, "Bruschetta", 100));
    italianBreakfast->items.push_back(MenuItem(4, "Panini", 120));
    italianBreakfast->items.push_back(MenuItem(5, "Cappuccino", 80));
    italian->subCategories.push_back(italianBreakfast);

    //lunch node for italian restaurants.
    TreeNode* italianLunch = new TreeNode("Lunch");
    italianLunch->items.push_back(MenuItem(1, "Pasta", 180));
    italianLunch->items.push_back(MenuItem(2, "Lasagna", 250));
    italianLunch->items.push_back(MenuItem(3, "Risotto", 220));
    italianLunch->items.push_back(MenuItem(4, "Gnocchi", 200));
    italianLunch->items.push_back(MenuItem(5, "Minestrone", 150));
    italian->subCategories.push_back(italianLunch);

    //Dinner Node for italian restaurants.
    TreeNode* italianDinner = new TreeNode("Dinner");
    italianDinner->items.push_back(MenuItem(1, "Risotto", 220));
    italianDinner->items.push_back(MenuItem(2, "Osso Buco", 300));
    italianDinner->items.push_back(MenuItem(3, "Tiramisu", 180));
    italianDinner->items.push_back(MenuItem(4, "Polenta", 160));
    italianDinner->items.push_back(MenuItem(5, "Branzino", 280));
    italian->subCategories.push_back(italianDinner);

    // Adding restaurant categories
    root->subCategories.push_back(indian);
    root->subCategories.push_back(chinese);
    root->subCategories.push_back(italian);

    return root;
}

// 
string trim(const string& str) {
    int start = 0, end = str.length() - 1;

    // Find the first non-space character
    while (start <= end && str[start] == ' ') {
        start++;
    }

    // Find the last non-space character
    while (end >= start && str[end] == ' ') {
        end--;
    }

    // Return the trimmed substring
    return str.substr(start, end - start + 1);
}


// Order class for managing individual orders using linked list
class Order {
public:
    string item;
    int quantity;
    int totalPrice;
    string restaurant;
    Order* next;

    // Constructor
    Order(string i, int q, int t, string r) {
        item = i;
        quantity = q;
        totalPrice = t;
        restaurant = r;
        next = nullptr;
    }
};


// Function to display menu based on selected restaurant and meal time
void displayMenu(TreeNode* node) {
    if (!node) return;
    cout << node->category << endl;
    for (const auto& item : node->items) {
        cout << item.sr<< ". " << item.name << " - " << item.price << endl;
    }
    for (TreeNode* subCat : node->subCategories) {
        displayMenu(subCat);
    }
}

// Function to take and process the order
void addOrder(Order*& head, const string& itemName, int quantity, int price, string restaurant) {
    int total_price = quantity * price;
    auto newOrder = new Order(itemName, quantity, total_price, restaurant);
    newOrder->next = head;
    head = newOrder;
}

// Function to display orders and calculate bill
void displayOrders(Order* head) {
    int grandTotal = 0;
    cout << "\n--- Your Orders ---\n";
    while (head != nullptr) {
        cout << head->quantity << " x " << head->item << " (Restaurant: " << head->restaurant << ") = Rs. " << head->totalPrice << "\n";
        grandTotal += head->totalPrice;
        head = head->next;
    }
    cout << "Total Bill: Rs. " << grandTotal << "\n";
}

// Function to generate final bill with payment method
void generateBill(Order* head, Customer& customer) {
    int grandTotal = 0;
    cout << "\n--- Final Bill ---\n";
    while (head != nullptr) {
        cout << head->quantity << " x " << head->item << " (Restaurant: " << head->restaurant << ") = Rs. " << head->totalPrice << "\n";
        grandTotal += head->totalPrice;
        head = head->next;
    }
    // Apply discounts or loyalty points if available
    if (customer.loyaltyPoints >= 100) {
        cout << "Loyalty Discount Applied!\n";
        grandTotal *= 0.9; // 10% discount
    }
    cout << "Total Bill with discount: Rs. " << grandTotal << "\n";
    L :
    cout << "\nChoose Payment Method [integer](1. Card / 2. Cash): ";
    int paymentChoice;
    cin >> paymentChoice;
    if (paymentChoice == 1) {
        cout << "Payment successful via card. Thank you for your purchase!\n";
    } else if(paymentChoice == 2){
        cout << "Payment successful via cash. Thank you for your purchase!\n";
    }else{
        cout << "Invalid choice. Please try again.\n";
        goto L;
    }
}

// Function to undo the last order
void undoLastOrder(Order*& head, stack<Order*>& orderStack)

 {
    if (orderStack.empty()) 
    {
        cout << "No orders to undo.\n";
        return;
    }

    Order* lastOrder = orderStack.top();
    orderStack.pop();

    if (head == lastOrder) 
    {
        head = head->next;
    } 
    else 
    {
        Order* temp = head;
        while (temp->next != lastOrder)
        {
            temp = temp->next;
        }
        temp->next = lastOrder->next;
    }
    delete lastOrder;
    cout << "Last order undone.\n";
}


// Function to display available restaurants for a given cuisine
void displayRestaurantNames(vector<string>& restaurants)
{
    for (int i = 0; i < restaurants.size(); ++i) 
    {
        cout << i + 1 << ". " << restaurants[i] << endl;
    }
}



void DecorateTopic()
{
    system("cls");
    cout << endl;
    cout << "\t\t\t  ########################################################################" << endl;
    cout << "\t\t\t  #                                                                      #" << endl;
    cout << "\t\t\t  #              WELCOME TO THE FOOD ORDERING SYSTEM                     #" << endl;
    cout << "\t\t\t  #                                                                      #" << endl;
    cout << "\t\t\t  ########################################################################" << endl;
    cout << endl;

    cout << endl;
    cout << "\t\t\t  ----------------------------------------------------------------------" << endl;
    cout << "\t\t\t  |  Choose from a wide variety of cuisines and place your order now!  |" << endl;
    cout << "\t\t\t  ----------------------------------------------------------------------" << endl;
    cout << endl;
}




int main() {

        DecorateTopic();

    string customerName;


    cout << "Enter your name: ";
    getline(cin, customerName);

    cout << "Welcome, " << customerName << "!\n";

    // Create sample menu tree
    TreeNode* menuRoot = createSampleMenuTree();

    Order* orderList = nullptr;
    stack<Order*> orderStack;

    // Restaurant lists for each cuisine
    vector<string> indianRestaurants = {"Tandoor Delight", "Spicy Indian Hub", "Curry Point"};
    vector<string> chineseRestaurants = {"Golden Dragon", "Szechuan Palace", "Mandarin Bistro"};
    vector<string> italianRestaurants = {"La Bella Italia", "Pasta Paradise", "Romeo's Pizzeria"};

    char choice;
    do 
    {

        n:
        cout << "\nChoose a Cuisine:\n1. Indian\n2. Chinese\n3. Italian\nEnter choice: \n";

        string cuisineChoice;
        cin >> cuisineChoice;
        cin.ignore();


        string selectedCuisine;



        vector<string> selectedRestaurants;
        if (cuisineChoice == "1" || cuisineChoice == "indian") {
            selectedCuisine = "Indian";
            selectedRestaurants = indianRestaurants;
        } else if (cuisineChoice == "2"|| cuisineChoice == "chinese") {
            selectedCuisine = "Chinese";
            selectedRestaurants = chineseRestaurants;
        } else if (cuisineChoice == "3"|| cuisineChoice == "italian") {
            selectedCuisine = "Italian";
            selectedRestaurants = italianRestaurants;
        }else{
            cout << "Invalid choice. Please choose a valid cuisine.\n";
            goto n;
        }



        // Display the list of restaurants
        cout << "\nAvailable " << selectedCuisine << " Restaurants:\n";

        displayRestaurantNames(selectedRestaurants);

        cout << "Enter your choice (1-" << selectedRestaurants.size() << "): ";

        int restaurantChoice;
        cin >> restaurantChoice;
        cin.ignore();



        if (restaurantChoice < 1 || restaurantChoice > selectedRestaurants.size())
        {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        string selectedRestaurant = selectedRestaurants[restaurantChoice - 1];
        cout << "\nWelcome to " << selectedRestaurant << "!\n";

        cout << "Choose Meal (1. Breakfast / 2. Lunch / 3. Dinner): ";

        int mealChoice;
        cin >> mealChoice;
        cin.ignore();




        // Find selected restaurant and meal
        TreeNode* selectedRestaurantNode = nullptr;

        for (auto& restaurant : menuRoot->subCategories)
        {
            if (toLowerCase(restaurant->category) == toLowerCase(selectedCuisine)) 
            {
                selectedRestaurantNode = restaurant;
                break;
            }
        }




        TreeNode* selectedMealNode = nullptr;

        if (selectedRestaurantNode) 
        {
            for (auto& meal : selectedRestaurantNode->subCategories) 
            {
                if ((mealChoice == 1 && toLowerCase(meal->category) == "breakfast") ||
                    (mealChoice == 2 && toLowerCase(meal->category) == "lunch") ||
                    (mealChoice == 3 && toLowerCase(meal->category) == "dinner")) 
                {
                    selectedMealNode = meal;
                    break;
                }
            }
        }





        // Display menu and take orders
        if (selectedMealNode) 
        {
            displayMenu(selectedMealNode);
        m:
            cout << "\nEnter item name to order: ";

            string itemName;
            getline(cin, itemName);

           string itemN = trim(itemName);




            bool itemFound = false;
            //items mein se selected meal ke items ko displac krado.
            for (const auto& item : selectedMealNode->items)
            {
                if (toLowerCase(item.name) == toLowerCase(itemN)|| stoi(itemN) == item.sr) 
                {
                    itemFound = true;
                    itemN=item.name;
                    cout << "Enter quantity for " << itemN << ": ";
                    int quantity;
                    cin >> quantity;
                    cin.ignore();
                    addOrder(orderList, itemN, quantity, item.price, selectedRestaurant);
                    orderStack.push(orderList);
                    break;
                }
            }



            if (!itemFound) 
            {
                cout << "Item not found. Try again.\n";
                goto m;
            }
            
        }



        cout << "\nWould you like to order anything more? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');




    // Option to undo the last order like if the user has ordered something wrong he can undo and replace the new order.
    cout << "\nWould you like to undo the last order? (Y/N): ";
    cin >> choice;
    cin.ignore();




    //if something wrong is ordered , you can undo the whole order and replace the new order.
    if (choice == 'Y' || choice == 'y') 
    {
        undoLastOrder(orderList, orderStack);
    }



    // Generate bill and complete payment
    displayOrders(orderList);


    //it will generate the total bill for the food items selected.
    // generateBill(orderList, customers[customerName]);

    cout << "\nThank you for using our Food Ordering System!\n";

    return 0;
}