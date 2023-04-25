//lab5Main.c - main function

//George Paul Robert
//grobert1@myseneca.ca
//117928226


#include <stdio.h>
#include <string.h>
#include "lab5.h"

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

int main(){
    struct Company company[NUM_COM];
    initializeInfo(company);

    for (int i = 0; i < NUM_COM; ++i)
    {
        initializeInfo(&company[i]);
    }

    for (int i = 0; i < NUM_COM; ++i) //user prompt
    {
        printf("Enter the company name: ");
        scanf("%[^\n]s", company[i].companyName); //[^/n] used to read the whole line including whitespace
        cleanInputBuffer();//input buffer that contains /n newline is cleared by calling this function
        printf("Enter %s's stock symbol: ", company[i].companyName);
        scanf("%[^\n]s", company[i].stockSymbol);
        cleanInputBuffer();
        printf("Enter %s's current stock price: ", company[i].companyName);
        scanf("%f", &company[i].sharePrice);
        printf("Enter %s's annual dividend per share: ", company[i].companyName);
        scanf("%f", &company[i].annualDividend);
        cleanInputBuffer();

        printf("\n");

        company[i].dividendYield = calcDividendYield(&company[i]);
        calcValuation(&company[i]);
    }

    printf("COMPANY      SYMBOL            PRICE                 DIV             YIELD         VALUATION \n"); //printing the values of the company
    for (int i = 0; i < NUM_COM; ++i)
    {
        printf(" %s  %15s  %15.2f    %15.3f    %15.3f    %15s \n", company[i].companyName, company[i].stockSymbol, company[i].sharePrice, company[i].annualDividend, company[i].dividendYield, company[i].companyValue);
    }
    return 0;
}