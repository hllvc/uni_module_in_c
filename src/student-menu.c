#include <stdio.h>
#include <stdlib.h>

#include "../include/student-menu.h"
#include "../include/student-extra.h"
#include "../include/menu-extra.h"
#include "../include/exam.h"

void studentMenu(Student const * const student) {
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
				printf("!! Gasenje programa ...");
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

void startExam(Student const * const student) {
	printf("\n>---------------<\n");
	printf("!! Not working !!");
	printf("\n>---------------<");
	/* Question exam[EXAM_LENGTH]; */
	/* Answer answers[NUMBER_OF_ANSWERS]; */
	/* int answer; */
	/* loadExam(exam); */
	/* for (int i = 0; i < EXAM_LENGTH; i++) { */
	/* 	printf("%s", exam->name_); */
	/* 	getQuestion(answers, i); */
	/* 	for (int i = 0; i < NUMBER_OF_ANSWERS; i++) { */
	/* 		printf("%s", (answers + i)->name_); */
	/* 		printf("Unesite odgovor: "); */
	/* 		scanf("%d", &answer); */
	/* 	} */
	/* } */
}
