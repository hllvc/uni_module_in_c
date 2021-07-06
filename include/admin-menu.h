#ifndef __ADMIN_MENU_H__
#define __ADMIN_MENU_H__

#define C_1 '1'
#define C_2 '2'
#define C_3 '3'
#define C_4 '4'
#define C_5 '5'
#define C_r 'r'
#define C_0 '0'

#include "../include/student.h"

extern int studentsNum;
extern Student students[];

void admin(void);
void enrollStudent(void);
void removeStudent(void);
void editStudent(void);
void listAllStudents(Student const allStudents[]);
void generateExam(void);

#endif	// __ADMIN_MENU_H__
