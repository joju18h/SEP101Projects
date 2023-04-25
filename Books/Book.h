//George Paul Robert, 117928226
//Book.h - The Book structure and function prototype

#define BOOK_H_

//GIVEN: some useful constants
const int MAX_STRING = 64;
const int MAX_STREAM = 128;
const int NUM_BOOKS = 5;//Let's read only five books from the file

//TODO: Create a class or structure called Book
//      If you create a class, you can make all variables public

struct Book{
    char name[MAX_STRING];
    char author[MAX_STREAM];
    int year;
    double price;
};

//function protoype
char* extractString(char *leftptr, char *temp);
