#include <stdio.h>
#include <stdlib.h>

#include "../include/student-menu.h"
#include "../include/student-extra.h"
#include "../include/menu-extra.h"
#include "../include/exam.h"

void studentMenu(Student * const student) {
	char choice;
	while (1) {
		printf("\n\n----------------------");
		printf("\nSTUDENT MENU\n\n");
		printf("(%c) Pogledaj profil\n", CHOICE1);
		printf("(%c) Zapocni ispit\n", CHOICE2);

		printf("\n(%c) Kraj\n", CHOICE0);

		printf("\n* Odabir: ");
		scanf(" %c", &choice);

		switch (choice) {
			case CHOICE1:
				showProfile(student);
				break;
			case CHOICE2:
				startExam(student);
				break;
			case CHOICE0:
				printf("\n!! Gasenje programa ...");
				exit(0);
			default:
				printf("\n>-------------------<\n");
				printf("!! Pogresan unos !!");
				printf("\n>-------------------<");
		}
	};
}

void showProfile(Student const * const student) {
	printStudent(student);
}

void startExam(Student * const student) {
	printf("\n>---------------<\n");
	printf("Ispit");
	printf("\n>---------------<");
	resetExamData(student);
	Question exam[EXAM_LENGTH];
	Answer answers[NUMBER_OF_ANSWERS];
	int answer;
	loadExam(exam);
	for (int i = 0; i < numberOfQuestions; i++) {
		printf("\n--------------------\n");
		printf("Pitanje %d: %s?\n\n", i+1,(exam + i)->name_);
		getQuestion(answers, i+1);
		for (int i = 0; i < NUMBER_OF_ANSWERS; i++) {
			printf("(%d) %s\n", i+1,(answers + i)->name_);
		}
		printf("\nUnesite odgovor: ");
		scanf("%d", &answer);
		if((exam + i)->correctAnswer_ == answer) {
			printf("Tacno!\n");
			printf("Broj osvojenih poena %.2lf", (exam + i)->numberOfPoints_);
			appendPoints(student, exam->numberOfPoints_);
		}
		else printf("Netacno!");
		printf("\n--------------------------\n");
	}
	gradeStudent(student);
	updateData();
}
