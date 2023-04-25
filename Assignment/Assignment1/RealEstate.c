//RealEstate.c, Group - C. Function defintions.  everyone worked on their own properties' fucntions. Combined by George
#include <stdio.h>
#include "RealEstate.h"

//mothly earnings for each type each item
void calcMonthlyEarnings(struct Company *company, int type){
    // for apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++) {
            //validation
            if (company->apt[i].monthlyRent >= 0 && company->apt[i].monthlyCondoFees >= 0){
                company->apt[i].monthlyEarnings = company->apt[i].monthlyRent - company->apt[i].monthlyCondoFees;
            }
        }
    }
    //for townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            if (company->th[i].monthlyRent >= 0 && company->th[i].monthlyCondoFees >= 0 && company->th[i].monthlyPropertyTax >= 0 && company->th[i].monthlyUtilities >= 0){
                company->th[i].monthlyEarnings = company->th[i].monthlyRent - company->th[i].monthlyCondoFees - company->th[i].monthlyPropertyTax - company->th[i].monthlyUtilities;
            }
        }
    }
    //for semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            if(company->sdh[i].monthlyRent >= 0 && company->sdh[i].MonthlyPropertyTax >= 0 && company->sdh[i].monthlyUtilities >= 0){
                company->sdh[i].monthlyEarnings = company->sdh[i].monthlyRent - company->sdh[i].MonthlyPropertyTax - company->sdh[i].monthlyUtilities;
            }
        }
    }
}

//sum of monthly earnings of all items of a type
void sumMonthlyEarnings(struct Company *company, int type){
    // apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++){
            company->aptMonthlyEarning += company->apt[i].monthlyEarnings;
        }
    }
    // townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            company->thMonthlyEarning += company->th[i].monthlyEarnings;
        }
    }
    // semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            company->sdhMonthlyEarning += company->sdh[i].monthlyEarnings;
        }
    }
}

//roi of each item of each type
void calcRoi(struct Company *company, int type){
    // for apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++) {
            if (company->apt[i].purchasePrice > 0){
                company->apt[i].roi = 100 * 12 * (company->apt[i].monthlyEarnings / company->apt[i].purchasePrice);
            }
        }
    }
    //for townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            if (company->th[i].purchasePrice > 0){
                company->th[i].roi = 100 * 12 * (company->th[i].monthlyEarnings / company->th[i].purchasePrice);
            }
        }
    }
    //for semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            if(company->sdh[i].purchasePrice > 0){
                company->sdh[i].roi = 100 * 12 * (company->sdh[i].monthlyEarnings / company->sdh[i].purchasePrice);
            }
        }
    }
}

//sum roi of each type
void calcSumRoi(struct Company *company,int type){
    float sumPurchasePrice = 0.0;
    // apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++){
            sumPurchasePrice += company->apt[i].purchasePrice; 
        }
        company->aptRoi = 100 * 12 * (company->aptMonthlyEarning / sumPurchasePrice);
    }
    // townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            sumPurchasePrice += company->th[i].purchasePrice;
        }
        company->thRoi = 100 * 12 * (company->thMonthlyEarning / sumPurchasePrice);
    }
    // semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            sumPurchasePrice += company->sdh[i].purchasePrice;
        }
        company->sdhRoi = 100 * 12 * (company->sdhMonthlyEarning / sumPurchasePrice);
    }
}

//current value of per item
void calcCurrentValue(struct Company *company, int type){
    // for apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++) {
            company->apt[i].currentValue = 12 * (company->apt[i].monthlyEarnings / INTEREST_RATE);
            //total value for appartments
            company->aptValue += company->apt[i].currentValue;
        }
    }
    //for townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
           company->th[i].currentValue = 12 * (company->th[i].monthlyEarnings / INTEREST_RATE);
           //total value for townhouses
           company->thValue += company->th[i].currentValue;
        }
    }
    //for semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            company->sdh[i].currentValue = 12 * (company->sdh[i].monthlyEarnings / INTEREST_RATE);
            //total value for sdh
            company->sdhValue += company->sdh[i].currentValue;
        }
    }
}

