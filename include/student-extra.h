#ifndef __STUDENT_EXSTRA_H__
#define __STUDENT_EXSTRA_H__

#include "../include/student.h"

extern Student students[];
extern int studentsNum;

const int checkExistingEmail(char const* const email);
const int checkExistingId(int const id);
const int notValidPassword(char const* const password);
const int notValidAge(int const age);

void showStudent(Student const* const student);

void gradeStudent(Student* const student);
void appendPoints(Student* const student, double const points);
void resetTestData(Student* const student);

#endif	// __STUDENT_EXSTRA_H__
