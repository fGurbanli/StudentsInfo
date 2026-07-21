# Student Management System (C)

A modular console-based Student Management System written in **C**. This project was built to practice core C programming concepts including dynamic memory management, modular programming, pointers, structures, and file handling.

## Features

* Add new students
* List all students
* Search students
* Edit student information
* Delete students
* Automatic loading of student records from a file
* Persistent storage using text files
* Dynamic memory allocation with automatic resizing

## Technologies

* C (C17)
* Standard C Library
* Dynamic Memory Allocation
* File I/O
* Modular Programming
* Structures
* Pointers

## Project Structure

```text
StudentManagement/
│
├── main.c              # Program entry point
├── studentInfo.c       # Student management functions
├── studentInfo.h       # Student structure and function declarations
├── input.c             # Input validation functions
├── input.h             # Input function declarations
├── studentList.txt     # Student database
└── README.md
```

## Modules

### `main.c`

Controls the program flow and menu system.

### `studentInfo.c`

Implements all student management operations:

* Add Student
* Delete Student
* Edit Student
* Search Student
* List Students

### `studentInfo.h`

Contains:

* `Students` structure
* Function prototypes for the student management module

### `input.c`

Handles validated user input:

* `GetIntInput()`
* `GetFloatInput()`

### `input.h`

Contains the function declarations for the input module.

## Concepts Practiced

This project helped reinforce the following C programming concepts:

* Functions
* Structures (`struct`)
* Header files (`.h`)
* Source files (`.c`)
* Function prototypes
* Modular programming
* Pointers
* Dynamic memory allocation (`malloc`, `calloc`, `realloc`, `free`)
* Arrays of structures
* File handling (`fopen`, `fclose`, `fscanf`, `fprintf`)
* Memory management
* Input validation

## Memory Management

Each student stores dynamically allocated memory for:

* Name
* Academic Year
* GPA

All allocated memory is released before the program terminates to prevent memory leaks.

## Data Storage

Student records are stored in `studentList.txt` and are automatically loaded when the application starts.

Example:

```text
John Doe;2;3.75;
Alice Smith;1;4.00;
```

## Future Improvements

* Create a dedicated `file.c` / `file.h` module for all File I/O operations
* Sort students by GPA or name
* Export data to CSV
* Binary file support
* Improve error handling
* Unit testing

## Build

Using GCC:

```bash
gcc main.c studentInfo.c input.c -o StudentManagement
```

Run:

```bash
./StudentManagement
```

## Author

**Furgan Gurbanli**
