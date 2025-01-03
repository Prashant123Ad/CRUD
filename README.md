Student Database Management System

A C-based Student Database Management System that performs CRUD (Create, Read, Update, Delete) operations on student records. The application enables the management of student details, including adding, updating, searching, and deleting records stored in a file.

Features

Add Student Records: Allows users to add a new student to the database.

Search Student Records: Searches for student details using the roll number.

Update Student Records: Updates the existing details of a student.

Delete Student Records: Removes a student record from the database.

File-based Storage: All records are stored in a file (std.txt). Temporary files are used for updating and deleting operations to ensure data consistency.

Code Overview

Struct Definition

The struct student defines the attributes of a student:

struct student {
    int id;
    int roll;
    int grade;
    char name[20];
    char gender[20];
    char stream[20];
    char section[20];
    char address[20];
    char email[50];
    int mobile[50];
};

Functions

1. Main Function

Displays a menu for users to choose operations.

Options include Add, Search, Update, Delete, and Exit.

2. Add Function

Takes student details as input.

Appends the new student record to the file std.txt.

3. Search Function

Searches for a student using the roll number.

Displays student details if found; otherwise, notifies the user.

4. Delete Function

Deletes a student record by roll number.

Copies all records except the matching one into a temporary file and replaces the original file with the temporary file.

5. Update Function

Updates the details of a student by roll number.

Similar to the delete function, it uses a temporary file to store updated data.

How to Run the Program

Prerequisites

C Compiler: Ensure you have a C compiler installed (e.g., GCC).

Environment: Windows with conio.h support or equivalent setup.

Steps

Save the code in a file named student_management.c.

Open a terminal or command prompt.

Compile the program:

gcc student_management.c -o student_management

Run the compiled program:

./student_management

Follow the menu options to perform CRUD operations.

File Details

std.txt: Stores the student records.

temp.txt: Used as a temporary file during update and delete operations.

Example Output

Main Menu

<*<*<* Student Record Management >*>*>*
1. Add
2. Delete
3. Search
4. Update

Enter your choice: 1

Adding a Student Record

Enter roll: 101
Enter name: JohnDoe
Enter id: 1
Enter stream: Science
Enter gender: Male
Enter grade: 12
Enter section: A
Enter address: NewYork
Enter email address: john@example.com
Enter mobile no: 1234567890

Do you want more? (y/n): n

Searching for a Record

Enter roll: 101
1. student name is JohnDoe
2. student roll is 101
3. student id is 1
4. student grade is 12
5. student mobile no is 1234567890
6. student email is john@example.com
7. student address is NewYork
8. student gender is Male
9. student section is A
10. student stream is Science

Limitations

Buffer Overflow Risk: Functions like scanf() and lack of boundary checks may cause buffer overflows.

Concurrency: The system does not handle multiple simultaneous users or file locks.

Platform Dependency: Uses conio.h, which may not be compatible with non-Windows platforms.

Future Enhancements

Use fgets() for safer input handling.

Implement proper validations for inputs.

Add a graphical user interface (GUI).

Use databases like MySQL for better scalability.

License

This project is licensed under the MIT License - see the LICENSE file for details.

Author

Prashant Adhikari

