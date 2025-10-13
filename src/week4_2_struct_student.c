/*
 * week4_2_struct_student.c
<<<<<<< HEAD
 * Author: Mehmet Taha Ünal
 * Student ID: 231AMB077
 * Description:
 *   Defines a 'Student' structure with name, id, and grade fields.
 *   Creates two student records (Defne Goker and Emir Olgun) and prints their
 * information.
=======
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
 */

#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student s1, s2;

  strcpy(s1.name, "Defne Goker");
  s1.id = 1001;
  s1.grade = 9.1f;

  strcpy(s2.name, "Emir Olgun");
  s2.id = 1002;
  s2.grade = 8.7f;

  printf("Student 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
  printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

  return 0;
=======
// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
// Example:
// struct Student {
//     char name[50];
//     int id;
//     float grade;
// };

int main(void) {
    // TODO: Declare one or more Student variables

    // TODO: Assign values (either manually or via scanf)

    // TODO: Print struct contents using printf

    return 0;
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
