//lab5.h -  declarations for company info values that are store in a structure and function prototypes

//George Paul Robert
//grobert1@myseneca.ca
//117928226

#define MAXSTR 64 //maximum number of characters in names
#define NUM_COM 5 //number of companies


struct Company{  //struct Company that holds the company info
    char companyName[MAXSTR];
    char stockSymbol[MAXSTR];
    char companyValue[MAXSTR];
    float sharePrice;
    float annualDividend;
    float dividendYield;
};

//function prototypes
void initializeInfo(struct Company *company);
float calcDividendYield(struct Company *company);
void calcValuation(struct Company *company);
void cleanInputBuffer();