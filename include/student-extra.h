#ifndef __STUDENT_EXSTRA_H__
#define __STUDENT_EXSTRA_H__

#include "../include/student.h"

extern Student allStudents[];
extern int numberOfStudents;

const int emailExists(char const * const email);
const int idExists(int const id);
const int notValidPassword(char const * const password);
const int notValidAge(int const age);

void printStudent(Student const * const student);

#endif // __STUDENT_EXSTRA_H__
