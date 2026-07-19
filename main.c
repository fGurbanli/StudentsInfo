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
    int order = 1;
    FILE* studentList = fopen("studentList.txt", "a+");

    rewind(studentList);

    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return;
    }
    char temp1[50];
    char temp2[50];
    char temp3[50];

    while (fgets(temp1, sizeof(temp1), studentList) != NULL) {
        order++;
    }

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
    fprintf(studentList, "%d-)Name: %s, year: %s, gpa: %s\n",order, temp1,temp2,temp3);

    printf("\nStudent added succesfully!\n");

    fclose(studentList);
}

void ListStudent()
{
    FILE* studentList = fopen("studentList.txt", "r");

    if (studentList == NULL)
    {
        printf("File couldn't be opened!\n");
        return;
    }

    char line[50];

    while (fgets(line, sizeof(line), studentList) != NULL)
    {
        printf("%s", line);
    }

    fclose(studentList);
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
