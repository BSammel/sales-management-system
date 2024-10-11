#include "Sales.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
Sales::Sales()
{
    //ctor
}

const int MAX_ITEMS= 1000;
const int MAX_PRODUCTS = 1000;
const int MAX_ORDERS = 1000;

struct Items {
    int id;
    string name;
    int price;
    int itemid;
};

struct Product {
    int id;
    std::string name;
    double price;
    int categoryId;
};

struct Order {
    int id;
    int itemId;
    int amount;
};

Items items[MAX_ITEMS];
int itemCount = 0;

Product products[MAX_PRODUCTS];
int productCount = 0;

Order orders[MAX_ORDERS];
int orderCount = 0;

void Sales::Display()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"|WELCOME TO LINX' SALES MANAGEMENT SYSTEM|"<<endl;
    cout<<"------------------------------------------"<<endl;
}

void Sales::login()//enables the user to login
{
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    cin>>password;
}

void Sales::menu()//displays the menu to the user
{
    cout<<"*=*=*=*=*=*=*=*=*=*=*=*"<<endl;
    cout<<"*  1. Add an item     *"<<endl;
    cout<<"*  2.View all items   *"<<endl;
    cout<<"*  3. Edit an item    *"<<endl;
    cout<<"*  4. Delete an item  *"<<endl;
    cout<<"*  5. Make an order   *"<<endl;
    cout<<"*  6. Receipt         *"<<endl;
    cout<<"*  7. Exit            *"<<endl;
    cout<<"*=*=*=*=*=*=*=*=*=*=*=*"<<endl;
    cout<<" Choose your preferred option(1-7): ";
    cin>>options;
}
void Sales::addItem()
{

    if (itemCount < MAX_ITEMS)
    {
        cout << "Enter the name of the new item: ";
        string itemName;
        cin.ignore();
        getline(cin, itemName);

        double Price;
        cout << "Enter the price of the new item:$ ";
        cin>>Price;


       items[itemCount].id = itemCount + 1;
        items[itemCount].name = itemName;
       items[itemCount].price = Price;
        itemCount++;

        cout << "New item added successfully."<<endl;
    }
        else
            {
              cout << "Maximum category limit reached. Cannot add more categories.\n";
           }
}
void Sales::allItems()
{
     if (itemCount == 0) {
        cout << "No item found."<<endl;
    } else {
       cout << "Items:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << "- Item " << items[i].id << ": " << items[i].name <<" is $"<<items[i].price<< endl;;
        }
    }
}
void Sales::editItem()
{

    if (itemCount == 0) {
        cout << "No   item found. Cannot edit.\n";
        return;
    }


   cout << "Enter the ID of the item to edit: ";
    cin >> itemID;

    for (int i = 0; i < itemCount; ++i) {
        if (items[i].id == itemID) {
            cout << "Enter the new name for the item: ";
            cin.ignore();
            getline(cin, items[i].name);
            cout << "Enter the price for the item: ";
            cin.ignore();
            getline(cin, items[i].price);
            cout << "Item updated successfully.\n";
            return;
        }
    }

   cout << "Item with ID " << itemID << " not found.\n";
}
void Sales::deleteItem()
{

    if (itemCount == 0) {
        cout << "No items found. Cannot delete.\n";
        return;
    }


    cout << "Enter the ID of the item to delete: ";
    cin >> itemID;

    for (int i = 0; i < itemCount; ++i) {
        if (items[i].id == itemID) {
            // Remove the category by shifting elements to the left
            for (int j = i; j < itemCount - 1; ++j) {
                items[j] = items[j + 1];
            }
           itemCount--;
            cout << "Item deleted successfully.\n";
            return;
        }
    }

    cout << "Item with ID " << itemID<< " not found.\n";
}

void Sales::orderItem()
{
     if (itemCount == 0) {
        cout << "No items found. Cannot create an order.\n";
        return;
    }

    int itemId;
    std::cout << "Enter the ID of the item to order: ";
    std::cin >> itemId;

    int itemIndex = -1;
    for (int i = 0; i < itemCount; ++i) {
        if (items[i].id == itemId) {
           itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        std::cout << "Item with ID " << itemId << " not found.\n";
        return;
    }

    int amount;
    cout << "Enter the quantity to order: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid quantity. Order not created."<<endl;
        return;
    }

    if (orderCount < MAX_ORDERS) {
        orders[orderCount].id = orderCount + 1;
        orders[orderCount].itemId = itemId;
        orders[orderCount].amount = amount;
        orderCount++;

       cout << "Order created successfully.\n";
    } else {
        cout << "Maximum order limit reached. Cannot create more orders."<<endl;
    }
}

void Sales::receipt()
{
    const int orderID=0;
    for (int i = 0; i < orderCount; ++i) {
        if (orders[i].id == orderID) {
            int itemId = orders[i].itemId;
            int amount = orders[i].amount;
            double totalPrice = items[itemId - 1].price * amount;
            string itemName = items[itemId - 1].name;

            cout << "Receipt for Order ID " << orderID << ":\n";
            cout << "--------------------------------\n";
            cout << "Product: " << itemName << "\n";
            cout << "Quantity: " << amount << "\n";
            cout << "Total Price: GHS" << totalPrice << "\n";
            cout << "--------------------------------\n";
            return;
        }
    }

    cout << "Order with ID " << orderID << " not found.\n";
}
