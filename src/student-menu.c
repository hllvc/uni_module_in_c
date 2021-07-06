#include "../include/student-menu.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/exam.h"
#include "../include/menu-extra.h"
#include "../include/student-extra.h"

void studentBoard(Student* const student) {
  char choice;
  while (1) {
    printf("\n\n----------------------");
    printf("\nHELLO %s\n\n", student->firs_name_);
    printf("(%c) Check profile\n", C_1);
    printf("(%c) Start exam\n", C_2);

    printf("\n(%c) Exit\n", C_0);

    printf("\nChoice\n> ");
    scanf(" %c", &choice);

    switch (choice) {
    case C_1:
      profile(student);
      break;
    case C_2:
      test(student);
      break;
    case C_0:
      printf("\n>> Exiting ...");
      exit(0);
    default:
      printf("\n>-------------------<\n");
      printf(">> Wrong input <<");
      printf("\n>-------------------<");
    }
  };
}

void profile(Student const* const student) { showStudent(student); }

void test(Student* const student) {
  Question exam[EXAM_SIZE];
  loadTest(exam);
  if (questionsNum == 0) {
    printf("\n>> There is no registred tests <<");
    return;
  }
  printf("\n---------------\n");
  printf("TEST");
  printf("\n---------------");
  resetTestData(student);
  Answer answers[ANSWERS];
  int answer;
  for (int i = 0; i < questionsNum; i++) {
    printf("\n--------------------\n");
    printf("Question %d: %s?\n\n", i + 1, (exam + i)->name_);
    getQuestion(answers, i + 1);
    for (int i = 0; i < ANSWERS; i++) {
      printf("(%d) %s\n", i + 1, (answers + i)->name_);
    }
    do {
      printf("\nAnswer\n> ");
      scanf("%d", &answer);
    } while (wrongAnswer(answer));
    if ((exam + i)->correctAnswer_ == answer) {
      printf("Correct!\n");
      printf("Number of points %.2lf", (exam + i)->numberOfPoints_);
      appendPoints(student, (exam + i)->numberOfPoints_);
    } else
      printf("Incorrect!");
    printf("\n--------------------------\n");
  }
  gradeStudent(student);
  updateData();
}
