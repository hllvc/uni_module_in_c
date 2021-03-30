#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/student.h"
#include "../include/student-extra.h"

// function which generates random id for student
void setId(Student * const student) {
	srand(time(0));
	int id;
	do {
		id = (rand() % (MAX_ID - MIN_ID + 1) + MIN_ID);
	} while (idExists(id));
	student->id_ = id;
}

void setEmail(Student * const student) {
	char email[EMAIL_LENGTH];
	do {
	printf("Email: ");
		scanf("%s", email);
	} while (emailExists(email));
	strcpy(student->email_, email);
}

void setPassword(Student * const student) {
	char password[MAX_PASSWORD];
	do {
	printf("Password: ");
		scanf("%s", password);
	} while (notValidPassword(password));
	strcpy(student->password_, password);
}

void setFirstName(Student * const student) {
	char fName[FIRST_LENGTH];
	printf("First name: ");
	scanf("%s", fName);
	strcpy(student->firsName_, fName);
}

void setLastName(Student * const student) {
	char lName[LAST_LENGTH];
	printf("Last name: ");
	scanf("%s", lName);
	strcpy(student->lastName_, lName);
}

void setAge(Student * const student) {
	int age;
	do {
		scanf("%d", &age);
	} while (notValidAge(age));
	student->age_ = age;
}

void setGrade(Student * const student) {
	int grade;
	scanf("%d", &grade);
	student->grade_ = grade;
}

void setNumberOfPoints(Student * const student) {
	double points;
	scanf("%lf", &points);
	student->numberOfPoints_ = points;
}
