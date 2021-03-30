#include <stdio.h>

#include "../include/exam.h"

void setQuestion(Question * const question) {
	printf("* Pitanje: ");
	scanf("%s", question->name_);
}

void setPoints(Question * const question) {
	printf("* Broj poena za dato pitanje: ");
	scanf("%lf", &question->numberOfPoints_);
}

void setCorrectAnswer(Question * const question) {
	printf("* Tacan odgovor (unesite redni broj pitanja): ");
	scanf("%d", &question->correctAnswer_);
}

void setAnswer(Answer *const answer, int const answerId) {
	printf("* Odgovor broj %d: ", answerId);
	scanf("%s", answer->name_);
}

void setAnswerId(Answer *const answer, int const answerId) {
	answer->id_ = answerId;
}
