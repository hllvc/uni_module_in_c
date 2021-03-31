#ifndef __STUDENT_EXSTRA_H__
#define __STUDENT_EXSTRA_H__

#include "../include/student.h"

// varijable definisane negdje drugo
extern Student allStudents[];
extern int numberOfStudents;

// funckije
const int emailExists(char const * const email);
const int idExists(int const id);
const int notValidPassword(char const * const password);
const int notValidAge(int const age);

void printStudent(Student const * const student);

void gradeStudent(Student * const student);
void appendPoints(Student * const student, double const points);
void resetExamData(Student * const student);

#endif // __STUDENT_EXSTRA_H__
