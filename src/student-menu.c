#include <stdio.h>
#include <stdlib.h>

#include "../include/student-menu.h"
#include "../include/student-extra.h"

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
