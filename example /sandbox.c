
int calcMonthlyEarnings(struct Apartment *apartment){
    int retval = 0;
    for (int i = 0; i < NUM_AP; i++){
        if (apartment[i].monthlyRent >= 0 && apartment[i].monthlyCondoFees >= 0)
        {
            apartment[i].monthlyEarnings = apartment[i].monthlyRent - apartment[i].monthlyCondoFees;
            retval = 1;
        }
    }
    return retval;
}

double calcSumMonthlyEarning(struct Apartment apt[]){
    double sumMonthlyEarning = 0;
    for (int i = 0; i < NUM_AP; i++){
        sumMonthlyEarning += apt[i].monthlyEarnings;
    }
    return sumMonthlyEarning;
}

int calcRoi(struct Apartment *apartment){
    int retval = 0;
    for (int i = 0; i < NUM_AP; i++){
        if(apartment[i].purchasePrice != 0)
        apartment[i].roi = 100 * 12 * (apartment[i].monthlyEarnings / apartment[i].purchasePrice);
        retval = 1;
    }
    return retval;
}

double sumRoi(struct Apartment apt[]){
    double sumRoi = 0;
    for (int i = 0; i < NUM_AP; i++){
        sumRoi += apt[i].roi;
    }
    return sumRoi;
}

void calcCurrentValue(struct Apartment *apartment){
    for (int i = 0; i < NUM_AP;i++){
        apartment[i].currentValue = 12 * (apartment[i].monthlyEarnings / INTEREST_RATE);
    }
}

int calcCapitalGain(struct Apartment *apartment){
    int retval = 0;

    for (int i = 0; i < NUM_AP; i++)
    { if(apartment[i].years != 0){
        apartment[i].capitalGains = apartment[i].currentValue - apartment[i].purchasePrice;
        apartment[i].capitalGainRate = apartment[i].capitalGains / apartment[i].years;
        retval = 1;
        }
    }
    return retval;
}

int calcPerformance(struct Apartment *apartment){
    int retval = 0;
    for (int i = 0; i < NUM_AP; i++){
        apartment[i].performanceIndex = apartment[i].roi * apartment[i].capitalGainRate;
        retval = 1;
    }
    return retval;
}

int TownHouseMonthlyEarnings(struct TownHouse* townhouse) {
    int retval = 0;
    for (int i = 0; i < NUM_TH; ++i)
    {
        townhouse[i].monthlyEarnings = (townhouse[i].monthlyRent - townhouse[i].monthlyUtilities - townhouse[i].monthlyCondoFees - townhouse[i].monthlyPropertyTax);
        retval = 1;
    }
    return retval;
}