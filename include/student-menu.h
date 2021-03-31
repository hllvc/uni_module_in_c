#ifndef __STUDENT_MENU_H__
#define __STUDENT_MENU_H__

// constante vrijednosti za odabir
#define CHOICE1 '1'
#define CHOICE2 '2'
#define CHOICE0 '0'

#include "../include/student.h"

// varijabla definisana negdje drugo
extern int numberOfQuestions;

// funkcije
void studentMenu(Student * const student);
void showProfile(Student const * const student);
void startExam(Student * const student);

#endif // __STUDENT_MENU_H__
