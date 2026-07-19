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


    while (1)
    {
        PrintMenu();
        int option = GetIntInput();
        switch (option)
        {
            case 1:
                printf("\nOpenning the student list...\n");
                ListStudent();
                break;
            case 2:
                printf("\nOpenning...\n");
                AddStudent();
                break;
            case 3:
                printf("\nOpenning student search system...\n");
                break;
            case 4:
                printf("\nOpenning deleting system...\n");
                break;
            case 0:
                exit(0);
            default:
                printf("\nEnter a valid value!\n");
                break;
        }
    }
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

void AddStudent()
{
    FILE* studentList = fopen("studentList", "a");

    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return;
    }

    char temp[50];

    while (getchar() != '\n');
    printf("\nPlease write a name of the student: ");
    fgets(temp, sizeof(temp), stdin);
    fprintf(studentList, "%s", temp);

    printf("\nPlease write a year of the student: ");
    fgets(temp, sizeof(temp), stdin);
    fprintf(studentList, "%s", temp);

    printf("\nPlease write gpa of the student: ");
    fgets(temp, sizeof(temp), stdin);
    fprintf(studentList, "%s\n\n", temp);

    printf("\nStudent added succesfully!\n");

    fclose(studentList);
}

void ListStudent()
{
    FILE* studentList = fopen("studentList", "r");

    char line[50];

    while (fgets(line, sizeof(line), studentList) != NULL)
    {
        printf("%s", line);
    }
}

int GetIntInput() {
    int input;

    while (1)
    {
        if (scanf("%d", &input) == 1 && input >= 0) break;
        printf("\nEnter a valid value!");
        while (getchar() != '\n');
    }

    return input;
}
float GetFloatInput() {
    float input;

    while (1)
    {
        if (scanf("%f", &input) == 1) break;
        printf("\nEnter a valid value!");
        while (getchar() != '\n');
    }

    return input;
}
