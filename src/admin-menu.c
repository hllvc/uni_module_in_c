#include "../include/admin-menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/exam.h"
#include "../include/menu-extra.h"
#include "../include/student-extra.h"
#include "../include/student.h"

void admin(void) {
  char choice;
  while (1) {
    printf("\n\n----------------------");
    printf("\nADMIN\n\n");
    printf("[%c] Enroll student\n", C_1);
    printf("[%c] Edit student\n", C_2);
    printf("[%c] Generate test\n", C_5);
    printf("\n[%c] Reset all\n", C_r);

    printf("\n[%c] Exit\n", C_0);

    printf("\nChoice\n> ");
    scanf(" %c", &choice);

    switch (choice) {
    case C_1:
      enrollStudent();
      loadStudents(students);
      break;
    case C_2:
      editStudent();
      break;
    case C_3:
      removeStudent();
      break;
    case C_4:
      listAllStudents(students);
      break;
    case C_5:
      generateExam();
      break;
    case C_r:
      resetData();
      break;
    case C_0:
      printf("\n>> Exiting ...");
      exit(0);
    default:
      printf("\n\n>> Wrong input <<");
    }
  };
}

void enrollStudent(void) {
  printf("\n-------------------\n");
  printf("New Student");
  printf("\n-------------------\n");
  Student student = {0, "", "", "", "", 0, 0, 0};
  firstNameInput(&student);
  lastNameInput(&student);
  ageInput(&student);
  emailInput(&student);
  passInput(&student);
  generateId(&student);
  appendStudent(&student);
  studentsNum++;
  printf("\n-------------------\n");
  printf(">> Successfully enrolled new student <<");
  printf("\n-------------------");
}

void editStudent(void) {
  if (!(studentsNum > 1)) {
    printf("\n>> There is no students enrolled <<");
    return;
  }
  printf("\n-------------------\n");
  printf("Edit Student");
  printf("\n-------------------\n");
  Student* const student = getStudent();
  printf("\n>> Input new info <<\n\n");
  firstNameInput(student);
  lastNameInput(student);
  ageInput(student);
  updateData();
  printf("\n-------------------\n");
  printf(">> Successfully edited student %s <<", student->email_);
  printf("\n-------------------");
}

void removeStudent(void) {
  if (!(studentsNum > 1)) {
    printf("\n>> There is no students enrolled <<");
    return;
  }
  printf("\n-------------------\n");
  printf("Remove Student");
  printf("\n-------------------\n");
  Student* const student = getStudent();
  student->id_ = 0;
  updateData();
  studentsNum--;
  printf("\n-------------------\n");
  printf(">> Student %s is removed <<", student->email_);
  printf("\n-------------------");
}

void listAllStudents(Student const students[]) {
  if (!(studentsNum > 1)) {
    printf("\n>> There is no students enrolled <<");
    return;
  }
  printf("\n-------------------\n");
  printf("All Students");
  printf("\n-------------------\n");
  for (int i = 0; i < studentsNum; i++) {
    if (!checkIfAdmin(students + i)) showStudent(students + i);
  }
}
void generateExam(void) {
  printf("\n-------------------\n");
  printf("GENERATE TEST");
  printf("\n-------------------\n");
  int examLength;
  do {
    printf("\nNumber of questions\n> ");
    scanf("%d", &examLength);
  } while (checkTestSize(examLength));
  char filename[16];
  Question exam[examLength];
  Answer answer;
  for (int i = 0; i < examLength; i++) {
    sprintf(filename, "exam/Q&A_%d.dat", i + 1);
    fclose(fopen(filename, "wb+"));
    printf("\n");
    generateQuestion(exam + i, i + 1);
    setPoints(exam + i);
    printf("\n");
    for (int answerId = 1; answerId <= ANSWERS; answerId++) {
      generateAnswerId(&answer, answerId);
      generateAnswer(&answer, answerId);
      appendAnswer(filename, &answer);
    }
    markCorrectAnswer(exam + i);
  }
  saveTest(exam, examLength);
}