//capitalGain per item
void calcCapitalGain(struct Company *company, int type){
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++) {
            company->apt[i].capitalGains = company->apt[i].currentValue - company->apt[i].purchasePrice;
            //capital gains for the appartment type
            company->aptCapitalGains += company->apt[i].capitalGains;
        }
    }
    //for townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            company->th[i].capitalGains = company->th[i].currentValue - company->th[i].purchasePrice;
            //capital gains for the townhouse type
            company->thCapitalGains += company->th[i].capitalGains;
        }
    }
    //for semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            company->sdh[i].capitalGains = company->sdh[i].currentValue - company->sdh[i].purchasePrice;
            //capital gains for the sdh type
            company->sdhCapitalGains += company->sdh[i].capitalGains;
        }
    }
}

//capitalGainrate per item
void calcCapitalRate(struct Company *company, int type){
    // for apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++) {
            if (company->apt[i].years > 0.0){
                company->apt[i].capitalGainRate = company->apt[i].capitalGains / company->apt[i].years;
                //capital gains rate for the appartment type
                company->aptGainRate += company->apt[i].capitalGainRate;
            }
        }
    }
    //for townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            if (company->th[i].years > 0.0){
                company->th[i].capitalGainRate = company->th[i].capitalGains / company->th[i].years;
                //capital gains rate for the townhouse type
                company->thGainRate += company->th[i].capitalGainRate;
            }
        }
    }
    //for semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            if (company->sdh[i].years > 0.0){
                company->sdh[i].capitalGainRate = company->sdh[i].capitalGains / company->sdh[i].years;
                //capital gains rate for the sdh type
                company->sdhGainRate += company->sdh[i].capitalGainRate;
            }
        }
    }
}

//performanceIndex per category
void calcPerformanceIndex(struct Company *company, int type){
    // apartment
    if(type == 1){
        company->aptPerformance = company->aptRoi * company->aptGainRate;
    }
    // townhouses
    if(type == 2){
        company->thPerformance = company->thRoi * company->thGainRate;
    }
    // semi-detached houses
    if(type == 3){
        company->sdhPerformance = company->sdhRoi * company->sdhGainRate;
    }
}

//initializes everything to 0
void initializeInfo(struct Company *company)
{

    company->aptMonthlyEarning = 0.00;
    company->thMonthlyEarning = 0.00;
    company->sdhMonthlyEarning = 0.00;
    company->aptRoi = 0.00;
    company->thRoi = 0.00;
    company->sdhRoi = 0.00;
    company->aptPerformance = 0.00;
    company->thPerformance = 0.00;
    company->sdhPerformance = 0.00;
    company->aptGainRate = 0.00;
    company->thGainRate = 0.00;
    company->sdhGainRate = 0.00;
    company->aptValue = 0.00;
    company->thValue = 0.00;
    company->sdhValue = 0.00;
    company->aptCapitalGains = 0.00;
    company->thCapitalGains = 0.00;
    company->sdhCapitalGains = 0.00;

    for (int i = 0; i < NUM_AP; i++){
        company->apt[i].address[0] = '\0';
        company->apt[i].numRooms = 0;
        company->apt[i].bathRooms = 0;
        company->apt[i].purchasePrice = 0.00;
        company->apt[i].years = 0.0;
        company->apt[i].monthlyRent = 0.00;
        company->apt[i].monthlyCondoFees = 0.00;
        company->apt[i].monthlyEarnings = 0.00;
        company->apt[i].roi = 0.00;
        company->apt[i].currentValue = 0.00;
        company->apt[i].capitalGains = 0.00;
        company->apt[i].capitalGainRate = 0.00;
        company->apt[i].performanceIndex = 0.00;
    }

    for (int i = 0; i < NUM_TH; i++){
        company->th[i].address[0] = '\0';
        company->th[i].numRooms = 0;
        company->th[i].bathRooms = 0;
        company->th[i].purchasePrice = 0.00;
        company->th[i].years = 0.0;
        company->th[i].monthlyRent = 0.00;
        company->th[i].monthlyCondoFees = 0.00;
        company->th[i].monthlyEarnings = 0.00;
        company->th[i].roi = 0.00;
        company->th[i].currentValue = 0.00;
        company->th[i].capitalGains = 0.00;
        company->th[i].capitalGainRate = 0.00;
        company->th[i].performanceIndex = 0.00;
        company->th[i].monthlyPropertyTax = 0.00;
        company->th[i].monthlyUtilities = 0.00;
    }
    for (int i = 0; i < NUM_AP; i++){
        company->sdh[i].address[0] = '\0';
        company->sdh[i].numRooms = 0;
        company->sdh[i].bathRooms = 0;
        company->sdh[i].purchasePrice = 0;
        company->sdh[i].years = 0.0;
        company->sdh[i].monthlyRent = 0.00;
        company->sdh[i].MonthlyPropertyTax = 0.00;
        company->sdh[i].monthlyEarnings = 0.00;
        company->sdh[i].roi = 0.00;
        company->sdh[i].currentValue = 0.00;
        company->sdh[i].capitalGains = 0.00;
        company->sdh[i].capitalGainRate = 0.00;
        company->sdh[i].performanceIndex = 0.00;
        company->sdh[i].monthlyUtilities = 0.00;
    }
}

