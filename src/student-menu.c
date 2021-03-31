#include <stdio.h>
#include <stdlib.h>

#include "../include/student-menu.h"
#include "../include/student-extra.h"
#include "../include/menu-extra.h"
#include "../include/exam.h"

void studentMenu(Student * const student) {
	char choice;
	while (1) {
		// ispisivanje menu za studenta
		printf("\n\n----------------------");
		printf("\nSTUDENT MENU\n\n");
		printf("(%c) Pogledaj profil\n", CHOICE1);
		printf("(%c) Zapocni ispit\n", CHOICE2);

		printf("\n(%c) Kraj\n", CHOICE0);

		// unos odabira
		printf("\n* Odabir: ");
		scanf(" %c", &choice);

		switch (choice) {
			// odabir opcije
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

void showProfile(Student const * const student) { // prikazuje logovanu osobu i njene atribute
	printStudent(student);
}

void startExam(Student * const student) { // pocinje ispit
	Question exam[EXAM_LENGTH];
	loadExam(exam); // ucitaje ispit
	if (numberOfQuestions == 0) { // u slucaju da nema ispita vraca i daje poruku
		printf("\n!! Nema registrovanih ispita !!");
		return;
	}
	printf("\n---------------\n");
	printf("Ispit");
	printf("\n---------------");
	resetExamData(student); // resetuje poene jer krecemo novi ispit
	Answer answers[NUMBER_OF_ANSWERS]; //  niz odgovora
	int answer; // odgovor koji unosimo i provjerajemo
	for (int i = 0; i < numberOfQuestions; i++) { // prolazi kroz pitanja
		printf("\n--------------------\n");
		printf("Pitanje %d: %s?\n\n", i+1,(exam + i)->name_); // ispisuje pitanje za rednim brojem
		getQuestion(answers, i+1); // ucitanje odgovore za dato pitanje
		for (int i = 0; i < NUMBER_OF_ANSWERS; i++) { // prolazi kroz odgovore i ispisuje na ekran
			printf("(%d) %s\n", i+1,(answers + i)->name_);
		}
		do {
			printf("\nUnesite odgovor: "); // unosimo odgovor
			scanf("%d", &answer);
		} while(notValidAnswer(answer)); // dokle kod nije validan
		if((exam + i)->correctAnswer_ == answer) { // ako je odgovor tacan
			printf("Tacno!\n"); // ispisuje poruku
			printf("Broj osvojenih poena %.2lf", (exam + i)->numberOfPoints_); // osvojene bodove
			appendPoints(student, (exam + i)->numberOfPoints_); // i dodaje poene studentu
		}
		else printf("Netacno!"); // ako je netacan
		printf("\n--------------------------\n");
	}
	gradeStudent(student); // ocjenjuje studenta sa ispisom
	updateData(); // update file sa novim podacima tjst ocjenom i bodovima
}
