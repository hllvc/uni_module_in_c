#ifndef __STUDENT_MENU_H__
#define __STUDENT_MENU_H__

#define CHOICE1 '1'
#define CHOICE2 '2'
#define CHOICE0 '0'

#include "../include/student.h"

void studentMenu(Student const * const student);
void showProfile(Student const * const student);
void startExam(Student const * const student);

#endif // __STUDENT_MENU_H__
