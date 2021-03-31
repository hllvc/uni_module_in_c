#include <stdio.h>
#include <stdlib.h>

#include "include/admin-menu.h"
#include "include/student-menu.h"
#include "include/student.h"
#include "include/menu-extra.h"

int numberOfStudents = 0; // pocetni broj studenata, ujedno globalna varijabla za druge funkcije
int numberOfQuestions = 0; // pocetni broj pitanja, globalna
Student allStudents[MAX_STUDENTS]; // niz studenata, globalna

int main(void) {
	loadStudents(allStudents); // ucitajemo studente, u slucaju prvog pokretanja kreira novi file i folder za ispite
	Student * const student = login(); // login forma i validacija emaila i passworda
	if (isAdmin(student)) // provjeraje je li korisnik admin ili ne i tako bira menu
		adminMenu();
	else studentMenu(student);
}
