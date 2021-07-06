#include <stdio.h>
#include <stdlib.h>

#include "include/admin-menu.h"
#include "include/menu-extra.h"
#include "include/student-menu.h"
#include "include/student.h"

int studentsNum = 0;
int questionsNum = 0;
Student students[MAX_STUDENTS];

int main(void) {
  loadStudents(students);
  Student* const student = login();
  if (checkIfAdmin(student))
    admin();
  else
    studentBoard(student);
}
