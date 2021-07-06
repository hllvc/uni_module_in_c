#ifndef __STUDENT_C__
#define __STUDENT_C__

#define EMAIL 45
#define FIRST_NAME 25
#define LAST_NAME 25

#define MAX_PASS 20
#define MIN_PASS 8

#define MAX_AGE 75
#define MIN_AGE 18

#define MAX_ID 999999
#define MIN_ID 100000

#define MAX_STUDENTS 5

typedef struct stuent_t {
  unsigned long int id_;
  char email_[EMAIL];
  char password_[MAX_PASS];
  char firs_name_[FIRST_NAME];
  char last_name_[LAST_NAME];
  int age_;
  int grade_;
  double numberOfPoints_;

} Student;

void generateId(Student* const student);
void emailInput(Student* const student);
void passInput(Student* const student);
void firstNameInput(Student* const student);
void lastNameInput(Student* const student);
void ageInput(Student* const student);
void gradeInput(Student* const student);
void pointsInput(Student* const student);

#endif	// __STUDENT_C__
