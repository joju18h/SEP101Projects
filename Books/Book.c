//George Paul Robert, 117928226
//Book.c - function definitions for the Book class

// a function to extract a string from the stream.
//It will be called four times from main() to extract the
//NAME, AUTHOR, YEAR OF PUBLICATION, and PRICE.

/*
returns a char pointer to the next field after the delimiter
and takes in the pointer to the streaming data and a temporary id that stores the extracted field
*/

char* extractString(char *leftptr, char *temp){
    int index = 0;
    while (*leftptr != ';' && *leftptr != '\0')
    {
        temp[index] = *leftptr;
        ++index;
        ++leftptr;
    }
    temp[index] = '\0';

     //returns the adresss of the first character of the subsequent field
    return ++leftptr;
}

