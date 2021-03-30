#include <stdio.h>

#include "include/admin-menu.h"
#include "include/student-menu.h"
#include "include/student.h"
#include "include/menu-extra.h"

int numberOfStudents = 0;
Student allStudents[MAX_STUDENTS];

int main(void) {
	loadStudents(allStudents);
	Student * const student = login();
	if (isAdmin(student))
		adminMenu();
	/* else studentMenu(); */
}
