#ifndef __EXAM_H__
#define __EXAM_H__

#define QUESTION_SIZE 50
#define ANSWER_SIZE 20

#define ANSWERS 3
#define EXAM_SIZE 5

typedef struct {
  int id_;
  char name_[ANSWER_SIZE];
} Answer;

typedef struct {
  char name_[QUESTION_SIZE];
  double numberOfPoints_;
  int correctAnswer_;
} Question;

void generateQuestion(Question* const question, int const questionId);
void setPoints(Question* const question);
void markCorrectAnswer(Question* const question);

void generateAnswer(Answer* const answer, int const answerId);
void generateAnswerId(Answer* const answer, int const answerId);

#endif	// __EXAM_H__
