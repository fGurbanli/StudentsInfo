# Student Management System (C)

A console-based Student Management System written in **C**, featuring dynamic memory allocation, modular source organization, and file persistence.

## Features

* Add new students
* List all students
* Search students
* Edit student information
* Delete students
* Automatically save and load data from a text file
* Dynamic memory management using `malloc()`, `calloc()`, `realloc()`, and `free()`

## Technologies

* C (C17)
* Standard C Library
* Dynamic Memory Allocation
* File I/O
* Structures
* Pointers
* Modular Programming (`.c` / `.h`)

## Project Structure

```text
StudentManagement
│
├── main.c              # Program entry point
├── studentInfo.c       # Student management functions
├── studentInfo.h       # Structure definitions and function declarations
├── studentList.txt     # Student database
└── README.md
```

## Concepts Practiced

This project was built as part of learning the C programming language and focuses on the following concepts:

* Functions
* Structures (`struct`)
* Header files (`.h`)
* Source files (`.c`)
* Function prototypes
* Pointers
* Pointer arithmetic
* Dynamic memory allocation
* Arrays of structures
* File handling (`fopen`, `fclose`, `fscanf`, `fprintf`)
* Modular programming
* Memory management

## Data Storage

Student records are stored in a text file (`studentList.txt`) and are automatically loaded when the program starts.

Example format:

```text
John Doe;2;3.75;
Alice Smith;1;4.00;
```

## Memory Management

Every student record dynamically allocates memory for:

* Name
* Academic Year
* GPA

All allocated memory is released before the program exits to prevent memory leaks.

## Future Improvements

* Separate File I/O into its own module
* Input validation improvements
* Sort students by GPA or name
* Export to CSV
* Binary file support
* Better error handling
* Unit tests

## How to Compile

Using GCC:

```bash
gcc main.c studentInfo.c -o StudentManagement
```

Run:

```bash
./StudentManagement
```

## Learning Purpose

This project was created for educational purposes while learning C programming. The primary goal was to gain practical experience with memory management, pointers, file handling, and organizing larger C projects into multiple source and header files.

## Author

**Furgan Gurbanli**
