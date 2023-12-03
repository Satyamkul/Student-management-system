#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[50];
    int roll_number;
    char course[50];
} student;

student students[100];
int num_students = 0;

void add_student() {
    student s;
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student roll number: ");
    scanf("%d", &s.roll_number);
    printf("Enter student course: ");
    scanf("%s", s.course);

    students[num_students++] = s;
}

void delete_student() {
    int roll_number;
    printf("Enter student roll number to delete: ");
    scanf("%d", &roll_number);

    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll_number) {
            break;
        }
    }

    if (i == num_students) {
        printf("Student not found.\n");
        return;
    }

    for (int j = i; j < num_students - 1; j++) {
        students[j] = students[j + 1];
    }

    num_students--;
}

void update_student() {
    int roll_number;
    printf("Enter student roll number to update: ");
    scanf("%d", &roll_number);

    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll_number) {
            break;
        }
    }

    if (i == num_students) {
        printf("Student not found.\n");
        return;
    }

    student s;
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student course: ");
    scanf("%s", s.course);

    students[i] = s;
}

void display_student() {
    int roll_number;
    printf("Enter student roll number to display: ");
    scanf("%d", &roll_number);

    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll_number) {
            break;
        }
    }

    if (i == num_students) {
        printf("Student not found.\n");
        return;
    }

    student s = students[i];
    printf("Student name: %s\n", s.name);
    printf("Student roll number: %d\n", s.roll_number);
    printf("Student course: %s\n", s.course);
}

void display_all_students() {
    for (int i = 0; i < num_students; i++) {
        student s = students[i];
        printf("Student name: %s\n", s.name);
        printf("Student roll number: %d\n", s.roll_number);
        printf("Student course: %s\n", s.course);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("Student Management System\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Update student\n");
        printf("4. Display student\n");
        printf("5. Display all students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                update_student();
                break;
            case 4:
                display_student();
                break;
            case 5:
                display_all_students();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    while (choice != 6);
}
