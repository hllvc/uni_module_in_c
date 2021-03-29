#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "student.h"

// function which generates random id for student
void setId(Student const * const student) {
	srand(time(0));
	int randomId = (radn() % (MAX_ID - MIN_ID + 1) + MIN_ID);
	student->id_ = randomId;
}

void setEmail(Student const * const student) {
	char email[EMAIL_LENGTH];
	scanf("%s", email);
	student->email_ = email;
}

void setPassword(Student const * const student) {
	char password[MAX_PASSWORD];
	scanf("%s", password);
	student->password_ = password;
}

void setFirstName(Student const * const student) {
	char fName[FIRST_LENGTH];
	scanf("%s", fName);
	student->firsName_ = fName;
}

void setLastName(Student const * const student) {
	char lName[LAST_LENGTH];
	scanf("%s", lName);
	student->lastName_ = lName;
}

void setAge(Student const * const student) {
	int age;
	scanf("%d", age);
	student->age_ = age;
}

void setGrade(Student const * const student) {
	int grade;
	scanf("%d", grade);
	student->grade_ = grade;
}

void setNumberOfPoints(Student const * const student) {
	double points;
	scanf("%f", points);
	student->numberOfPoints_ = points;
}
