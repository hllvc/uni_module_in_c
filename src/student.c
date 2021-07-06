#include "../include/student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/student-extra.h"

void generateId(Student* const student) {
  srand(time(0));
  int id;
  do {
    id = (rand() % (MAX_ID - MIN_ID + 1) + MIN_ID);
  } while (checkExistingId(id));
  student->id_ = id;
}

void emailInput(Student* const student) {
  char email[EMAIL];
  do {
    printf("Email\n> ");
    scanf("%s", email);
    if (checkExistingEmail(email)) printf(">> Email already exists <<\n");
  } while (checkExistingEmail(email));
  strcpy(student->email_, email);
}

void passInput(Student* const student) {
  char password[MAX_PASS];
  do {
    printf("Password\n> ");
    scanf("%s", password);
  } while (notValidPassword(password));
  strcpy(student->password_, password);
}

void firstNameInput(Student* const student) {
  char fName[FIRST_NAME];
  printf("First name\n> ");
  scanf("%s", fName);
  strcpy(student->firs_name_, fName);
}

void lastNameInput(Student* const student) {
  char lName[LAST_NAME];
  printf("Last name\n> ");
  scanf("%s", lName);
  strcpy(student->last_name_, lName);
}

void ageInput(Student* const student) {
  int age;
  do {
    printf("Age> ");
    scanf("%d", &age);
    if (notValidAge(age))
      printf(">> Age not valid! Enter age between %d & %d <<\n", MIN_AGE,
	     MAX_AGE);
  } while (notValidAge(age));
  student->age_ = age;
}
