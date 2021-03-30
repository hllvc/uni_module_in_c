#include <stdio.h>
#include <stdlib.h>

#include "../include/admin-menu.h"
#include "../include/student.h"
#include "../include/menu-extra.h"

void adminMenu(void) {
	char choice;
	while (1) {
		printf("\nADMIN MENU\n\n");
		printf("(%c) Novi student\n", CHOICE1);
		printf("(%c) Uredi studenta\n", CHOICE2);
		printf("(%c) Obrisi studenta\n", CHOICE3);
		printf("(%c) Prikazi sve studente\n", CHOICE4);

		printf("\n(%c) Kraj\n", CHOICE0);

		printf("\nOdabir: ");
		scanf(" %c", &choice);

		switch (choice) {
			case CHOICE1:
				addStudent();
				break;
			case CHOICE4:
				listStudents(allStudents);
				break;
			case CHOICE0:
				exit(0);
			default:
				printf("Pogresan unos!");
		}
	};


}

void addStudent(void) {
	Student student;
	setFirstName(&student);
	setLastName(&student);
	setEmail(&student);
	setPassword(&student);
	setId(&student);
	appendStudent(&student);
}

void editStudent(void);
void deleteStudent(void);

void listStudents(Student const allStudents[]) {
	for (int i = 0; i < numberOfStudents; i++)
		printStudent(allStudents + i);
}
void createExam(void);
