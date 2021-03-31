#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/student.h"
#include "../include/student-extra.h"

// funckija za random id
void setId(Student * const student) {
	srand(time(0)); // generise random bazen (pool) brojeva
	int id;
	do {
		id = (rand() % (MAX_ID - MIN_ID + 1) + MIN_ID); // generise random broj
	} while (idExists(id)); // sve dok postoji, tjst ne ponavljaju se isti
	student->id_ = id;
}

// postavljamo email studenta
void setEmail(Student * const student) {
	char email[EMAIL_LENGTH];
	do {
		printf("* Email: ");
		scanf("%s", email);
		if (emailExists(email))
			printf("!! Email vec postoji !!\n"); // ako email postoji poruka
	} while (emailExists(email)); // dokle god email postoji nastavljamo
	strcpy(student->email_, email);
}

void setPassword(Student * const student) {
	char password[MAX_PASSWORD];
	do {
	printf("* Password: ");
		scanf("%s", password);
	} while (notValidPassword(password)); // unosimo sifru dok je validne duzine
	strcpy(student->password_, password);
}

// postavljamo ime
void setFirstName(Student * const student) {
	char fName[FIRST_LENGTH];
	printf("* First name: ");
	scanf("%s", fName);
	strcpy(student->firsName_, fName);
}

// prezime
void setLastName(Student * const student) {
	char lName[LAST_LENGTH];
	printf("* Last name: ");
	scanf("%s", lName);
	strcpy(student->lastName_, lName);
}

// godine
void setAge(Student * const student) {
	int age;
	do {
		printf("* Age: ");
		scanf("%d", &age);
		if (notValidAge(age))
			printf("!! Godine moraju biti izmedju %d i %d !!\n", MIN_AGE, MAX_AGE);
	} while (notValidAge(age)); // dokle god su godine ispod min definistanih ili vece od max def ponavljamo
	student->age_ = age;
}
