#include "../include/menu-extra.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/exam.h"
#include "../include/student-extra.h"

Student* const login(void) {
  printf("\n----------------------");
  printf("\nLOGIN\n");
  Student* const student = getStudent();
  char password[MAX_PASS];
  while (1) {
    printf("Password\n> ");
    scanf("%s", password);
    for (int i = 0; i < studentsNum; i++) {
      if (!strcmp(student->password_, password)) return student;
    }
    printf(">> Wrong password <<\n");
  }
}

const int checkTestSize(int const length) {
  if (length < 0 || length > EXAM_SIZE) {
    printf("\n>> Maximum number of questions is %d <<\n", EXAM_SIZE);
    return 1;
  }
  return 0;
}

const int wrongAnswer(int const answer) {
  if (answer < 0 || answer > ANSWERS) {
    printf("\n>> Wrong input <<\n");
    return 1;
  }
  return 0;
}

const int checkIfAdmin(Student const* const student) {
  if (student->id_ == 1) return 1;
  return 0;
}

Student* const getStudent(void) {
  Student* student;
  char email[EMAIL];
  while (1) {
    printf("\nEmail\n> ");
    scanf("%s", email);
    if (!checkExistingEmail(email)) {
      printf(">> Student with given email does not exist <<");
    } else {
      for (int i = 0; i < studentsNum; i++)
	if (!strcmp((students + i)->email_, email)) {
	  return students + i;
	}
    }
  }
}

void updateData() {
  resetData();
  for (int i = 0; i < studentsNum; i++) {
    if ((students + i)->id_ != 0) appendStudent(students + i);
  }
}

void resetData(void) {
  fclose(fopen("students.dat", "wb+"));
  Student student = {1, "root", "root"};
  FILE* file = fopen("students.dat", "wb+");
  fwrite(&student, sizeof(Student), 1, file);
  fclose(file);
}

void appendStudent(Student const* const student) {
  FILE* file = fopen("students.dat", "ab+");
  if (file != NULL) fwrite(student, sizeof(Student), 1, file);
  fclose(file);
}

void appendAnswer(char const filename[], Answer const* const answer) {
  FILE* file = fopen(filename, "ab+");
  if (file != NULL) fwrite(answer, sizeof(Answer), 1, file);
  fclose(file);
}

void saveTest(Question exam[], int const examLength) {
  FILE* file = fopen("exam/exam.dat", "wb+");
  if (file != NULL)
    for (int i = 0; i < examLength; i++)
      fwrite(exam + i, sizeof(Question), 1, file);
  fclose(file);
}

void loadStudents(Student studnets[]) {
  studentsNum = 0;
  FILE* file = fopen("students.dat", "rb+");
  if (file == NULL) {
    resetData();
    createDir();
    file = fopen("students.dat", "rb+");
  }
  if (file != NULL)
    while (fread(students + studentsNum, sizeof(Student), 1, file)) {
      studentsNum++;
    }
  fclose(file);
}

void loadTest(Question exam[]) {
  questionsNum = 0;
  FILE* file = fopen("exam/exam.dat", "rb+");
  if (file == NULL) return;
  if (file != NULL)
    while (fread(exam + questionsNum, sizeof(Question), 1, file))
      questionsNum++;
  fclose(file);
}

void getQuestion(Answer answers[], int const number) {
  char filename[16];
  sprintf(filename, "exam/Q&A_%d.dat", number);
  int counter = 0;
  FILE* file = fopen(filename, "rb+");
  if (file != NULL)
    while (fread(answers + counter, sizeof(Answer), 1, file)) counter++;
}

void createDir() {
#ifdef __linux__
  mkdir("exam", 0755);
#else
  mkdir("exam");
#endif
}
