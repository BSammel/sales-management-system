//PROJECT ON SALES MANAGEMENT SYSTEM
//SAMMEL BEMPONG
//SRI.41.008.057.22
//CE

#include <iostream>
#include "Sales.h"
#include <stdlib.h>
using namespace std;


int main()
{
    system("color 2d");//changes the color of the program at runtime
    Sales sales;//creating an object of the class
    sales.Display();
    sales.login();
    cout<<endl;
    if(sales.password==2023 && sales.username=="username")
        {
           do
           {
                sales.menu();
                cout<<endl;
              switch(sales.options)
               {
                  case 1:
                     sales.addItem();//calls the function additem
                      break;

                     case 2:
                        sales.allItems();//calls the function allitem
                         break;

                         case 3:
                            sales.editItem();//calls the function edititem
                             break;

                                case 4:
                                   sales.deleteItem();//calls the function deleteitem
                                    break;

                          case 5:
                               sales.orderItem();//calls the function order item
                                break;

                     case 6:
                          int orderid;
                          cout<<"Enter the id of the order to view the receipt"<<endl;
                          cin>>orderid;
                            sales.receipt();//Displays the receipt to the user
                            break;

                case 7:
                    cout<<"Exiting the program"<<endl;//exits the program

            default:
                cout<<"Invalid option"<<endl;

        }
               cout<<endl;//moves the cursor to the next line
           }while(sales.options<7);
        }
        else
        {
            cout<<"Invalid username or password";
        }
    return 0;
}
