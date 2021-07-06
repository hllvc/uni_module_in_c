#ifndef __STUDENT_MENU_H__
#define __STUDENT_MENU_H__

#define C_1 '1'
#define C_2 '2'
#define C_0 '0'

#include "../include/student.h"

extern int numberOfQuestions;

void studentBoard(Student* const student);
void profile(Student const* const student);
void test(Student* const student);

#endif	// __STUDENT_MENU_H__
