#ifndef __ADMIN_MENU_H__
#define __ADMIN_MENU_H__

#define CHOICE1 '1'
#define CHOICE2 '2'
#define CHOICE3 '3'
#define CHOICE4 '4'
#define CHOICE5 '5'
#define CHOICE0 '0'

#include "../include/student.h"

extern int numberOfStudents;
extern Student allStudents[];

void adminMenu(void);
void addStudent(void);
void editStudent(void);
void deleteStudent(void);
void listStudents(Student const allStudents[]);
void createExam(void);

#endif // __ADMIN_MENU_H__
