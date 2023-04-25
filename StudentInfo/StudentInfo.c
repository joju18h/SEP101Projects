//StudentInfo.c - function definitions for student information

//George Paul Robert
//grobert1@myseneca.ca
//117928226
#include <stdbool.h>
#include "StudentInfo.h"

/*struct Subject{
    char name[MAX_STR];
    int mark;
};

struct StudentInfo
{
    char lastName[MAX_STR];
    int studentId;
    struct Subject subject[NUM_SUBJECTS];
};
*/

//initializeInfo - returns void, accepts the address of struct StudentInfo
//Sets the last name to a null string. This can be accomplished by setting the first character
//                                     in the last name array to the null terminator '\0'.
//Sets the student id to 0.
//Goes through the subject array (NUM_SUBJECTS) and for each subject
//     sets name to a null string and
//     sets mark to 0.
void initializeInfo(struct StudentInfo *thestudent){
    thestudent->lastName[0] = '\0';
    thestudent->studentId = 0;

    for (int i = 0; i < NUM_SUBJECTS; ++i){
        thestudent->subject[i].mark = 0;
        thestudent->subject[i].name[i] = '\0';
    }
}


//findMinMark - returns integer, accepts the address struct Subject
//
//Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//    Once an invalid mark is reached (mark equals zero), the loop terminates
//
//The index of the minimum mark is returned

int findMinMark(struct Subject *thesub){
    bool validity = true; //checking if an invalid mark(mark == 0) is reached
    int minMark = 100;
    int index = 0;
    for (int i = 0; i < NUM_SUBJECTS && validity == true; ++i){
        if(thesub[i].mark == 0){
            validity = false;
        }
        else if(thesub[i].mark < minMark){
            minMark = thesub[i].mark;
            index = i;
        }
    }
    return index;
}

//findMaxMark - returns integer, accepts the address of struct Subject
//
//Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//    Once an invalid mark is reached (mark equals zero), the loop terminates
//
//The index of the maximum mark is returned
int findMaxMark(struct Subject *thesub){
    bool validity = true;
    int maxMark = 0;
    int index = 0;
    for (int i = 0; i < NUM_SUBJECTS && validity == true; ++i){
        if(thesub[i].mark == 0){
            validity = false;
        }
        else if(thesub[i].mark > maxMark){
            maxMark = thesub[i].mark;
            index = i;
        }
    }
    return index;
}

//calcAverageMark - returns float, accepts the address of struct Subject
//
//Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//    Once an invalid mark is reached (mark equals zero), the loop terminates
//
//Returns the running total divided by the number of marks.

float calcAverageMark(struct Subject* thesub){
    bool validity = true;
    double runningTotal = 0.00; //for calculating the sum of the marks
    double avg = 0.00; //for calculating the average marks
    int counter = 0; //for finding the number of subjects the student has taken
    for (int i = 0; i < NUM_SUBJECTS && validity == true; ++i){
        if(thesub[i].mark == 0){
            validity = false;
            counter = i; //counter gets set to the value of i that has a zero value store inside it so that you obtain the number of subjects
        }
        else{
            runningTotal += thesub[i].mark;
        }
    }
    avg = runningTotal / counter;
    return avg;
}