//prints top category
void evaluateTopCategory(struct Company company){
    double avgGainRate = 0.00;
    if (company.aptPerformance > company.thPerformance && company.aptPerformance > company.sdhPerformance){
        avgGainRate = company.aptGainRate / NUM_AP;
        printf("TYPE: APPARTMENT\n");
        printf("ROI: %.2lf\n", company.aptRoi);
        printf("AVERAGE CAPITAL GAINS RATE: %.2lf\n", avgGainRate);
        printf("ROI X AVERAGE CAPITAL GAINS RATE: .%2lf\n", (company.aptRoi * avgGainRate));
    }
    else if(company.thPerformance > company.sdhPerformance){
        avgGainRate = company.thGainRate / NUM_TH;
        printf("TYPE: TOWNHOUSE\n");
        printf("ROI: %.2lf\n", company.thRoi);
        printf("AVERAGE CAPITAL GAINS RATE: %.2lf\n", avgGainRate);
        printf("ROI X AVERAGE CAPITAL GAIN RATE: %.2lf\n", (company.thRoi * avgGainRate));
    }
    else{
        avgGainRate = company.sdhGainRate / NUM_SEMI;
        printf("TYPE: SEMIDETACHED\n");
        printf("ROI: %.2lf\n", company.sdhRoi);
        printf("AVERAGE CAPITAL GAINS RATE: %.2lf\n", avgGainRate);
        printf("ROI X AVERAGE CAPITAL GAINS RATE: %.2lf", (company.sdhRoi * avgGainRate));
    }
}

//find performance for each property
void calcPropertyPerformance(struct Company *company, int type){
    // for apartment
    if(type == 1){
        for (int i = 0; i < NUM_AP; i++) {
            company->apt[i].performanceIndex = company->apt[i].roi * company->apt[i].capitalGainRate;
        }
    }
    //for townhouses
    if(type == 2){
        for (int i = 0; i < NUM_TH; i++){
            company->th[i].performanceIndex = company->th[i].roi * company->th[i].capitalGainRate;
        }
    }
    //for semi-detached houses
    if(type == 3){
        for (int i = 0; i < NUM_SEMI; i++){
            company->sdh[i].performanceIndex = company->sdh[i].roi * company->sdh[i].capitalGainRate;
        }
    }
}

