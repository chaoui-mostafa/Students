#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
typedef struct {
    int id;
    char name[50];
    int age;
    float grade;
} Student;

// Menu display function
void menu() {
    printf("\n===== Student Management System =====\n");
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new student
void addStudent() {
    FILE *fp = fopen("students.dat", "ab"); // open file in append binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter student age: ");
    scanf("%d", &s.age);
    printf("Enter student grade: ");
    scanf("%f", &s.grade);

    fwrite(&s, sizeof(Student), 1, fp); // write student to file
    fclose(fp);
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No data found.\n");
        return;
    }

    Student s;
    printf("\n--- Student List ---\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Grade: %.2f\n", s.id, s.name, s.age, s.grade);
    }
    fclose(fp);
}

// Function to search for a student by ID
void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No data found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Student found:\n");
            printf("Name: %s | Age: %d | Grade: %.2f\n", s.name, s.age, s.grade);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
    fclose(fp);
}

// Function to update student info
void updateStudent() {
    FILE *fp = fopen("students.dat", "rb+");
    if (fp == NULL) {
        printf("No data found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new age: ");
            scanf("%d", &s.age);
            printf("Enter new grade: ");
            scanf("%f", &s.grade);

            fseek(fp, -sizeof(Student), SEEK_CUR); // move pointer back
            fwrite(&s, sizeof(Student), 1, fp);    // overwrite
            found = 1;
            printf("Student updated successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}

// Function to delete a student by ID
void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No data found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.dat", "wb");
    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Student deleted successfully.\n");
    else
        printf("Student not found.\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
