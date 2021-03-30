#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/student-extra.h"

const int emailExists(char const * const email) {
	for (int i = 0; i < numberOfStudents; i++) {
		if (!strcmp((allStudents + i)->email_, email))
			return 1;
	}
	return 0;
}

const int idExists(int const id) {
	for (int i = 0; i < numberOfStudents; i++)
		if ((allStudents + i)->id_ == id)
			return 1;
	return 0;
}

const int notValidPassword(char const * const password) {
	int const passwordLength = strlen(password);
	if (passwordLength > MAX_PASSWORD || passwordLength < MIN_PASSWORD)
		return 1;
	return 0;
}

const int notValidAge(int const age) {
	if (age > MAX_AGE || age < MIN_AGE)
		return 1;
	return 0;
}

void printStudent(Student const * const student) {
	printf("\n----------------------");
	printf("\nFirst name: %s", student->firsName_);
	printf("\nLast name: %s", student->lastName_);
	printf("\nEmail: %s", student->email_);
	printf("\nID: %lu", student->id_);
}
