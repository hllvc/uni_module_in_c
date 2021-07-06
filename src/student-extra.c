#include "../include/student-extra.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int checkExistingEmail(char const* const email) {
  for (int i = 0; i < studentsNum; i++) {
    if (!strcmp((students + i)->email_, email)) return 1;
  }
  return 0;
}

const int checkExistingId(int const id) {
  for (int i = 0; i < studentsNum; i++)
    if ((students + i)->id_ == id) return 1;
  return 0;
}

const int notValidPassword(char const* const password) {
  int const passwordLength = strlen(password);
  if (passwordLength > MAX_PASS || passwordLength < MIN_PASS) return 1;
  return 0;
}

const int notValidAge(int const age) {
  if (age > MAX_AGE || age < MIN_AGE) return 1;
  return 0;
}

void showStudent(Student const* const student) {
  printf("\n----------------------");
  printf("\nID -> %lu\n", student->id_);
  printf("\nFirst name -> %s", student->firs_name_);
  printf("\nLast name -> %s", student->last_name_);
  printf("\nEmail -> %s", student->email_);
  printf("\nAge -> %d", student->age_);
  printf("\nNumber of points -> %.2lf\n", student->numberOfPoints_);
  printf("\nGrade -> %d", student->grade_);
}

void resetTestData(Student* const student) {
  student->numberOfPoints_ = 0;
  student->grade_ = 0;
}

void appendPoints(Student* const student, double const points) {
  student->numberOfPoints_ += points;
}

void gradeStudent(Student* const student) {
  double points = student->numberOfPoints_;
  if (points > 95)
    student->grade_ = 10;
  else if (points > 85 && points < 95)
    student->grade_ = 9;
  else if (points > 75 && points < 85)
    student->grade_ = 8;
  else if (points > 65 && points < 75)
    student->grade_ = 7;
  else if (points > 55 && points < 65)
    student->grade_ = 6;
  else
    student->grade_ = 0;
  printf("\nNumber of points -> %.2lf", student->numberOfPoints_);
  printf("\nGrade -> %d", student->grade_);
}
