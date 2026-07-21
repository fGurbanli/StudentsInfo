//
// Created by Furgan Gurbanlli on 21.07.2026
//

#ifndef STUDENTSINFO_STUDENTINFO_H
#define STUDENTSINFO_STUDENTINFO_H

typedef struct Students {
    char* name;
    char* year;
    char* gpa;
}Students;

void PrintMenu();
void AddStudent(int* order, Students** students, int* maxSize);
void DeleteStudent(int* order, Students* students);
void EditStudent(int* order,Students* students);
void ListStudent(int* order, Students* students);
void SearchStudent(Students* students);

#endif //STUDENTSINFO_STUDENTINFO_H