#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stddef.h>

typedef struct {
    u8 name[100];
    u8 date_of_birth[11];
    u8 address[200];
    u8 phone_number[12];
    u32 id;
    f64 score;
    struct Student *next;
}Student;

u32 generateStudenID();
void createNewStudent();
u32 checkID(u32 studentID);
void studentList(u32 studentID);
void studentEdit(u32 studenID);
void studentScore(u32 studentID);
void deleteStudent(u32 studentID);
int compareByName(const void* a, const void* b);
void bubbleSort(void* base, u32 n, size_t size, int (*cmp)(const void*, const void*));
void studentsList();
void studentsRank();


#endif // HEADER_H_INCLUDED
