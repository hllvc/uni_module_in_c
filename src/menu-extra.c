#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/menu-extra.h"
#include "../include/student-extra.h"
#include "../include/exam.h"

Student * const login(void) { // login menu
	printf("\n----------------------");
	printf("\nLOGIN MENU\n");
	Student * const student = getStudent(); // vracamo studenta po mailu
	char password[MAX_PASSWORD];
	while (1) { // vrti se dok ne unesemo tacnu sifru
		printf("* Password: ");
		scanf("%s", password);
		for (int i = 0; i < numberOfStudents; i++) { // prolazi kroz sve korisnike i testira sifru
			if (!strcmp(student->password_, password))
				return student;
		}
		printf("!! Pogresna sifra !!\n");
	}
}

const int notValidExamLength(int const length) { // ako unesemo veci broj pitanja od maximalno definisanog
	if (length < 0 || length > EXAM_LENGTH) {
		printf("\n!! Maksimalan broj pitanja je %d !!\n", EXAM_LENGTH);
		return 1;
	}
	return 0;
}

const int notValidAnswer(int const answer) { // ako unesemo veci broj odgovora od definisanih
	if (answer < 0 || answer > NUMBER_OF_ANSWERS) {
		printf("\n!! Pogresan unos !!\n");
		return 1;
	}
	return 0;
}

const int isAdmin(Student const * const student) { // provjeraje da li je student admin i vraca 1 ili 0
	if (student->id_ == 1)
		return 1;
	return 0;
}

Student * const getStudent(void) { // vraca studenta na osnovu maila
	Student * student;
	char email[EMAIL_LENGTH];
	while (1) {
		printf("\n* Email: ");
		scanf("%s", email);
		if (!emailExists(email)) { // unutar ifa funckija koja provjeraje da li postoji korisnik za unesenim mailom
			printf("!! Ucenik sa unesenim emailom ne postoji !!");
		}
		else {
			for (int i = 0; i < numberOfStudents; i++) // ako postoji trazi ga i vraca
				if (!strcmp((allStudents + i)->email_, email)) {
					return allStudents + i;
				}
		}
	}
}

void updateData() { // update save file
	resetData(); // prvo se obrise
	for (int i = 0; i < numberOfStudents; i++) { // pa ponovo sacuva
		if ((allStudents + i)->id_ != 0) // ako je id razlicit od 0 spremi, ako je nula brise
			appendStudent(allStudents + i);
	}
}

void resetData(void) { // resetuje sacuvane podatke
	fclose(fopen("students.dat", "wb+")); // ovdje samo zapise prazan file
	Student student = {1, "admin", "admin"}; // default admin student
	FILE * file = fopen("students.dat", "wb+"); // otvara file
	fwrite(&student, sizeof(Student), 1, file); // zapisuje samo admina
	fclose(file);
}

void appendStudent(Student const * const student) { // dodaje studenta u file
	FILE * file = fopen("students.dat", "ab+"); // otvara file
	if (file != NULL)
		fwrite(student, sizeof(Student), 1, file); // ako file postoji sacuva studenta
	fclose(file);
}

void appendAnswer(char const filename[], Answer const * const answer) { // dodaje odgovor u file
	FILE * file = fopen(filename, "ab+"); // otvara file
	if (file != NULL)
		fwrite(answer, sizeof(Answer), 1, file); // sacuva pitanje u file
	fclose(file);
}

void saveExam(Question exam[], int const examLength) { // sacuva ispit
	FILE * file = fopen("exam/exam.dat", "wb+"); // otvara file
	if (file != NULL)
		for (int i = 0; i < examLength; i++) // prolazi kroz sva pitanja i sacuva
			fwrite(exam + i, sizeof(Question), 1, file);
	fclose(file);
}

void loadStudents(Student allStudents[]) { // ucitaje studente
	numberOfStudents = 0;
	FILE * file = fopen("students.dat", "rb+"); // otvara file
	if (file == NULL) { // u slucaju da file ne postoji tjst prvi puta otvaramo
		resetData(); // save prazan file samo sa adminom
		make_directory(); // napravi folder exam za ispite
		file = fopen("students.dat", "rb+"); // i otvara file za dalji rad
	}
	if (file != NULL) // ako postoji
		while(fread(allStudents + numberOfStudents, sizeof(Student), 1, file)) { // ucitaje studente
			numberOfStudents++;
		}
	fclose(file);
}

void loadExam(Question exam[]) { // ucitaje ispit
	numberOfQuestions = 0;
	FILE * file = fopen("exam/exam.dat", "rb+"); // otvra
	if (file == NULL) // ako ne postoji samo se vrati
		return;
	if (file != NULL) // ako postoji
		while(fread(exam + numberOfQuestions, sizeof(Question), 1, file)) // ucitaje ispite
			numberOfQuestions++;
	fclose(file);
}

void getQuestion(Answer answers[], int const number) { // ucitanje odgovore
	char filename[16];
	sprintf(filename, "exam/Q&A_%d.dat", number); // svaki odgovor spremljen pod brojem pitanja u zaseban file
	int counter = 0;
	FILE * file = fopen(filename, "rb+"); // otvara file
	if (file != NULL)
		while(fread(answers + counter, sizeof(Answer), 1, file)) // ucitaje pitanja
			counter++;
}

void make_directory() { // kreira direktoriju exam
   #ifdef __linux__ // ako je linux
       mkdir("exam", 0755); 
   #else // ako je windows
       mkdir("exam");
   #endif
}
