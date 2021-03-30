#ifndef __STUDENT_C__
#define __STUDENT_C__

// definisemo konstantne vrijednosti i duzine informacija
#define EMAIL_LENGTH 45
#define FIRST_LENGTH 25
#define LAST_LENGTH 25

#define MAX_PASSWORD 20
#define MIN_PASSWORD 8

#define MAX_AGE 75
#define MIN_AGE 18

#define MAX_ID 9999999999
#define MIN_ID 1000000000

#define MAX_STUDENTS 5

// definisemo strukturu student
typedef struct stuent_t {

	// sve varijable potrebne za studenta
	unsigned long int id_; // id studenta
	char email_[EMAIL_LENGTH]; // email
	char password_[MAX_PASSWORD]; // sifra
	char firsName_[FIRST_LENGTH]; // ime
	char lastName_[LAST_LENGTH]; // prezime
	int age_; // godine
	int grade_; // ocjena
	double numberOfPoints_; // broj poena
	
} Student;

void setId(Student * const student);
void setEmail(Student * const student);
void setPassword(Student * const student);
void setFirstName(Student * const student);
void setLastName(Student * const student);
void setAge(Student * const student);
void setGrade(Student * const student);
void setNumberOfPoints(Student * const student);

#endif // __STUDENT_C__
