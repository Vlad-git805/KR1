#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>

Quiz *quiz;
int countQuiz = 0;

//void init()
//{
//	int currentString = 0;
//	int currentString2 = 0;
//	string data;
//	ifstream fin;
//	fin.open();
//	bool isOpen = fin.is_open();
//	if (isOpen == false)
//	{
//		cout << "Error" << endl;
//	}
//	else
//	{
//		while (!fin.eof())
//		{
//			currentString++;
//			//getline(fin, data);
//			if (currentString == 1)
//			{
//
//			}
//			else if (currentString == 2)
//			{
//
//			}
//			else if (currentString == 3)
//			{
//
//			}
//			else if (currentString == 4)
//			{
//
//			}
//			else if (currentString == 5)
//			{
//
//			}
//			else if (currentString == 6)
//			{
//
//			}
//			else if (currentString == 7)
//			{
//
//				currentString2++;
//				currentString = 0;
//				/*push_back(oldEmployee);
//				oldEmployee = Employee();*/
//			}
//		}
//	}
//	fin.close();
//	Employee * newemployee2 = new Employee[currentString2];
//	fin.open(fileName);
//	bool isOpen = fin.is_open();
//	if (isOpen == false)
//	{
//		cout << "Error" << endl;
//	}
//	else
//	{
//		while (!fin.eof())
//		{
//			currentString++;
//			getline(fin, data);
//			for (int i = 0; i < currentString2; i++)
//			{
//				currentString++;
//				getline(fin, data);
//
//				for (int j = 0; j < currentString2; j++)
//				{
//					if (currentString == 1)
//					{
//						newemployee2[i].name = data;
//						break;
//					}
//					else if (currentString == 2)
//					{
//						newemployee2[i].surname = data;
//					}
//					else if (currentString == 3)
//					{
//						newemployee2[i].education = data;
//					}
//					else if (currentString == 4)
//					{
//						newemployee2[i].age = data;
//					}
//					else if (currentString == 5)
//					{
//						newemployee2[i].createDateOfBirth.day = data;
//					}
//					else if (currentString == 6)
//					{
//						newemployee2[i].createDateOfBirth.month = data;
//					}
//					else if (currentString == 7)
//					{
//						newemployee2[i].createDateOfBirth.year = data;
//						currentString = 0;
//						/*push_back(oldEmployee);
//						oldEmployee = Employee();*/
//					}
//				}
//			}
//		}
//	}
//	fin.close();
//
//}

void addQuiz()
{
	ofstream fout;
	fout.open("Quiz.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		Quiz *temp = new Quiz[countQuiz + 1];
		for (int i = 0; i < countQuiz; i++)
		{
			temp[i] = quiz[i];
		}

		temp[countQuiz].question = new Questions[5];
		//Вносимо данні про нову вікторину
		cout << "Enter name of quiz" << endl;
		cin >> temp[countQuiz].nameQuiz;
		cout << "Enter questions" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "enter " << i + 1 << "question" << endl;
			cin >> temp[countQuiz].question[i].question1;
			cout << "enter answer of " << i + 1 << "question" << endl;
			cin >> temp[countQuiz].question[i].answer;
		}

		fout << temp[countQuiz].nameQuiz << endl;
		for (int i = 0; i < 5; i++)
		{
			fout << temp[countQuiz].question[i].question1 << endl;
			fout << temp[countQuiz].question[i].answer << endl;
		}

		fout.close();
		countQuiz++;
		delete quiz;
		quiz = temp;
	}
	else
	{
		cout << "Error" << endl;
	}
}

void listOfQuiz()
{
	for (int i = 0; i < countQuiz; i++)
	{
		cout << quiz[i].nameQuiz << "\t";
	}
	cout << endl;
}

void passTheQuiz()
{
	cout << "Sellect quiz" << endl;
	cout << "Quizzes that are available: ";
	listOfQuiz();
	string name;
	string result;
	int countResult = 0;
	cout << "Enter name which quiz you want to pass" << endl;
	cin >> name;
	for (int i = 0; i < countQuiz; i++)
	{
		if (quiz[i].nameQuiz == name)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << "Question " << j + 1 << ":" << endl;
				cout << quiz[i].question[j].question1;
				cout << "answer -> ";
				cin >> result;
				if (result == quiz[i].question[j].answer)
				{
					countResult++;
				}
				else
				{
					cout << "you are wrong" << endl;
				}
			}
			cout << "You have " << countResult << "right answer" << endl;
		}

	}
}
