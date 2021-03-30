#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/admin-menu.h"
#include "../include/student.h"
#include "../include/menu-extra.h"
#include "../include/student-extra.h"
#include "../include/exam.h"

void adminMenu(void) {
	char choice;
	while (1) {
		printf("\n\n----------------------");
		printf("\nADMIN MENU\n\n");
		printf("(%c) Novi student\n", CHOICE1);
		printf("(%c) Uredi studenta\n", CHOICE2);
		printf("(%c) Obrisi studenta\n", CHOICE3);
		printf("(%c) Prikazi sve studente\n", CHOICE4);
		printf("(%c) Kreiraj ispit\n", CHOICE5);
		printf("\n(%c) Resetuj sve podatke\n", CHOICEr);

		printf("\n(%c) Kraj\n", CHOICE0);

		printf("\n* Odabir: ");
		scanf(" %c", &choice);

		switch (choice) {
			case CHOICE1:
				addStudent();
				loadStudents(allStudents);
				break;
			case CHOICE2:
				editStudent();
				break;
			case CHOICE3:
				deleteStudent();
				break;
			case CHOICE4:
				listStudents(allStudents);
				break;
			case CHOICE5:
				createExam();
				break;
			case CHOICEr:
				resetData();
				break;
			case CHOICE0:
				printf("!! Gasenje programa ...");
				exit(0);
			default:
				printf("\n>-----------------<\n");
				printf("!! Pogresan unos !!");
				printf("\n>-----------------<");
		}
	};


}

void addStudent(void) {
	printf("\n-------------------\n");
	printf("Novi student");
	printf("\n-------------------\n");
	Student student = {0, "", "", "", "", 0, 0, 0};
	setFirstName(&student);
	setLastName(&student);
	setAge(&student);
	setEmail(&student);
	setPassword(&student);
	setId(&student);
	appendStudent(&student);
	numberOfStudents++;
	printf("\n-------------------\n");
	printf("!! Uspijesno registrovan novi student !!");
	printf("\n-------------------");
}

void editStudent(void) {
	printf("\n-------------------\n");
	printf("Uredi studenta");
	printf("\n-------------------\n");
	Student * const student = getStudent();
	printf("\n!! Unesite nove podatke !!\n\n");
	setFirstName(student);
	setLastName(student);
	updateData();
	printf("\n-------------------\n");
	printf("!! Uspijesno uredjen student %s !!", student->email_);
	printf("\n-------------------");
}

void deleteStudent(void) {
	printf("\n-------------------\n");
	printf("Obrisi studenta");
	printf("\n-------------------\n");
	Student * const student = getStudent();
	student->id_ = 0;
	updateData();
	numberOfStudents--;
	printf("\n-------------------\n");
	printf("!! Student %s je obrisan sa liste !!", student->email_);
	printf("\n-------------------");
}

void listStudents(Student const allStudents[]) {
	printf("\n-------------------\n");
	printf("Lista svih studenata");
	printf("\n-------------------\n");
	for (int i = 0; i < numberOfStudents; i++) {
		if (!isAdmin(allStudents + i))
			printStudent(allStudents + i);
	}
}
void createExam(void) {
	printf("\n-------------------\n");
	printf("Kreiranje ispita");
	printf("\n-------------------\n");
	int examLength;
	printf("Broj pitanja: ");
	scanf("%d", &examLength);
	char filename[16];
	Question exam[examLength];
	Answer answer;
	for (int i = 0; i < examLength; i++) {
		sprintf(filename, "Q&A_%d.dat", i+1);
		setQuestion(exam + i);
		setPoints(exam + i);
		for (int answerId = 1; answerId <= NUMBER_OF_ANSWERS; answerId++) {
			setAnswerId(&answer, answerId);
			setAnswer(&answer, answerId);
			appendAnswer(filename, &answer);
		}
		setCorrectAnswer(exam + i);
	}
	saveExam(exam, examLength);
}
