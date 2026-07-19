#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetIntInput();
float GetFloatInput();

void PrintMenu();
void AddStudent();
void DeleteStudent();
void EditStudent();
void ListStudent();
void SearchStudent();


int main(void) {

    PrintMenu();

    return 0;
}

void PrintMenu()
{
    printf("\n=====Student Information System=====\n\n");
    printf("1- List of Student\n");
    printf("2- Add a Student\n");
    printf("3- Search a Student\n");
    printf("4- Delete a Student\n");
    printf("\n0- Exit\n");
}

int GetIntInput() {
    int input;

    while (1)
    {
        if (scanf("%d", &input) == 1) break;
    }
    printf("\nEnter a valid value!");
    while (getchar() != '\n');
    return input;
}
float GetFloatInput() {
    float input;

    while (1)
    {
        if (scanf("%f", &input) == 1) break;
    }
    printf("\nEnter a valid value!");
    while (getchar() != '\n');
    return input;
}
