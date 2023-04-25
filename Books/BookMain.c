//BookMain.c, George Paul Robert, 117928226

#include <stdio.h>
//for using strcpy()
#include <string.h>
#include <stdlib.h>
#include "Book.h"

int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("Usage: ./Main  Book.txt");
		return -1;
	}
//array of structures for storing the data from the .txt file
	struct Book book[NUM_BOOKS];
	FILE *fp = NULL;

	fp = fopen(argv[1], "r");

	for (int i = 0; i < NUM_BOOKS; ++i) {
		char bookData[MAX_STREAM] = { 0 };
//temporary storage for fields from the .txt file after extraction so that they can be assignment to struct members
		char temp[MAX_STREAM];


		fscanf(fp, "%[^\n]s", bookData); // Read an entire line from the file and store in bookData
		while (fgetc(fp) != '\n' && (!feof(fp)));//clear out the carriage return

		//NAME;AUTHOR;YEAR;PRICE;
		//Call the extraction function four times too extract the NAME, AUTHOR, YEAR, and PRICE using
		//       the following pointers. Store the information into the array of Book objects one at a time:
		char *leftPtr = bookData;//&bookData[0]

		leftPtr = extractString(leftPtr, temp);
		strcpy(book[i].name, temp);

		leftPtr = extractString(leftPtr, temp);
		strcpy(book[i].author, temp);

		leftPtr = extractString(leftPtr, temp);
		book[i].year = atoi(temp);

		extractString(leftPtr, temp);
		book[i].price = atof(temp);
	}
	fclose(fp);

	printf("\t \t \t \t \tBOOK INFORMATION \n");
	printf("\n");

	for(int i = 0; i < NUM_BOOKS;i++){
		printf("%30s\t %30s\t %10d\t $%-5.2lf\n", book[i].name, book[i].author, book[i].year, book[i].price);
	}


	return 0;
}