#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/admin-menu.h"
#include "../include/student.h"
#include "../include/menu-extra.h"
#include "../include/student-extra.h"

void adminMenu(void) {
	char choice;
	while (1) {
		printf("\n\n----------------------");
		printf("\nADMIN MENU\n\n");
		printf("(%c) Novi student\n", CHOICE1);
		printf("(%c) Uredi studenta\n", CHOICE2);
		printf("(%c) Obrisi studenta\n", CHOICE3);
		printf("(%c) Prikazi sve studente\n", CHOICE4);
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
				printf(">-------------------<");
				printf("!! Pogresan unos !!");
				printf(">-------------------<");
		}
	};


}

void addStudent(void) {
	printf("\n-------------------\n");
	printf("Novi student");
	printf("\n-------------------\n");
	Student student;
	setFirstName(&student);
	setLastName(&student);
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

}
