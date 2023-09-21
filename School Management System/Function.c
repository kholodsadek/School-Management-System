#include "STD_TYPES.h"
#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAXRECORDS 100
static Student students[MAXRECORDS];
static u32 numOfStudends = 0;

u32 generateStudenID() {
    static u32 accountCounter = 20230100; // Starting account ID
    return accountCounter++;
}

void createNewStudent() {
    printf("FullName: ");
    fflush(stdin);fflush(stdout);
    scanf("%s",students[numOfStudends].name);
    printf("Address: ");
    fflush(stdin);fflush(stdout);
    scanf("%s",students[numOfStudends].address);
    printf("Date Of Birth: ");
    fflush(stdin);fflush(stdout);
    scanf("%s",students[numOfStudends].date_of_birth);
    printf("Phone number: ");
    fflush(stdin);fflush(stdout);
    scanf("%s",students[numOfStudends].phone_number);
    students[numOfStudends].id = generateStudenID();
    printf("Student ID: %d\n",students[numOfStudends].id);

    numOfStudends++;
    printf("Student Create Successfully.\n");
}

u32 checkID(u32 studentID) {
    // Find the student's record
    u32 studentIndex = -1;
    for (u32 i = 0; i < numOfStudends; i++) {
        if (students[i].id == studentID) {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex == -1) {
        printf("Student's ID not found.\n");
    }
    return studentIndex;
}

void studentList(u32 studentID){
    u32 studentIndex = checkID(studentID);
    if(studentIndex == -1){
        return;
    }
    printf("Student has ID %d information:\n",studentID);
    printf("FullName: %s\n",students[studentIndex].name);
    printf("Address: %s\n",students[studentIndex].address);
    printf("Date of Birth: %s\n",students[studentIndex].date_of_birth);
    printf("Phone Number; %s\n",students[studentIndex].phone_number);
    printf("Score: %.2lf\n",students[studentIndex].score);
}

void studentEdit(u32 studentID){
    studentList(studentID);
    u32 studentIndex = checkID(studentID);
    if(studentIndex == -1){
        return;
    }
    u32 choice;
    printf(" 1- FullName.    2- Address.    3- Date of Birth.    4- Phone Number.\n");
    printf("Enter your choice: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&choice);
    switch(choice){
    case 1:
        // edit fullname
        printf("Enter new FullName: ");
        fflush(stdin);fflush(stdout);
        scanf("%s",students[studentIndex].name);
        break;
    case 2:
        // edit address
        printf("Enter new Address: ");
        fflush(stdin);fflush(stdout);
        scanf("%s",students[studentIndex].address);
        break;
    case 3:
        // edit date of birth
        printf("Enter new Date of birth: ");
        fflush(stdin);fflush(stdout);
        scanf("%s",students[studentIndex].date_of_birth);
        break;
    case 4:
        // edit phone number
        printf("Enter new Phone Number: ");
        fflush(stdin);fflush(stdout);
        scanf("%s",students[studentIndex].phone_number);
        break;
    default:
        printf("Wrong Enter!\n");
        break;
    }
    printf("Student Record Update Successfully.\n");
}

void studentScore(u32 studentID){
    u8 answer;
    f64 temp;
    u32 studentIndex = checkID(studentID);
    if(studentIndex == -1){
        return;
    }
    temp = students[studentIndex].score;
    printf("Score of Student ID %d: %.2lf\n",studentID,students[studentIndex].score);
    printf("Do you Want Edited? y/n: ");
    fflush(stdin);fflush(stdout);
    scanf("%c",&answer);
    switch (answer){
    case 'n':
        return;
    case 'y':
        printf("Enter New Score: ");
        fflush(stdin);fflush(stdout);
        scanf("%lf", &students[studentIndex].score);
        break;
    default:
        printf("WRONG ENTER!\n");
        break;
    }
    if (temp == students[studentIndex].score){
        printf("Student Score doesn't Update Successfully.\n");
        return;
    }
    printf("Student Score Update Successfully.\n");
}

void deleteStudent(u32 studentID) {
    u32 studentIndex = checkID(studentID);
    if (studentIndex == -1) {
        printf("Student's ID not found.\n");
        return;
    }

    // Move all elements after the deleted student one position up
    for (u32 i = studentIndex; i < numOfStudends - 1; i++) {
        students[i] = students[i + 1];
    }

    numOfStudends--;
    printf("Student Record is deleted Successfully.\n");
}

// Comparison function for sorting by name
int compareByName(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

// Bubble sort function that accepts a comparison function
void bubbleSort(void* base, u32 n, size_t size, int (*cmp)(const void*, const void*)) {
    for (u32 i = 0; i < n - 1; i++) {
        for (u32 j = 0; j < n - i - 1; j++) {
            if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0) {
                // Swap elements
                char temp[size];
                memcpy(temp, (char*)base + j * size, size);
                memcpy((char*)base + j * size, (char*)base + (j + 1) * size, size);
                memcpy((char*)base + (j + 1) * size, temp, size);
            }
        }
    }
}

void studentsList(){
    if (numOfStudends == 0) {
        printf("No Records in System.\n");
        return;
    }
    // Sort the students array by name
    bubbleSort(students, numOfStudends, sizeof(Student), compareByName);
    for(u32 i=0;i<numOfStudends;i++){
            printf("ID: %d\n",students[i].id);
            printf("FullName: %s\n",students[i].name);
            printf("Address: %s\n",students[i].address);
            printf("Date of Birth: %s\n",students[i].date_of_birth);
            printf("Phone Number; %s\n",students[i].phone_number);
            printf("Score: %.2lf\n",students[i].score);
            printf("----------------------------------\n");
    }
}

void studentsRank(){
    if (numOfStudends == 0) {
        printf("No Records in System.\n");
        return;
    }
    u32 i;
    for(i=0;i<numOfStudends;i++){
        if (students[i].score < students[i+1].score){
            f64 temp = students[i].score;
            students[i].score = students[i+1].score;
            students[i+1].score = temp;
        }
    }
    for(u32 i=0;i<numOfStudends;i++){
            printf("ID: %d\n",students[i].id);
            printf("Score: %.2lf\n",students[i].score);
            printf("----------------------------------\n");
    }
}