//finds the top property
void evaluateTopProperty(struct Company company){
    int indexTopApt = 0, indexTopTh = 0, indexTopSdh = 0;
    //top apartment
    for (int i = 0; i < NUM_AP; i++){
        if(company.apt[i].performanceIndex > company.apt[indexTopApt].performanceIndex){
            indexTopApt = i;
        }
    //top townhouse
    }
    for(int i = 0; i < NUM_TH; i++){
        if(company.th[i].performanceIndex > company.th[indexTopTh].performanceIndex){
            indexTopTh = i;
        }
    }
    //top semidetached house
    for(int i = 0; i < NUM_SEMI; i++){
        if(company.sdh[i].performanceIndex > company.sdh[indexTopTh].performanceIndex){
            indexTopSdh = i;
        }
    }

    if(company.apt[indexTopApt].performanceIndex > company.th[indexTopTh].performanceIndex && company.apt[indexTopApt].performanceIndex > company.sdh[indexTopTh].performanceIndex){
        printf("ADDRESS : %s\n", company.apt[indexTopApt].address);
        printf("TYPE: APARTMENT\n");
        printf("ROI: %.2lf\n", company.apt[indexTopApt].roi);
        printf("CAPITAL GAINS RATE: %.2lf\n", company.apt[indexTopApt].capitalGainRate);
        printf("Number of Rooms: %d\n", company.apt[indexTopApt].numRooms);
        printf("Number of Bathrooms: %d\n", company.apt[indexTopApt].bathRooms);
        printf("ROI X CAPITAL GAINS: %.2lf\n\n\n", company.apt[indexTopApt].performanceIndex);
    }
    else if(company.th[indexTopTh].performanceIndex > company.sdh[indexTopSdh].performanceIndex){
        printf("ADDRESS : %s\n", company.th[indexTopTh].address);
        printf("TYPE: TOWNHOUSE\n");
        printf("ROI: %.2lf\n", company.th[indexTopTh].roi);
        printf("CAPITAL GAINS RATE: %.2lf\n", company.th[indexTopTh].capitalGainRate);
        printf("Number of Rooms: %d\n", company.th[indexTopTh].numRooms);
        printf("Number of Bathrooms: %d\n", company.th[indexTopTh].bathRooms);
        printf("ROI X CAPITAL GAINS: %.2lf\n\n\n", company.th[indexTopTh].performanceIndex);
    }
    else{
        printf("ADDRESS : %s\n", company.sdh[indexTopSdh].address);
        printf("TYPE: SEMI-DETACHED HOUSE\n");
        printf("ROI: %.2lf\n", company.sdh[indexTopSdh].roi);
        printf("CAPITAL GAINS RATE: %.2lf\n", company.sdh[indexTopSdh].capitalGainRate);
        printf("Number of Rooms: %d\n", company.sdh[indexTopSdh].numRooms);
        printf("Number of Bathrooms: %d\n", company.sdh[indexTopSdh].bathRooms);
        printf("ROI X CAPITAL GAINS: %.2lf\n\n\n", company.sdh[indexTopSdh].performanceIndex);
    }

}

// prints the formatted output
void printProperty(struct Company company){

    printf("The following are financial stats for Brookfield Asset Management, 11 Yonge Street\n\n");
    printf("Total Properties Owned: %d\n\n", TOTAL_PROPS);
    printf("Total Monthy Earnings: %.2lf\n\n", (company.aptMonthlyEarning + company.thMonthlyEarning + company.sdhMonthlyEarning));
    printf("Total ROI for all units: %.2lf\n\n\n", (company.aptRoi + company.thRoi + company.sdhRoi));

    printf("Apartments: \n\n\n");
    printf("Total units owned: %d\n", NUM_AP);
    printf("Monthy Earnings: $%.2lf\n", company.aptMonthlyEarning);
    printf("Avg monthly earnings (per unit): $%.2lf\n", (company.aptMonthlyEarning / NUM_AP));
    printf("ROI (for all units): %.2lf%%\n", company.aptRoi);
    printf("Total Value: $%.2lf\n", company.aptValue);
    printf("Capital gains: $%.2lf\n", company.aptCapitalGains);
    printf("Average capital gains rate: %.2lf\n\n\n", (company.aptGainRate / NUM_AP));

    printf("Townhouses: \n\n\n");
    printf("Total units owned: %d\n", NUM_TH);
    printf("Monthy Earnings: $%.2lf\n", company.thMonthlyEarning);
    printf("Avg monthly earnings (per unit): $%.2lf\n", (company.thMonthlyEarning / NUM_TH));
    printf("ROI (for all units): %.2lf%%\n", company.thRoi);
    printf("Total Value: $%.2lf\n", company.thValue);
    printf("Capital gains: $%.2lf\n", company.thCapitalGains);
    printf("Average capital gains rate: %.2lf\n\n\n", (company.thGainRate / NUM_TH));

    printf("Semi-detached houses: \n\n\n");
    printf("Total units owned: %d\n", NUM_SEMI);
    printf("Monthy Earnings: $%.2lf\n", company.sdhMonthlyEarning);
    printf("Avg monthly earnings (per unit): $%.2lf\n", (company.sdhMonthlyEarning / NUM_SEMI));
    printf("ROI (for all units): %.2lf%%\n", company.sdhRoi);
    printf("Total Value: $%.2lf\n", company.sdhValue);
    printf("Capital gains: $%.2lf\n", company.sdhCapitalGains);
    printf("Average capital gains rate: %.2lf\n\n\n", (company.sdhGainRate / NUM_SEMI));

}

