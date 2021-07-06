#include "../include/exam.h"

#include <stdio.h>

#include "../include/menu-extra.h"

void generateQuestion(Question* const question, int const questionId) {
  printf("Question number %d:\n> ", questionId);
  scanf(" %[^\n]%*c", question->name_);
}

void setPoints(Question* const question) {
  printf("Points for given question\n> ");
  scanf(" %lf", &question->numberOfPoints_);
}

void markCorrectAnswer(Question* const question) {
  do {
    printf("\nMark correct answer (enter number of answer)\n> ");
    scanf("%d", &question->correctAnswer_);
  } while (wrongAnswer(question->correctAnswer_));
}

void generateAnswer(Answer* const answer, int const answerId) {
  printf("Answer number%d\n> ", answerId);
  scanf(" %[^\n]%*c", answer->name_);
}

void generateAnswerId(Answer* const answer, int const answerId) {
  answer->id_ = answerId;
}
