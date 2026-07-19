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




    return 0;
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
