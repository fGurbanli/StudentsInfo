#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students {
    char name[100];
    char year[100];
    char gpa[10];
}Students;

int GetIntInput();
float GetFloatInput();

void PrintMenu();
void AddStudent(int* order, Students* students);
void DeleteStudent(int* order, Students* students);
void EditStudent(int* order);
void ListStudent(int* order, Students* students);
void SearchStudent();


int main(void) {

    char temp[70];
    int order = 0;

    FILE* studentList = fopen("studentList.txt", "r");

    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return 1;
    }

    rewind(studentList);


    while (fgets(temp, sizeof(temp), studentList) != NULL)
    {
        order++;
    }
    rewind(studentList);

    Students students[order];

    for (int i = 0; i < order; i++)
    {
        fscanf(studentList, " %[^;];%[^;]; %[^;];" ,students[i].name,students[i].year,students[i].gpa);
    }



    while (1)
    {

        PrintMenu();
        int option = GetIntInput();
        switch (option)
        {
            case 1:
                printf("\nOpenning the student list...\n");
                ListStudent(&order, students);
                break;
            case 2:
                printf("\nOpenning...\n");
                AddStudent(&order, students);
                break;
            case 3:
                printf("\nOpenning student search system...\n");
                break;
            case 4:
                printf("\nOpenning deleting system...\n");
                DeleteStudent(&order, students);
                break;
            case 0:
                fclose(studentList);
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

void AddStudent(int* order, Students* students)
{
    FILE* studentList = fopen("studentList.txt", "a+");
    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return ;
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
    fprintf(studentList, "%s;%s %s\n", temp1,temp2,temp3);

    printf("\nStudent added succesfully!\n");

    (*order)++;

    fscanf(studentList, "%[^;]" ,students[*order - 1].name);
    fscanf(studentList, "%s" ,students[*order - 1].year);
    fscanf(studentList, "%s" ,students[*order - 1].gpa);

    fclose(studentList);
}

void ListStudent(int* order, Students* students) {
    for (int i = 0; i < *order; i++)
    {
        printf("\n=====Student %d=====", i + 1);
        printf("\nName: %s Year: %s GPA: %s\n", students[i].name, students[i].year, students[i].gpa);
    }
}

void DeleteStudent(int* order, Students* students)
{
    FILE* temp = fopen("temp.txt", "w");
    FILE* studentList = fopen("studentList.txt", "r");

    char line[200];
    int newLine = 1;

    if (studentList == NULL) {
        printf("\nFile couldn't be openned!");
        return;
    }

    if (temp == NULL) {
        printf("\nFile couldn't be openned!");
        fclose(temp);
        fclose(studentList);
        return;
    }
    ListStudent(order, students);
    printf("\nEnter the index of the student you want to delete: ");

    int input = GetIntInput();

    if (*order - 1 < input) {
        printf("\nEnter a valid value!\n");
        return;
    }

    while (fgets(line, sizeof(line), studentList) != NULL) {
        if (newLine != input) {
            fputs(line, temp);
        }
        newLine++;
    }



    fclose(temp);
    fclose(studentList);

    if (remove("studentList.txt") != 0)
    {
        printf("Delete failed!\n");
    }

    if (rename("temp.txt", "studentList.txt") != 0)
    {
        printf("Rename failed!\n");
    }

    (*order)--;
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
