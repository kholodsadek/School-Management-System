#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include "Header.h"

int main()
{
    printf("*********School Management System*********\n");
    while(1){
        u32 choiceFromMenu, choiceFromExis, stuID,stuIndex;
        printf("******Main Menu******\n");
        printf(" 1- Create New Student. \n 2- Open Existing Student. \n 3- Students List. \n 4- Rank Student. \n 5- Exit System. \n");
        printf("Enter your Choice: ");
        fflush(stdin); fflush(stdout);
        scanf("%d", &choiceFromMenu);
        switch (choiceFromMenu){
        case 1:
            // create new student
            printf("******Create New Student******\n");
            createNewStudent();
            break;
        case 2:
            // open existing student
            printf("Enter Student ID: ");
            fflush(stdin); fflush(stdout);
            scanf("%d", &stuID);
            //check if this id is in list or not
            stuIndex = checkID(stuID);
            if(stuIndex == -1){
                break;
            }
            printf("******Open Existing Student******\n");
            printf(" 1- Student Edit. \n 2- Student Score. \n 3- Student List. \n 4- Delete Student. \n 5- Return to main menu. \n");
            printf("Enter your Choice: ");
            fflush(stdin); fflush(stdout);
            scanf("%d", &choiceFromExis);
            switch (choiceFromExis){
            case 1:
                // student edit
                studentEdit(stuID);
                break;
            case 2:
                // student score
                studentScore(stuID);
                break;
            case 3:
                // student list
                studentList(stuID);
                break;
            case 4:
                // delete student
                deleteStudent(stuID);
                break;
            case 5:
                // return to main menu
                break;
            default:
                printf("WRONG ENTER!\n");
                break;
            }
            break;
        case 3:
            // view students list
            studentsList();
            break;
        case 4:
            // rank student
            studentsRank();
            break;
        case 5:
            //exit system
            return 0;
        default:
            printf("WRONG ENTER!\n");
            break;
        }
    }
}


