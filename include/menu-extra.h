#ifndef __MENU_EXTRA_H__
#define __MENU_EXTRA_H__

#include "../include/student.h"

extern int numberOfStudents;
extern Student allStudents[];

Student * const login(void);
const int isAdmin(Student const * const student);
void appendStudent(Student const * const student);
void resetData(void);
void loadStudents(Student allStudents[]);

#endif // __MENU_EXTRA_H__
