#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Header.h"

using namespace std;

void main()
{
	//init();
	int a = 0;
	do
	{
		cout << "1 - Add new quiz" << endl;
		cout << "2 - list of quiz" << endl;
		cout << "3 - pass  the quiz" << endl;
		cout << "0 - exit" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Add Quiz" << endl;
			addQuiz();
		}
		break;
		case 2:
		{
			cout << "List of quiz: \t ";
			listOfQuiz();
		}
		break;
		case 3:
		{
			cout << "Pass the quiz" << endl;
			passTheQuiz();
		}
		break;
		case 0:
		{
			exit(0);
		}
		break;
		default:
			break;
		}
	} while (a != 0);
	system("pause");
}