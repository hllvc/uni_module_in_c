#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/menu-extra.h"
#include "../include/student-extra.h"

Student * const login(void) {
	Student * const student = malloc(sizeof(Student));
	char email[EMAIL_LENGTH], password[MAX_PASSWORD];
	while (1) {
		printf("\nEmail: ");
		scanf("%s", email);
		if (!emailExists(email))
			printf("Ucenik sa unesenim emailom ne postoji!\n");
		else {
			while (1) {
				printf("Password: ");
				scanf("%s", password);
				for (int i = 0; i < numberOfStudents; i++) {
					if (!strcmp((allStudents + i)->password_, password))
						return (allStudents + i);
				}
				printf("Pogresna sifra!\n");
			}
		}
	}
	return student;
}

const int isAdmin(Student const * const student) {
	if (student->id_ == 1)
		return 1;
	return 0;
}

void resetData(void) {
	Student student;
	setEmail(&student);
	setPassword(&student);
	student.id_ = 1;
	FILE * file = fopen("students.dat", "wb+");
	if (file != NULL)
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
		fclose(fopen("students.dat", "wb+"));
	if (file != NULL)
		while(fread(allStudents + numberOfStudents, sizeof(Student), 1, file)) {
			numberOfStudents++;
		}
	fclose(file);
}
