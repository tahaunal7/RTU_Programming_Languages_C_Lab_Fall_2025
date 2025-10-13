// week5_task3_student_management_system.c
// Author: Mehmet Taha Ünal
// Student ID: 231AMB077
// Week 5 – Files & Modular Programming
// Task 3: Student Management System 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 100
#define NAME_LIMIT 60
#define FILE_PATH "students.txt"

typedef struct {
    char fullname[NAME_LIMIT];
    int studentID;
    float grade;
} Student;

int import_data(Student arr[]);
void export_data(Student arr[], int count);
void register_student(Student arr[], int *count);
void display_students(Student arr[], int count);

int main(void) {
    Student db[MAX_COUNT];
    int total = 0;
    int option;

    printf(">>> Loading existing student data...\n");
    total = import_data(db);
    printf(">>> %d record(s) found.\n", total);

    do {
        printf("\n==== STUDENT DATABASE ====\n");
        printf("1. Show all students\n");
        printf("2. Register new student\n");
        printf("3. Save & Exit\n");
        printf("Choose: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input, try again.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch (option) {
            case 1:
                display_students(db, total);
                break;
            case 2:
                register_student(db, &total);
                break;
            case 3:
                export_data(db, total);
                printf("All changes saved. Exiting...\n");
                break;
            default:
                printf("Invalid selection, please choose 1–3.\n");
        }
    } while (option != 3);

    return 0;
}

// -----------------------------------------------------

int import_data(Student arr[]) {
    FILE *fp = fopen(FILE_PATH, "r");
    if (!fp) {
        printf("No existing file found. Starting fresh.\n");
        return 0;
    }

    int i = 0;
    while (i < MAX_COUNT &&
           fscanf(fp, "%59s %d %f", arr[i].fullname, &arr[i].studentID, &arr[i].grade) == 3) {
        i++;
    }

    fclose(fp);
    return i;
}

void export_data(Student arr[], int count) {
    FILE *fp = fopen(FILE_PATH, "w");
    if (!fp) {
        fprintf(stderr, "Error: cannot write to %s\n", FILE_PATH);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].fullname, arr[i].studentID, arr[i].grade);
    }

    fclose(fp);
    printf(">>> %d record(s) saved to file.\n", count);
}

void register_student(Student arr[], int *count) {
    if (*count >= MAX_COUNT) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    Student temp;
    printf("Enter full name (no spaces): ");
    scanf("%59s", temp.fullname);
    printf("Enter student ID: ");
    scanf("%d", &temp.studentID);
    printf("Enter GPA: ");
    scanf("%f", &temp.grade);

    arr[*count] = temp;
    (*count)++;

    printf("Student '%s' successfully added!\n", temp.fullname);
}

void display_students(Student arr[], int count) {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("[%02d] %-15s | ID: %d | GPA: %.2f\n",
               i + 1, arr[i].fullname, arr[i].studentID, arr[i].grade);
    }
    printf("--------------------\n");
}
