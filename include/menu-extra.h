#ifndef __MENU_EXTRA_H__
#define __MENU_EXTRA_H__

#include "../include/student.h"

extern int numberOfStudents;
extern Student allStudents[];

Student * const login();
const int isAdmin(Student const * const student);
void appendStudent(Student const * const student);
void loadStudents(Student allStudents[]);

#endif // __MENU_EXTRA_H__
