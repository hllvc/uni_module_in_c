#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/student-extra.h"

const int emailExists(char const * const email) { // provjeraje da li email postoji i vraca 1 ili 0
	for (int i = 0; i < numberOfStudents; i++) {
		if (!strcmp((allStudents + i)->email_, email))
			return 1;
	}
	return 0;
}

const int idExists(int const id) { // provjeraje da li postoji id i vraca 1 ili 0
	for (int i = 0; i < numberOfStudents; i++)
		if ((allStudents + i)->id_ == id)
			return 1;
	return 0;
}

const int notValidPassword(char const * const password) { // provjeraje duzinu sifre i vraca 1 ili 0
	int const passwordLength = strlen(password);
	if (passwordLength > MAX_PASSWORD || passwordLength < MIN_PASSWORD)
		return 1;
	return 0;
}

const int notValidAge(int const age) { // provjera validnost godina po min i max godine
	if (age > MAX_AGE || age < MIN_AGE)
		return 1;
	return 0;
}

void printStudent(Student const * const student) { // formatirano ispisivanje atributa studenta
	printf("\n----------------------");
	printf("\nFirst name: %s", student->firsName_);
	printf("\nLast name: %s", student->lastName_);
	printf("\nEmail: %s", student->email_);
	printf("\nAge: %d", student->age_);
	printf("\nNumber of points: %.2lf", student->numberOfPoints_);
	printf("\nGrade: %d", student->grade_);
	printf("\nID: %lu", student->id_);
}

void resetExamData(Student * const student) { // resetuje bodove i ocjenu studenta
	student->numberOfPoints_ = 0;
	student->grade_ = 0;
}

void appendPoints(Student * const student, double const points) { // dodaje bodove studenta
	student->numberOfPoints_ += points;
}

void gradeStudent(Student * const student) { // ocjenjuje i prikazuje bodove i ocjenu po skali ispod
	double points = student->numberOfPoints_;
	if (points > 95)
		student->grade_ = 10;
	else if (points > 85 && points < 95)
		student->grade_ = 9;
	else if (points > 75 && points < 85)
		student->grade_ = 8;
	else if (points > 65 && points < 75)
		student->grade_ = 7;
	else if (points > 55 && points < 65)
		student->grade_ = 6;
	else student->grade_ = 0;
	printf("\nBroj poena: %.2lf", student->numberOfPoints_);
	printf("\nOcjena: %d", student->grade_);
}
