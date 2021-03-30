#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "student.h"

// function which generates random id for student
void setId(Student * const student) {
	srand(time(0));
	int randomId = (rand() % (MAX_ID - MIN_ID + 1) + MIN_ID);
	student->id_ = randomId;
}

void setEmail(Student * const student) {
	char email[EMAIL_LENGTH];
	scanf("%s", email);
	strcpy(student->email_, email);
}

void setPassword(Student * const student) {
	char password[MAX_PASSWORD];
	scanf("%s", password);
	strcpy(student->password_, password);
}

void setFirstName(Student * const student) {
	char fName[FIRST_LENGTH];
	scanf("%s", fName);
	strcpy(student->firsName_, fName);
}

void setLastName(Student * const student) {
	char lName[LAST_LENGTH];
	scanf("%s", lName);
	strcpy(student->lastName_, lName);
}

void setAge(Student * const student) {
	int age;
	scanf("%d", age);
	student->age_ = age;
}

void setGrade(Student * const student) {
	int grade;
	scanf("%d", grade);
	student->grade_ = grade;
}

void setNumberOfPoints(Student * const student) {
	double points;
	scanf("%f", points);
	student->numberOfPoints_ = points;
}

void printStudent(Student const * const student) {
	printf("ID: %d\n", student->id_);
	printf("Ime: %s\n", student->firsName_);
	printf("Prezime: %s\n", student->lastName_);
}
