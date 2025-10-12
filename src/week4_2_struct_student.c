/*
 * week4_2_struct_student.c
 * Author: Mehmet Taha Ünal
 * Student ID: 231AMB077
 * Description:
 *   Defines a 'Student' structure with name, id, and grade fields.
 *   Creates two student records (Defne Goker and Emir Olgun) and prints their
 * information.
 */

#include <stdio.h>
#include <string.h>

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
}
