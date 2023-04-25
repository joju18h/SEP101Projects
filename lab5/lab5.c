//lab5.c - function defintions for lab5Main.c

//George Paul Robert
//grobert1@myseneca.ca
//117928226

/*
struct Company{  //struct Company that holds the company info
    char companyName[MAXSTR];
    char stockSymbol[MAXSTR];
    char companyValue[MAXSTR];
    float sharePrice;
    float annualDividend;
    float dividendYield;
};
*/

#include "lab5.h"
#include <stdio.h>
#include <string.h> //import string.h library to use string functions

#define VALUE 5 //used for evaluating valuation

void initializeInfo(struct Company *company){ //initialising  all the values to zero
    company->companyName[0] = '\0';
    company->stockSymbol[0] = '\0';
    company->companyValue[0] = '\0';
    company->sharePrice = 0;
    company->annualDividend = 0;
    company->dividendYield = 0;
}

float calcDividendYield(struct Company *company){ //for calculating dividend yield
    float yield;

    if (company->annualDividend > 0 && company->sharePrice > 0)
    {
        yield = 100 * (company->annualDividend / company->sharePrice);
    }
    return yield;
}

void calcValuation(struct Company *company){ //valuation of the company is calculated
    if(company->dividendYield > VALUE){
        strcpy(company->companyValue, "Under Valued"); //the string is stored inside companyValue  using strcpy
    }
    else if(company->dividendYield < VALUE){
        strcpy(company->companyValue, "Over Valued");
    }
    else{
        strcpy(company->companyValue, "Fully Valued");
    }
}

void cleanInputBuffer(void){
    char ch;
    do{
        ch = getchar();

    } while (ch != '\n');

}