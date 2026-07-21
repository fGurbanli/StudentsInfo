//
// Created by Furgan Gurbanlli on 21.07.2026.
//
#include "input.h"
#include <stdio.h>

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