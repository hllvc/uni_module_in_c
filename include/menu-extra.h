#ifndef __MENU_EXTRA_H__
#define __MENU_EXTRA_H__

#include "../include/exam.h"
#include "../include/student.h"

extern int studentsNum;
extern int questionsNum;
extern Student studnets[];

Student* const login(void);
const int checkIfAdmin(Student const* const student);
const int wrongAnswer(int const answer);
const int checkTestSize(int const length);
Student* const getStudent(void);
void updateData();
void appendStudent(Student const* const student);
void appendAnswer(char const filename[], Answer const* const answer);
void saveTest(Question exam[], int const examLength);
void resetData(void);
void loadStudents(Student allStudents[]);
void loadTest(Question exam[]);
void getQuestion(Answer answers[], int const number);
void createDir();

#endif	// __MENU_EXTRA_H__
