//RealEstate.h, Group - C
//git test

//new branch
#define MAX_STR 255
#define NUM_AP 2
#define NUM_TH 5
#define NUM_SEMI 6
#define TOTAL_PROPS 13
#define INTEREST_RATE 0.05


//apartment struct - Kunal
struct Apartment{
    char address[MAX_STR];
    int numRooms;
    int bathRooms;
    double purchasePrice;
    float years;
    double monthlyRent;
    double monthlyCondoFees;
    double monthlyEarnings;
    double roi;
    double currentValue;
    double capitalGains;
    double capitalGainRate;
    double performanceIndex;
};

//townhouse struct - Fahima
struct TownHouse {
    char address[MAX_STR];
    int numRooms;
    int bathRooms;
    float purchasePrice;
    float years;
    float monthlyRent;
    float monthlyCondoFees;
    double monthlyEarnings;
    double roi;
    double currentValue;
    double capitalGains;
    double capitalGainRate;
    double performanceIndex;
    double monthlyUtilities;
    double monthlyPropertyTax;
};

//semidetached houses - Kasra
struct SemiDeHouse{
    char address[MAX_STR];
    int numRooms;
    int bathRooms;
    float purchasePrice;
    float years;
    float monthlyRent;
    double monthlyEarnings;
    double roi;
    double currentValue;
    double capitalGains;
    double capitalGainRate;
    double performanceIndex;
    double monthlyUtilities;
    double MonthlyPropertyTax;
};

//Real Estate Company's struct - George
struct Company{
    struct Apartment apt[NUM_AP];
    struct TownHouse th[NUM_TH];
    struct SemiDeHouse sdh[NUM_SEMI];
    float aptMonthlyEarning;
    float thMonthlyEarning;
    float sdhMonthlyEarning;
    double aptRoi;
    double thRoi;
    double sdhRoi;
    double aptPerformance;
    double thPerformance;
    double sdhPerformance;
    double aptGainRate;
    double thGainRate;
    double sdhGainRate;
    double aptValue;
    double thValue;
    double sdhValue;
    double aptCapitalGains;
    double thCapitalGains;
    double sdhCapitalGains;
};

//function Protoypes - everyone worked on their own individual properties' fucntions. Combined by George

void calcMonthlyEarnings(struct Company *company, int type);
void sumMonthlyEarnings(struct Company *company, int type);
void calcRoi(struct Company *company, int type);
void calcSumRoi(struct Company *company,int type);
void calcCurrentValue(struct Company *company, int type);
void calcCapitalGain(struct Company *company, int type);
void calcCapitalRate(struct Company *company, int type);
void calcPerformanceIndex(struct Company *company, int type);
void initializeInfo(struct Company *company);
void evaluateTopCategory(struct Company company);
void calcPropertyPerformance(struct Company *company, int type);
void evaluateTopProperty(struct Company company);
void printProperty(struct Company company);