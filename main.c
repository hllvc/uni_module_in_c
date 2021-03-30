#include <stdio.h>

#include "include/admin-menu.h"
#include "include/student.h"
#include "include/menu-extra.h"

int numberOfStudents = 0;
Student allStudents[MAX_STUDENTS];

int main(void) {
	Student student;
	loadStudents(allStudents);
	adminMenu();
}
