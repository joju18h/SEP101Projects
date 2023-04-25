//GroceryListMain.cpp, George Paul Robert, 117928226
#include <iostream>
#include <iomanip>
#include "GroceryList.h"

using namespace std;

int main()
{
    bool ret = false;
    int items = 0, barcode = 0;
    string name = "\0";
    double cost = 0.00, runningTotal = 0.00, totalTax = 0.0, sumTotal = 0.0;
    char ch; //for yes or no input

    do{
        cout << "Enter the number of grocery items: ";
        //checking if item is an integer
        if(cin >> items){
            if(items <= 5 && items > 0){
                ret = true;
            }
            else{
                cout << "Invalid number of items" << endl;
            }
        }
        else{
            cout << "Invalid Input" << endl;
            //clear buffer and ignore the previous input
            cin.clear();
            cin.ignore(123, '\n');
        }
    } while (ret == false);



    GroceryList list[items];

    for (int i = 0; i < items; ++i){
        ret = false;
        do{
            cout << "Enter the name of the grocery item: ";
            fflush(stdin); //clears input buffer
            getline(cin, name); // for inputing more than one string
            ret = list[i].setName(name);
            if(ret == false)
                cout << "Invalid name";
        } while (ret == false);
        ret = false;
        do{
            cout << "Enter the barcode of the grocery item: ";
            fflush(stdin);
            if(cin >> barcode){
                ret = list[i].setBarcode(barcode);
                if(ret == false){
                    cout << "Invalid barcode" << endl;
                }
            }
            else{
                cout << "Invalid barcode" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
        } while (ret == false);
        ret = false;
        do{
            cout << "Enter the cost of the grocery item: $";
            fflush(stdin);
            if(cin >> cost){
                ret = list[i].setCost(cost);
                if(ret == false){
                    cout << "Invalid cost" << endl;
                }
            }
            else{
                cout << "Invalid cost" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
        } while (ret == false);
        ret = false;
        do{
            cout << "Is the item taxable? [Y/N] ";
            fflush(stdin);
            cin >> ch;
            ch = tolower(ch);
            if (ch == 'y' || ch == 'n'){
                ret = list[i].evaluateTax(ch);
            }
            else{
                cout << "Invalid entry"<<endl;
            }
        } while (ret == false);
        cout << endl;
    }

    for (int i = 0; i < items; i++){
        cout.setf(ios::left); //left justified
        cout.setf(ios::fixed);
        cout.precision(2); //2 decimal places
        cout << "name: " << setw(20) << list[i].getName() << " cost: $" << list[i].getCost() << " tax: $" << list[i].getTax() << endl;
    }

    cout << "----------------------------" << endl;

    for (int i = 0; i < items; i++){
        runningTotal += list[i].getCost();
        totalTax += list[i].getTax();
    }

    sumTotal = runningTotal + totalTax;

    cout << "Subtotal: $" << runningTotal << endl;
    cout << "Taxes : $" << totalTax << endl;
    cout << "Total: $" << sumTotal << endl;
}