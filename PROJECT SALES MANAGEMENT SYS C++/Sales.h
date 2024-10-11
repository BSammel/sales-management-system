#ifndef SALES_H
#define SALES_H
#include <string>
#include <stdlib.h>
using namespace std;


class Sales
{
    public:
        Sales();
        //function prototyping
        void addItem();
        void allItems();
        void editItem();
        void deleteItem();
        void orderItem();
        void receipt();
        void login();
        void menu();
        void Display();
         int password;
        int options;
        string username;
         int itemID;


    protected:

    private:

};

#endif // SALES_H
