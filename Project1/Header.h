#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

#define PAUSE system("pause");
#define CLEAR system("cls");

struct Questions
{
	string question1;
	string answer;
};

struct Quiz
{
	string nameQuiz;
	Questions *question;
};

void init();
void addQuiz();
void listOfQuiz();
void passTheQuiz();
