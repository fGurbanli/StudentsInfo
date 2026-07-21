//
// Created by Furgan Gurbanlli on 21.07.2026.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "studentInfo.h"

void PrintMenu()
{
    printf("\n=====Student Information System=====\n\n");
    printf("1- List of Student\n");
    printf("2- Add a Student\n");
    printf("3- Search a Student\n");
    printf("4- Delete a Student\n");
    printf("5- Edit a Student\n");
    printf("\n0- Exit\n");
}

void AddStudent(int* order, Students** students, int* maxSize)
{
    FILE* studentList = fopen("studentList.txt", "a+");
    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return ;
    }

    //Checks if there is a empty space for new student

    if (*order >= *maxSize) {
        (*maxSize) *= 2; //If there is no empty space maxSize will be doubled
        Students* temp = realloc(*students, (*maxSize) * sizeof(Students)); //Allocating memory again with double size
        if (temp == NULL) {
            printf("\nMemory allocation failed!\n");
            return;
        }
        *students = temp;
        for (int i = *order; i < *maxSize; i++)
        {
            (*students)[i].name = NULL;
            (*students)[i].year = NULL; //Giving NULL for values of unoccupied spaces
            (*students)[i].gpa = NULL;
        }
    }

    char temp1[500];
    char temp2[500]; //Temporary variables for getting informations of students
    char temp3[500];

    while (getchar() != '\n');
    printf("\nPlease write a name of the student: ");
    fgets(temp1, sizeof(temp1), stdin);
    temp1[strcspn(temp1, "\n")] = '\0';

    printf("\nPlease write a year of the student: ");
    fgets(temp2, sizeof(temp2), stdin);
    temp2[strcspn(temp2, "\n")] = '\0';

    printf("\nPlease write gpa of the student: ");
    fgets(temp3, sizeof(temp3), stdin);
    temp3[strcspn(temp3, "\n")] = '\0';
    fprintf(studentList, "%s;%s;%s;\n", temp1,temp2,temp3);

    printf("\nStudent added succesfully!\n");

    (*students)[*order].name = malloc(strlen(temp1)+1);
    (*students)[*order].year = malloc(strlen(temp2)+1); //Allocating memory
    (*students)[*order].gpa = malloc(strlen(temp3)+1);

    if ((*students)[*order].name == NULL) {
        printf("\nMemory allocation failed!");
        return ;
    }
    if ((*students)[*order].year == NULL) {
        printf("\nMemory allocation failed!");
        return ;
    }
    if ((*students)[*order].gpa == NULL) {
        printf("\nMemory allocation failed!");
        return ;
    }

    strcpy((*students)[*order].name, temp1);
    strcpy((*students)[*order].year, temp2); //Writing information of students
    strcpy((*students)[*order].gpa, temp3);

    (*order)++;

    fclose(studentList);
}

void ListStudent(int* order, Students* students) {
    for (int i = 0; i < *order; i++)
    {
        printf("\n=====Student %d=====", i + 1);
        printf("\nName: %s Year: %s GPA: %s\n", students[i].name, students[i].year, students[i].gpa);
    }
}

void DeleteStudent(int* order, Students* students) {
    ListStudent(order, students);
    printf("\nEnter an index of the student you want to delete: (Insert 0 to exit) ");

    int input;

    while (1) {
        input = GetIntInput();
        if (input >= 0 && input <= *order) {
            break;
        }
        printf("\nEnter a valid value!");
    }
    if (input == 0) {
        return; //0 to exit
    }

    for (int i = input; i < *order; i++)
    {
        strcpy(students[i - 1].name, students[i].name);
        strcpy(students[i - 1].year, students[i].year); //Moving array after inserted index 1 down
        strcpy(students[i - 1].gpa, students[i].gpa);
    }

    free(students[input - 1].name);
    free(students[input - 1].year); //Setting deleted students' datas free
    free(students[input - 1].gpa);

    (*order)--;

    FILE* studentList = fopen("studentList.txt", "w"); //Openning file for rewriting without deleted student

    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return ;
    }

    for (int i = 0; i < *order; i++)
    {
        fprintf(studentList,"%s;%s;%s;\n", students[i].name,students[i].year,students[i].gpa); //Rewriting all students datas
    }

    fclose(studentList);
}

void EditStudent(int* order, Students* students) //This function will delete selected student and rewrite again
{
    ListStudent(order, students);
    printf("\nEnter an index of the student you want to edit: (Insert 0 to exit) ");


    int input;

    while (1) {
        input = GetIntInput();
        if (input >= 0 && input <= *order) {
            break;
        }
        printf("\nEnter a valid value!");
    }

    if (input == 0) {
        return; // 0 to exit
    }

    char temp1[500];
    char temp2[500];
    char temp3[500];

    while (getchar() != '\n');
    printf("\nPlease write a name of the student: ");
    fgets(temp1, sizeof(temp1), stdin);
    temp1[strcspn(temp1, "\n")] = '\0';

    printf("\nPlease write a year of the student: ");
    fgets(temp2, sizeof(temp2), stdin);
    temp2[strcspn(temp2, "\n")] = '\0';

    printf("\nPlease write gpa of the student: ");
    fgets(temp3, sizeof(temp3), stdin);
    temp3[strcspn(temp3, "\n")] = '\0';

    free(students[input - 1].name);
    free(students[input - 1].year);
    free(students[input - 1].gpa);

    students[input - 1].name = malloc(strlen(temp1)+1);
    students[input - 1].year = malloc(strlen(temp2)+1); //Deleting selected student
    students[input - 1].gpa = malloc(strlen(temp3)+1);

    strcpy(students[input - 1].name, temp1);
    strcpy(students[input - 1].year, temp2); //Rewriting
    strcpy(students[input - 1].gpa, temp3);

    FILE* studentList = fopen("studentList.txt", "w");

    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return ;
    }

    for (int i = 0; i < *order; i++)
    {
        fprintf(studentList,"%s;%s;%s;\n", students[i].name,students[i].year,students[i].gpa);
    }

    fclose(studentList);
}

void SearchStudent(Students* students) {
    int orderLine = 0;
    FILE* studentList = fopen("studentList.txt","r");
    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return ;
    }

    char line[100];
    char search[50];

    while (getchar() != '\n');
    printf("\nEnter a name of student you want search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';

    while (fgets(line, sizeof(line), studentList) != NULL)
    {
        if (strstr(line, search) != NULL)
        {
            printf("\n====Student Found====\n");
            printf("Name: %s Year: %s GPA: %s", students[orderLine].name, students[orderLine].year, students[orderLine].gpa);
            return;
        }
        orderLine++;
    }

    printf("\nStudent couldn't be found!");

    fclose(studentList);
}

int GetIntInput() {
    int input;

    while (1)
    {
        if (scanf("%d", &input) == 1 && input >= 0) break;
        printf("\nEnter a valid value!");
        while (getchar() != '\n'); //cleaning buffer
    }

    return input;
}
float GetFloatInput() {
    float input;

    while (1)
    {
        if (scanf("%f", &input) == 1) break;
        printf("\nEnter a valid value!");
        while (getchar() != '\n'); //cleaning buffer
    }

    return input;
}
