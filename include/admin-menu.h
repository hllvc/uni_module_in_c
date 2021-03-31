#ifndef __ADMIN_MENU_H__
#define __ADMIN_MENU_H__

// predefinisane konstante za odabir koje se mogu promijenit
#define CHOICE1 '1'
#define CHOICE2 '2'
#define CHOICE3 '3'
#define CHOICE4 '4'
#define CHOICE5 '5'
#define CHOICEr 'r'
#define CHOICE0 '0'

#include "../include/student.h"

// varijable koje koristimo u funkcijama ali su definisane npr u main
extern int numberOfStudents;
extern Student allStudents[];

// lista funkcija
void adminMenu(void);
void addStudent(void);
void editStudent(void);
void deleteStudent(void);
void listStudents(Student const allStudents[]);
void createExam(void);

#endif // __ADMIN_MENU_H__
