/*
 * week4_3_struct_database.c
<<<<<<< HEAD
 * Author: Mehmet Taha Ünal
 * Student ID: 231AMB077
 * Description:
 *   Simple in-memory database using an array of structs.
 *   Allocates memory dynamically for multiple Student records,
 *   reads data from the user, and displays all student records in a table.
=======
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  students = (struct Student *)malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d (Name ID Grade): ", i + 1);
    scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade);
  }

  printf("\n%-6s %-15s %-6s\n", "ID", "Name", "Grade");
  for (int i = 0; i < n; i++) {
    printf("%-6d %-15s %-6.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  free(students);
  return 0;
=======
// TODO: Define struct Student with fields name, id, grade

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // TODO: Allocate memory for n Student structs using malloc

    // TODO: Read student data in a loop

    // TODO: Display all student records in formatted output

    // Optional: Compute average grade or find top student

    // TODO: Free allocated memory

    return 0;
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
