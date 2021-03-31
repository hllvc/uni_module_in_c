#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/menu-extra.h"
#include "../include/student-extra.h"
#include "../include/exam.h"

Student * const login(void) {
	printf("\n----------------------");
	printf("\nLOGIN MENU\n");
	Student * const student = getStudent();
	char password[MAX_PASSWORD];
	while (1) {
		printf("* Password: ");
		scanf("%s", password);
		for (int i = 0; i < numberOfStudents; i++) {
			if (!strcmp(student->password_, password))
				return student;
		}
		printf(">------------------<\n");
		printf("!! Pogresna sifra !!");
		printf("\n>------------------<\n");
	}
}

const int notValidExamLength(int const length) {
	if (length < 0 || length > EXAM_LENGTH) {
		printf("\n!! Maksimalan broj pitanja je %d !!\n", EXAM_LENGTH);
		return 1;
	}
	return 0;
}

const int notValidAnswer(int const answer) {
	if (answer < 0 || answer > NUMBER_OF_ANSWERS) {
		printf("\n!! Pogresan unos !!\n");
		return 1;
	}
	return 0;
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
		printf("\n* Email: ");
		scanf("%s", email);
		if (!emailExists(email)) {
			printf(">-----------------------------------------<\n");
			printf("!! Ucenik sa unesenim emailom ne postoji !!");
			printf("\n>-----------------------------------------<");
		}
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

void appendAnswer(char const filename[], Answer const * const answer) {
	FILE * file = fopen(filename, "ab+");
	if (file != NULL)
		fwrite(answer, sizeof(Answer), 1, file);
	fclose(file);
}

void saveExam(Question exam[], int const examLength) {
	FILE * file = fopen("exam/exam.dat", "wb+");
	if (file != NULL)
		for (int i = 0; i < examLength; i++)
			fwrite(exam + i, sizeof(Question), 1, file);
	fclose(file);
}

void loadStudents(Student allStudents[]) {
	numberOfStudents = 0;
	FILE * file = fopen("students.dat", "rb+");
	if (file == NULL) {
		resetData();
		make_directory();
	}
	if (file != NULL)
		while(fread(allStudents + numberOfStudents, sizeof(Student), 1, file)) {
			numberOfStudents++;
		}
	fclose(file);
}

void loadExam(Question exam[]) {
	numberOfQuestions = 0;
	FILE * file = fopen("exam/exam.dat", "rb+");
	if (file == NULL)
		return;
	if (file != NULL)
		while(fread(exam + numberOfQuestions, sizeof(Question), 1, file))
			numberOfQuestions++;
	fclose(file);
}

void getQuestion(Answer answers[], int const number) {
	char filename[16];
	sprintf(filename, "exam/Q&A_%d.dat", number);
	int counter = 0;
	FILE * file = fopen(filename, "rb+");
	if (file != NULL)
		while(fread(answers + counter, sizeof(Answer), 1, file))
			counter++;
}

void make_directory() {
   #ifdef __linux__
       mkdir("exam", 0755); 
   #else
       _mkdir("exam");
   #endif
}
