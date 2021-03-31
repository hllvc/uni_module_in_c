#include <stdio.h>

#include "../include/exam.h"
#include "../include/menu-extra.h"

void setQuestion(Question * const question, int const questionId) { // postavljanje pitanja
	printf("* Pitanje broj %d: ", questionId);
	scanf(" %[^\n]%*c", question->name_);
}

void setPoints(Question * const question) { // poeni za pitanje
	printf("* Broj poena za dato pitanje: ");
	scanf(" %lf", &question->numberOfPoints_);
}

void setCorrectAnswer(Question * const question) { // unos tacnog odgovora sa granicom ako se unese izvan
	do {
		printf("\n* Tacan odgovor (unesite redni broj pitanja): ");
		scanf("%d", &question->correctAnswer_);
	} while (notValidAnswer(question->correctAnswer_));
}

void setAnswer(Answer *const answer, int const answerId) { // postavljanje odgovra
	printf("* Odgovor broj %d: ", answerId);
	scanf(" %[^\n]%*c", answer->name_);
}

void setAnswerId(Answer *const answer, int const answerId) {
	answer->id_ = answerId;
}
