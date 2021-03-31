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
		// ispisujemo menu za admina
		printf("\n\n----------------------");
		printf("\nADMIN MENU\n\n");
		printf("(%c) Novi student\n", CHOICE1);
		printf("(%c) Uredi studenta\n", CHOICE2);
		printf("(%c) Obrisi studenta\n", CHOICE3);
		printf("(%c) Prikazi sve studente\n", CHOICE4);
		printf("(%c) Kreiraj ispit\n", CHOICE5);
		printf("\n(%c) Resetuj sve podatke\n", CHOICEr);

		printf("\n(%c) Kraj\n", CHOICE0);

		// unosimo odabir
		printf("\n* Odabir: ");
		scanf(" %c", &choice);

		switch (choice) {
			// odabir opcije
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
				// izazenje iz programa na 0
				printf("\n!! Gasenje programa ...");
				exit(0);
			default:
				// u slucaju nekog drugog unosa osim zadanog izbacuje pogresan unos
				printf("\n\n!! Pogresan unos !!");
		}
	};


}

void addStudent(void) {
	printf("\n-------------------\n");
	printf("Novi student");
	printf("\n-------------------\n");
	Student student = {0, "", "", "", "", 0, 0, 0}; // kreiramo pocetno stanje studenta sa svim praznim ili nultim opcijama
	// popunjavanje vrijednosti studenta
	setFirstName(&student);
	setLastName(&student);
	setAge(&student);
	setEmail(&student);
	setPassword(&student);
	setId(&student);
	appendStudent(&student); // sacuvamo studenta u file
	numberOfStudents++; // povecavamo broj studenata
	printf("\n-------------------\n");
	printf("!! Uspijesno registrovan novi student !!");
	printf("\n-------------------");
}

void editStudent(void) {
	if (!(numberOfStudents > 1)) { // ako nema registrovanih studenata izbacuje poruku i vraca se
		printf("\n!! Nema registrovanih studenata !!");
		return;
	}
	printf("\n-------------------\n");
	printf("Uredi studenta");
	printf("\n-------------------\n");
	Student * const student = getStudent(); // vraca studenta sa unosom maila
	printf("\n!! Unesite nove podatke !!\n\n");
	// update podataka
	setFirstName(student);
	setLastName(student);
	setAge(student);
	updateData(); // overwrite file u kojem cuvamo sa novim izmjenjenim podacima
	printf("\n-------------------\n");
	printf("!! Uspijesno uredjen student %s !!", student->email_);
	printf("\n-------------------");
}

void deleteStudent(void) {
	if (!(numberOfStudents > 1)) { // ako nema registrovanih studenata izbacuje poruku i vraca se
		printf("\n!! Nema registrovanih studenata !!");
		return;
	}
	printf("\n-------------------\n");
	printf("Obrisi studenta");
	printf("\n-------------------\n");
	Student * const student = getStudent(); // vraca studenta sa unosom maila
	student->id_ = 0; // postavlja id na 0, na osnovu kojem brisemo studenta
	updateData(); // update file bez studenta
	numberOfStudents--; // smanjumemo broj studenata jer je obrisan
	printf("\n-------------------\n");
	printf("!! Student %s je obrisan sa liste !!", student->email_);
	printf("\n-------------------");
}

void listStudents(Student const allStudents[]) {
	if (!(numberOfStudents > 1)) { // ako nema registrovanih studenata izbacuje poruku i vraca se
		printf("\n!! Nema registrovanih studenata !!");
		return;
	}
	printf("\n-------------------\n");
	printf("Lista svih studenata");
	printf("\n-------------------\n");
	for (int i = 0; i < numberOfStudents; i++) { // prolazimo kroz niz studenata i ispisujemo vrijednost
		if (!isAdmin(allStudents + i))
			printStudent(allStudents + i); // funckija koja printa atribute studenta
	}
}
void createExam(void) {
	printf("\n-------------------\n");
	printf("Kreiranje ispita");
	printf("\n-------------------\n");
	int examLength; // deklaracija varijable za broj pitanja
	do { // vrti se u krug dokle ne unesemo valid broj pitanja
		printf("\nBroj pitanja: ");
		scanf("%d", &examLength);
	} while (notValidExamLength(examLength));
	char filename[16]; // varijabla koja ce cuvat ime file sa odgovorima za odredjeno pitanje po broju
	Question exam[examLength]; // niz pitanja
	Answer answer; // odgovor
	for (int i = 0; i < examLength; i++) {
		sprintf(filename, "exam/Q&A_%d.dat", i+1); // spremamo ime file u varijabu filename
		fclose(fopen(filename, "wb+")); // overwrite staru vrijednost sa nista
		printf("\n");
		setQuestion(exam + i, i+1); // postavljamo pitanje
		setPoints(exam + i); // unosimo broj poena za pitanje
		printf("\n");
		for (int answerId = 1; answerId <= NUMBER_OF_ANSWERS; answerId++) { // prolazimo kroz broj odgovora i navodimo
			setAnswerId(&answer, answerId); // id od odgovora
			setAnswer(&answer, answerId); // text odgovora
			appendAnswer(filename, &answer); // dodaje odogovor i zadati filename
		}
		setCorrectAnswer(exam + i); // biljezimo tacan odgovor
	}
	saveExam(exam, examLength); // sacuvamo citav ispit
}
