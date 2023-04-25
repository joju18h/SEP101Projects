//StudentInfo.h - declarations for student information

//George Paul Robert
//grobert1@myseneca.ca
//117928226

#define MAX_STR 64
#define NUM_SUBJECTS 4

//struct Subject with members name(character array stores the name of the subject) and marks

struct Subject{
    char name[MAX_STR];
    int mark;
};

//struct StudentInfo with members lastName to store the last name of the student
// studentId and array of structures subject which is a variable of structure Subject
struct StudentInfo{
    char lastName[MAX_STR];
    int studentId;
    struct Subject subject[NUM_SUBJECTS];
};


//initializeInfo - returns void, accepts the address of struct StudentInfo
//findMinMark - returns integer, accepts the address struct Subject
//findMaxMark - returns integer, accepts the address of struct Subject
//calcAverageMark - returns float, accepts the address of struct Subject

void initializeInfo(struct StudentInfo* thestudent);
int findMinMark(struct Subject* thesub);
int findMaxMark(struct Subject* thesub);
float calcAverageMark(struct Subject* thesub);


