#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>

Quiz *quiz;
int countQuiz = 0;

void init()
{
	//int currentString = 0;
	//int currentString2 = 0;
	//string data;
	//ifstream fin;
	//fin.open();
	//bool isOpen = fin.is_open();
	//if (isOpen == false)
	//{
	//	cout << "Error" << endl;
	//}
	//else
	//{
	//	while (!fin.eof())
	//	{
	//		currentString++;
	//		//getline(fin, data);
	//		if (currentString == 1)
	//		{
	//		}
	//		else if (currentString == 2)
	//		{
	//		}
	//		else if (currentString == 3)
	//		{
	//		}
	//		else if (currentString == 4)
	//		{
	//		}
	//		else if (currentString == 5)
	//		{
	//		}
	//		else if (currentString == 6)
	//		{
	//		}
	//		else if (currentString == 7)
	//		{
	//			currentString2++;
	//			currentString = 0;
	//			/*push_back(oldEmployee);
	//			oldEmployee = Employee();*/
	//		}
	//	}
	//}
	//fin.close();
	//Employee * newemployee2 = new Employee[currentString2];
	//fin.open(fileName);
	//bool isOpen = fin.is_open();
	//if (isOpen == false)
	//{
	//	cout << "Error" << endl;
	//}
	//else
	//{
	//	while (!fin.eof())
	//	{
	//		currentString++;
	//		getline(fin, data);
	//		for (int i = 0; i < currentString2; i++)
	//		{
	//			currentString++;
	//			getline(fin, data);
	//			for (int j = 0; j < currentString2; j++)
	//			{
	//				if (currentString == 1)
	//				{
	//					newemployee2[i].name = data;
	//					break;
	//				}
	//				else if (currentString == 2)
	//				{
	//					newemployee2[i].surname = data;
	//				}
	//				else if (currentString == 3)
	//				{
	//					newemployee2[i].education = data;
	//				}
	//				else if (currentString == 4)
	//				{
	//					newemployee2[i].age = data;
	//				}
	//				else if (currentString == 5)
	//				{
	//					newemployee2[i].createDateOfBirth.day = data;
	//				}
	//				else if (currentString == 6)
	//				{
	//					newemployee2[i].createDateOfBirth.month = data;
	//				}
	//				else if (currentString == 7)
	//				{
	//					newemployee2[i].createDateOfBirth.year = data;
	//					currentString = 0;
	//					/*push_back(oldEmployee);
	//					oldEmployee = Employee();*/
	//				}
	//			}
	//		}
	//	}
	//}
	//fin.close();

	int currentString = 0;
	int currentString2 = 0;
	string data;
	ifstream fin;
	fin.open("Quiz.txt");
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
		}
		currentString2 = (currentString - 1) / 11;
		//cout << currentString2 << endl;
		currentString = 0;
	}
	fin.close();
	countQuiz = currentString2;
	Quiz *temp1 = new Quiz[currentString2];
	int f = 0;
	fin.open("Quiz.txt");
	bool isOpenn = fin.is_open();
	if (isOpenn == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
			for (int i = f; i < currentString2;)
			{
				if (currentString == 1)
				{
					temp1[i].question = new Questions[5];
					temp1[i].nameQuiz = data;
					//cout << temp[i].nameQuiz << endl;
					break;
				}
				else if (currentString == 2)
				{
					temp1[i].question[0].question1 = data;
					//cout << temp[i].question[0].question1 << endl;
					break;
				}
				else if (currentString == 3)
				{
					temp1[i].question[0].answer = data;
					//cout << temp[i].question[0].answer << endl;
					break;
				}
				else if (currentString == 4)
				{
					temp1[i].question[1].question1 = data;
					//cout << temp[i].question[1].question1 << endl;
					break;
				}
				else if (currentString == 5)
				{
					temp1[i].question[1].answer = data;
					//cout << temp[i].question[1].answer << endl;
					break;
				}
				else if (currentString == 6)
				{
					temp1[i].question[2].question1 = data;
					//cout << temp[i].question[2].question1 << endl;
					break;
				}
				else if (currentString == 7)
				{
					temp1[i].question[2].answer = data;
					//cout << temp[i].question[2].answer << endl;
					break;
				}
				else if (currentString == 8)
				{
					temp1[i].question[3].question1 = data;
					//cout << temp[i].question[3].question1 << endl;
					break;
				}
				else if (currentString == 9)
				{
					temp1[i].question[3].answer = data;
					//cout << temp[i].question[3].answer << endl;
					break;
				}
				else if (currentString == 10)
				{
					temp1[i].question[4].question1 = data;
					//cout << temp[i].question[4].question1 << endl;
					break;
				}
				else if (currentString == 11)
				{
					temp1[i].question[4].answer = data;
					//cout << temp[i].question[4].answer << endl;
					currentString = 0;
					f++;
					break;
				}
			}
		}
		quiz = temp1;
	}
	fin.close();
	//system("pause");
}

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
		delete[] quiz;
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
				cout << " = ";
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
			cout << "You have " << countResult << " right answer" << endl;
		}

	}
}
