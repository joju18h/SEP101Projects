//RealEstateMain.c - main program for real estate companies
//SEP101 Assignment 1, by Group C - George, Kunal, Kasra and Fahima

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "RealEstate.h"

//main function - George, Kunal

int main(void) {
	struct Company company;
	// Read the data for all companies from a file
	char address[255];
	int rooms;
	int bathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyCondoFees;
	double monthlyPropertyTax;
	float yearsOwned;

	initializeInfo(&company);

	//Retrieve data for apartments
	FILE* fp = fopen("Apartments.txt", "r");
	for (int i = 0; i < NUM_AP; ++i) {
		fscanf(fp, "%[^\n]s", address);
		strcpy(company.apt[i].address, address);
		fscanf(fp, "%d", &rooms);
		company.apt[i].numRooms = rooms;
		fscanf(fp, "%d", &bathrooms);
		company.apt[i].bathRooms = bathrooms;
		fscanf(fp, "%lf", &purchasePrice);
		company.apt[i].purchasePrice = purchasePrice;
		fscanf(fp, "%lf", &monthlyRent);
		company.apt[i].monthlyRent = monthlyRent;
		fscanf(fp, "%lf", &monthlyCondoFees);
		company.apt[i].monthlyCondoFees = monthlyCondoFees;
		fscanf(fp, "%f", &yearsOwned);
		company.apt[i].years = yearsOwned;

		while (fgetc(fp) != '\n' && (!feof(fp)));//clear the file buffer before the next fscanf()
	}


	//function calls for apartments
	calcMonthlyEarnings(&company,1);
	sumMonthlyEarnings(&company, 1);
	calcRoi(&company,1);
	calcSumRoi(&company,1);
	calcCurrentValue(&company,1);
	calcCapitalGain(&company,1);
	calcCapitalRate(&company,1);
	calcPerformanceIndex(&company,1);
	calcPropertyPerformance(&company, 1);

	fclose(fp);

	// Retrieve data for townhouses
	fp = fopen("Townhouses.txt", "r");
	for (int i = 0; i < NUM_SEMI; ++i) {
		fscanf(fp, "%[^\n]s", address);
		strcpy(company.th[i].address, address);
		fscanf(fp, "%d", &rooms);
		company.th[i].numRooms = rooms;
		fscanf(fp, "%d", &bathrooms);
		company.th[i].bathRooms = bathrooms;
		fscanf(fp, "%lf", &purchasePrice);
		company.th[i].purchasePrice = purchasePrice;
		fscanf(fp, "%lf", &monthlyRent);
		company.th[i].monthlyRent = monthlyRent;
		fscanf(fp, "%lf", &monthlyUtilities);
		company.th[i].monthlyUtilities = monthlyUtilities;
		fscanf(fp, "%lf", &monthlyCondoFees);
		company.th[i].monthlyCondoFees = monthlyCondoFees;
		fscanf(fp, "%lf", &monthlyPropertyTax);
		company.th[i].monthlyPropertyTax = monthlyPropertyTax;
		fscanf(fp, "%f", &yearsOwned);
		company.th[i].years = yearsOwned;

		while (fgetc(fp) != '\n' && (!feof(fp)));//clear the file buffer before the next fscanf()
	}
	//function calls for townhouses

	calcMonthlyEarnings(&company, 2);
	sumMonthlyEarnings(&company,2);
	calcRoi(&company,2);
	calcSumRoi(&company,2);
	calcCurrentValue(&company,2);
	calcCapitalGain(&company,2);
	calcCapitalRate(&company,2);
	calcPerformanceIndex(&company,2);
	calcPerformanceIndex(&company,2);
	calcPropertyPerformance(&company, 2);


	fclose(fp);

	//Retrieve data for semi-detached houses
	fp = fopen("SemiDetachedHouses.txt", "r");
	for (int i = 0; i < NUM_SEMI; ++i) {
		fscanf(fp, "%[^\n]s", address);
		strcpy(company.sdh[i].address, address);
		fscanf(fp, "%d", &rooms);
		company.sdh[i].numRooms = rooms;
		fscanf(fp, "%d", &bathrooms);
		company.sdh[i].bathRooms = bathrooms;
		fscanf(fp, "%lf", &purchasePrice);
		company.sdh[i].purchasePrice = purchasePrice;
		fscanf(fp, "%lf", &monthlyRent);
		company.sdh[i].monthlyRent = monthlyRent;
		fscanf(fp, "%lf", &monthlyUtilities);
		company.sdh[i].monthlyUtilities = monthlyUtilities;
		fscanf(fp, "%lf", &monthlyPropertyTax);
		company.sdh[i].MonthlyPropertyTax = monthlyPropertyTax;
		fscanf(fp, "%f", &yearsOwned);
		company.sdh[i].years = yearsOwned;

		while (fgetc(fp) != '\n' && (!feof(fp)));//clear the file buffer before the next fscanf()
	}
	//function calls for semidetched houses

	calcMonthlyEarnings(&company,3);
	sumMonthlyEarnings(&company,3);
	calcRoi(&company,3);
	calcSumRoi(&company,3);
	calcCurrentValue(&company,3);
	calcCapitalGain(&company,3);
	calcCapitalRate(&company,3);
	calcPerformanceIndex(&company,3);
	calcPerformanceIndex(&company,3);
	calcPropertyPerformance(&company, 3);

	fclose(fp);

//printing all values

	printProperty(company);
	printf("Top performing property (investment recomendation): \n");
	evaluateTopProperty(company);
	printf("Top performing property type: \n");
	evaluateTopCategory(company);

	return 0;
}