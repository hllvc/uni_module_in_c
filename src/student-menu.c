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
				break;
			case CHOICE0:
				printf("!! Gasenje programa ...");
				exit(0);
			default:
				printf(">-------------------<");
				printf("!! Pogresan unos !!");
				printf(">-------------------<");
		}
	};
}

void showProfile(Student const * const student) {
	printStudent(student);
}

void startExam(Student const * const student) {
	Question exam[EXAM_LENGTH];
	int answer;
	loadExam(exam);
	printf("%s", exam->name_);
	Answer answers[NUMBER_OF_ANSWERS];
	for (int i = 0; i < NUMBER_OF_ANSWERS; i++)
		printf("%s", answers->name_);
	printf("Unesite odgovor: ");
	scanf("%d", &answer);
}
