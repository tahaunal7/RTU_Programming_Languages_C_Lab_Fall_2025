// week5_task2_struct_save_load.c
// Author: Mehmet Taha Ünal
// Student ID: 231AMB077
// Week 5 – Files & Modular Programming
// Task 2: Save and Load a Student Record (text file version)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char fullName[50];
    int age;
    float gpa;
} Student;

int save_student(const char *fname, const Student *s);
int load_student(const char *fname, Student *s);

int main(void) {
    Student original = {"ElifNaz", 21, 3.87f};
    Student loaded;
    const char *filename = "student_record.txt";

    printf(">>> Writing student to '%s'\n", filename);
    if (save_student(filename, &original) != 0) {
        fprintf(stderr, "Error: could not save data!\n");
        return EXIT_FAILURE;
    }

    printf(">>> Reading data back from file...\n");
    if (load_student(filename, &loaded) != 0) {
        fprintf(stderr, "Error: could not load data!\n");
        return EXIT_FAILURE;
    }

    printf("\n>>> Loaded Student Record <<<\n");
    printf("Name: %s\n", loaded.fullName);
    printf("Age: %d\n", loaded.age);
    printf("GPA: %.2f\n", loaded.gpa);

    Student second = {"DefneGoker", 23, 3.94f};
    save_student("student_record2.txt", &second);
    printf("\nSaved another record: %s, Age %d, GPA %.2f\n",
           second.fullName, second.age, second.gpa);

    return EXIT_SUCCESS;
}

int save_student(const char *fname, const Student *s) {
    FILE *fp = fopen(fname, "w");
    if (!fp) return 1;

    fprintf(fp, "%s %d %.2f\n", s->fullName, s->age, s->gpa);
    fclose(fp);
    return 0;
}

int load_student(const char *fname, Student *s) {
    FILE *fp = fopen(fname, "r");
    if (!fp) return 1;

    if (fscanf(fp, "%49s %d %f", s->fullName, &s->age, &s->gpa) != 3) {
        fclose(fp);
        return 2;
    }

    fclose(fp);
    return 0;
}
