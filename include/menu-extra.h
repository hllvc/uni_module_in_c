#ifndef __MENU_EXTRA_H__
#define __MENU_EXTRA_H__

#include "../include/student.h"
#include "../include/exam.h"

extern int numberOfStudents;
extern Student allStudents[];

Student * const login(void);
const int isAdmin(Student const * const student);
Student * const getStudent(void);
void updateData();
void appendStudent(Student const * const student);
void appendAnswer(char const filename[], Answer const * const answer);
void saveExam(Question exam[], int const examLength);
void resetData(void);
void loadStudents(Student allStudents[]);
void loadExam(Question exam[]);

#endif // __MENU_EXTRA_H__
