//From George Paul Robert, ID 117928226


#include <stdio.h>
int main()
{
    float cost_item1, cost_item2, cost_item3; //declaration of the variables to store the item costs

    printf("Enter the cost of item 1: $");    //prompt for user input of the costs
    scanf("%f", &cost_item1);                 //input of the costs

    printf("Enter the cost of item 2: $");    
    scanf("%f", &cost_item2);

    printf("Enter the cost of item 3: $");
    scanf("%f", &cost_item3);

    float total_cost = cost_item1 + cost_item2 + cost_item3; //total cost of all the items
    printf("The total cost is: %.2f \n", total_cost); //output of the total costs

    int remainder = total_cost * 100 + 0.0001; /*to remove the decimal and then proceed to seperate the dollars
                                                 quarters, dimes and so on */
    

    int num_Dollars, num_Quarters, num_Dimes, num_Nickels, num_Pennies; //declaring the variables to store the value of dollarsquarters, dimes and so on

    num_Dollars = remainder / 100;      //gets the dollar value
    remainder = remainder % 100;        //seprates the rest of the cents

    num_Quarters =  remainder / 25;     //gets the number of quarters
    remainder = remainder % 25;         //seprates the rest to find dimes

    num_Dimes =  remainder / 10;        //gets the number of dimes
    remainder = remainder % 10;         //seperation again

    num_Nickels = remainder / 5;        // finds number of nickels
    remainder  = remainder % 5;         //  remaining digits gives the number of pennies

    num_Pennies = remainder;

    printf("You used %d dollars, %d quarters, %d dimes, %d nickels, %d pennies.", num_Dollars, num_Quarters, num_Dimes, num_Nickels, num_Pennies); //prints in the required format

    return 0;
}