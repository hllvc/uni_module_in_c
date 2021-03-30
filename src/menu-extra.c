#include <stdio.h>

#include "../include/menu-extra.h"

extern int numberOfStudents;

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
		while(fread(allStudents + numberOfStudents++, sizeof(Student), 1, file));
	fclose(file);
}
