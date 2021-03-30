#include <stdio.h>

#include "student.h"

int main(void) {
	Student student;
	setFirstName(&student);
	setLastName(&student);
	printStudent(&student);
}
