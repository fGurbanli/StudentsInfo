#include <stdio.h>
#include <stdlib.h>
#include "studentInfo.h"

int main(void) {

    //initial values
    int maxSize = 10;
    char temp[70];
    int order = 0;

    FILE* studentList = fopen("studentList.txt", "r"); //Opening file to find how many students there are

    if (studentList == NULL) {
        printf("\nFile couldn't be opened!");
        return 1;
    }

    rewind(studentList);

    while (fgets(temp, sizeof(temp), studentList) != NULL)
    {
        order++; //Getting student count
    }

    while (order >= maxSize)
    {
        maxSize *= 2; //Adjusting maxSize before memory allocation
    }

    rewind(studentList);

    Students* students = calloc(maxSize, sizeof(Students));

    if (students == NULL) {
        printf("\nMemory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < order; i++)
    {
        students[i].name = malloc(100);
        students[i].year = malloc(100); //Allocating memory for each type of information in struct
        students[i].gpa = malloc(10);

        fscanf(studentList, " %[^;];%[^;]; %[^;];" ,students[i].name,students[i].year,students[i].gpa);
    }

    while (1)
    {

        PrintMenu();
        int option = GetIntInput();
        switch (option)
        {
            case 1:
                printf("\nOpening the student list...\n");
                ListStudent(&order, students);
                break;
            case 2:
                printf("\nOpening...\n");
                AddStudent(&order, &students, &maxSize);
                break;
            case 3:
                printf("\nOpening student search system...\n");
                SearchStudent(students);
                break;
            case 4:
                printf("\nOpening deleting system...\n");
                DeleteStudent(&order, students);
                break;
            case 5:
                printf("\nOpening student editing system...");
                EditStudent(&order, students);
                break;
            case 0:
                fclose(studentList);
                for(int i = 0; i < order; i++)
                {
                    free(students[i].name);
                    free(students[i].year);
                    free(students[i].gpa);
                }

                free(students);
                exit(0);
            default:
                printf("\nEnter a valid value!\n");
                break;
        }
    }
}

