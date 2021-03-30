#ifndef __EXAM_H__
#define __EXAM_H__

#define Q_LENGTH 45
#define A_LENGTH 15

#define NUMBER_OF_ANSWERS 3
#define EXAM_LENGTH 5

typedef struct {
	int id_;
	char name_[A_LENGTH];
} Answer;

typedef struct {
	char name_[Q_LENGTH];
	double numberOfPoints_;
	int correctAnswer_;
} Question;


void setQuestion(Question * const question);
void setPoints(Question * const question);
void setCorrectAnswer(Question * const question);

void setAnswer(Answer * const answer, int const answerId);
void setAnswerId(Answer * const answer, int const answerId);

#endif // __EXAM_H__
