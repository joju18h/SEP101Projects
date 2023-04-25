//tempMonitor.c By: George Paul Robert, ID: 117928226

#include <stdio.h>

#define DAYS 4 //The number of days for which the temperatures are to be monitored

int main() {

    int highTemp[DAYS], lowTemp[DAYS], indexHighestTemp, indexLowestTemp; //declaring arrays to store the high & low temperatures as well as highest and lowest temperature's index
    const int highestPossibleTemp = 40; //temperature limits
    const int lowestPossibleTemp = -40;
    int highestTemp = lowestPossibleTemp; //initialisation of variables to store highest and lowest temperatures
    int lowestTemp = highestPossibleTemp;
    int validEntry = 0, totalHighTemp = 0, totalLowTemp = 0, totalTemp = 0, i; //valid entry being the flag. the other's to store sums of highs, lows and overall respectively
   

    printf("---=== SEP Temperature Analyzer ===--- \n");

    for(i = 0; i < DAYS; ++i) {
        do { //do while loop for validation of the values
            printf("Enter the high value for day %d : \n", i + 1 ); //user input prompts for high and low temperatures 
            scanf("%d", &highTemp[i]);
            printf("Enter the low value for day %d : \n", i + 1 );
            scanf("%d", &lowTemp[i]);
            if(highTemp[i] < lowTemp[i] || highTemp[i] > highestPossibleTemp || lowTemp[i] < lowestPossibleTemp) { //checking if the values are valid
                validEntry = 0;
                printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low. \n");

            }
            else{
                validEntry = 1; 
            }
        } while (validEntry == 0);

        totalHighTemp += highTemp[i];
        totalLowTemp += lowTemp[i];
        totalTemp = totalTemp + (highTemp[i] + lowTemp[i]); //sum of all the temperatures over the 4 days

        if(highTemp[i] > highestTemp){
            highestTemp = highTemp[i]; //keeps checking the entered temperature to the previously stored highest one to find the highest
            indexHighestTemp = i; //sets the index to the current element's index
        }
        if(lowTemp[i] < lowestTemp){
            lowestTemp = lowTemp[i]; //keeps checking the entered temperature to the previously stored lowest one to find the lowest
            indexLowestTemp = i;
        }

    }

/* finding the average highs, lows and overall temperatures.
Type casting to float is used to preserve the digits after the decimal */

float avgHighTemp = (float)totalHighTemp / DAYS; 
float avgLowTemp = (float)totalLowTemp / DAYS;
float avgTotalTemp = (float)totalTemp / (DAYS*2);

//to print each element of both the arrays containing the high and low temperatures

printf("The high temperatures were: ");
for(i = 0; i < DAYS; ++i) {
    printf("%d ", highTemp[i]);
}

printf("\nThe low temperatures were: ");
for(i = 0; i < DAYS; ++i) {
    printf("%d ", lowTemp[i]);
}

printf("\nThe average LOW temperature was: %.2f \n", avgLowTemp);
printf("The average HIGH temperature was: %.2f \n", avgHighTemp);
printf("The average temperature was: %.2f \n", avgTotalTemp);
printf("The highest temperature was %d, on day %d \n", highestTemp, indexHighestTemp + 1);
printf("The lowest temperature was %d, on day %d", lowestTemp, indexLowestTemp + 1);

return 0;

}