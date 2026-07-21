# Student Information System (C)

A console-based **Student Information System** written in C.
This project demonstrates dynamic memory management, structures, file handling, and basic CRUD operations.

The program allows users to manage student records by adding, listing, searching, editing, and deleting students. Student information is stored permanently in a text file.

---

## Features

* Add new students
* List all students
* Search students by name
* Edit existing student information
* Delete students
* Save data permanently using file I/O
* Dynamic memory allocation for student records
* Automatic memory resizing with `realloc()`

---

## Technologies Used

* C Programming Language
* Standard C Libraries:

    * `stdio.h`
    * `stdlib.h`
    * `string.h`

---

## Concepts Practiced

This project was created to practice intermediate C programming concepts:

### Structures

Student data is organized using a custom structure:

```c
typedef struct Students {
    char* name;
    char* year;
    char* gpa;
} Students;
```

### Dynamic Memory Management

The program uses:

* `calloc()` to allocate memory for the student list
* `malloc()` to allocate memory for individual student information
* `realloc()` to increase the size of the student array
* `free()` to release allocated memory

### File I/O

Student information is stored in:

```
studentList.txt
```

The program uses:

* `fopen()`
* `fprintf()`
* `fscanf()`
* `fgets()`
* `fclose()`

to read and write data.

---

## Menu

The program provides the following options:

```
=====Student Information System=====

1- List of Student
2- Add a Student
3- Search a Student
4- Delete a Student
5- Edit a Student

0- Exit
```

---

## Data Storage Format

Student records are stored in the following format:

```
Name;Year;GPA;
```

Example:

```
John Smith;2;3.75;
Alice Brown;1;4.20;
```

---

## How to Run

### Compile

Using GCC:

```bash
gcc main.c -o StudentSystem
```

### Run

Linux / macOS:

```bash
./StudentSystem
```

Windows:

```bash
StudentSystem.exe
```

---

## Project Structure

```
StudentInformationSystem/
│
├── main.c
├── studentList.txt
└── README.md
```

---

## Future Improvements

Possible improvements for future versions:

* Replace text file storage with binary file storage (`fread` / `fwrite`)
* Add sorting functionality
* Add student ID system
* Improve error handling
* Separate code into multiple source files (`.c` and `.h`)
* Add password protection
* Use dynamic string resizing instead of fixed allocations

---

## Author

**Furgan Gurbanli**

This project was developed as a practice project while learning C programming, focusing on memory management and file operations.
