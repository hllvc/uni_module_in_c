#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/menu-extra.h"
#include "../include/student-extra.h"

Student * const login(void) {
	Student * const student = getStudent();
	char password[MAX_PASSWORD];
	while (1) {
		printf("Password: ");
		scanf("%s", password);
		for (int i = 0; i < numberOfStudents; i++) {
			if (!strcmp(student->password_, password))
				return student;
		}
		printf("Pogresna sifra!\n");
	}
}

const int isAdmin(Student const * const student) {
	if (student->id_ == 1)
		return 1;
	return 0;
}

Student * const getStudent(void) {
	Student * student;
	char email[EMAIL_LENGTH];
	while (1) {
		printf("\nEmail: ");
		scanf("%s", email);
		if (!emailExists(email))
			printf("Ucenik sa unesenim emailom ne postoji!\n");
		else {
			for (int i = 0; i < numberOfStudents; i++)
				if (!strcmp((allStudents + i)->email_, email)) {
					return allStudents + i;
				}
		}
	}
}

void updateData() {
	resetData();
	for (int i = 0; i < numberOfStudents; i++) {
		if ((allStudents + i)->id_ != 0)
			appendStudent(allStudents + i);
	}
}

void resetData(void) {
	fclose(fopen("students.dat", "wb+"));
	Student student = {1, "admin", "admin"};
	FILE * file = fopen("students.dat", "wb+");
	fwrite(&student, sizeof(Student), 1, file);
	fclose(file);
}

void appendStudent(Student const * const student) {
	FILE * file = fopen("students.dat", "ab+");
	if (file != NULL)
		fwrite(student, sizeof(Student), 1, file);
	fclose(file);
}

void loadStudents(Student allStudents[]) {
	numberOfStudents = 0;
	FILE * file = fopen("students.dat", "rb+");
	if (file == NULL)
		resetData();
	if (file != NULL)
		while(fread(allStudents + numberOfStudents, sizeof(Student), 1, file)) {
			numberOfStudents++;
		}
	fclose(file);
}
