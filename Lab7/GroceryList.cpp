//GroceryList.cpp, 117928226, George Paul Robert. Function defintions
#include <iostream>
#include "GroceryList.h"
#define HST 0.13
#define MAXNUM 5

//getter functions
std::string GroceryList::getName() const{
    return name;
}

int GroceryList::getBarcode() const{
    return barcode;
}

double GroceryList::getTax() const{
    return tax;
}

double GroceryList::getCost() const{
    return cost;
}

//setter functions
bool GroceryList::setName(std::string _name){
    bool retVal = false;
    if(_name != "\n"){
        name = _name;
        retVal = true;
    }
    return retVal;
}

bool GroceryList::setBarcode(int _barcode){
    int count = 0;
    bool retVal = false;
    int temp = _barcode;
    while (temp != 0)
    {
        temp = temp / 10;
        ++count;
    }
    if(count <= 7 && count > 0){
        barcode = _barcode;
        retVal = true;
    }
    return retVal;
}


bool GroceryList::setCost(double _cost){
    bool retVal = false;
    if(_cost >= 0){
        cost = _cost;
        retVal = true;
    }
    return retVal;
}

//finding tax for each item
bool GroceryList::evaluateTax(char taxable){
    bool retval = false;
    if (taxable == 'y'){
        tax = cost * HST;
        retval = true;
    }
    else if(taxable == 'n'){
        tax = 0;
        retval = true;
    }
    else{
        retval = false;
    }
    return retval;
}