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
		loadStudents(allStudents);
		printf("\nADMIN MENU\n\n");
		printf("(%c) Novi student\n", CHOICE1);
		printf("(%c) Uredi studenta\n", CHOICE2);
		printf("(%c) Obrisi studenta\n", CHOICE3);
		printf("(%c) Prikazi sve studente\n", CHOICE4);
		printf("\n(%c) Resetuj sve podatke\n", CHOICEr);

		printf("\n(%c) Kraj\n", CHOICE0);

		printf("\nOdabir: ");
		scanf(" %c", &choice);

		switch (choice) {
			case CHOICE1:
				addStudent();
				break;
			case CHOICE2:
				editStudent();
				break;
			case CHOICE4:
				listStudents(allStudents);
				break;
			case CHOICEr:
				resetData();
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

void editStudent(void) {
	Student * student;
	char email[EMAIL_LENGTH];
	while (strlen(student->email_) == 0) {
		printf("\nEmail: ");
		scanf("%s", email);
		if (!emailExists(email))
			printf("Ucenik sa unesenim emailom ne postoji!\n");
		else {
			for (int i = 0; i < numberOfStudents; i++)
				if (!strcmp((allStudents + i)->email_, email)) {
					student = allStudents + i;
				}
		}
	}
	printf("\nUnesite nove podatke!\n");
	setFirstName(student);
	setLastName(student);
	setEmail(student);
}

void deleteStudent(void);

void listStudents(Student const allStudents[]) {
	for (int i = 0; i < numberOfStudents; i++) {
		if (!isAdmin((allStudents + i)))
			printStudent(allStudents + i);
	}
}
void createExam(void);
