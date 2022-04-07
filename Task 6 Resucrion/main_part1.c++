#include <iostream>
#include <string>
#include <windows.h>
#include <locale>
#include <cmath>

#include "BracketsBalance.h"

using namespace std;


void printMenu(string& inputedString);

void printString(string& inputedString);

void inputString(string& inputedString);

void balanceCheckerHub(string inputedString);

BracketsBalance checkBrcaketsBalance(string str, BracketsBalance balance, size_t ind = 0);



void main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Главные переменные
	string inputedString;

	//Переменные для пользовательского ввода.
	int userMenuChoice = -1;

	// Главный меню-цикл.
	while (userMenuChoice != 0) 
	{
		system("cls");
		printMenu(inputedString);

		cin >> userMenuChoice;
		cin.ignore();

		switch (userMenuChoice) 
		{
		case 1:
			inputString(inputedString);
			system("pause");
			break;

		case 2:
			if (inputedString.size() > 0)
			{
				balanceCheckerHub(inputedString);
			}
			else
			{
				cout << "Действие невозможно. Введите строку.\n";
			}
			system("pause");
			break;

		case 0:
			cout << "До свидания!\n";
			userMenuChoice = 0;
			system("pause");
			break;

		default:
			cout << "Я не понимаю вас, повторите ввод\n";
			cin.clear();
			system("pause");
			break;
		}
	}
}


void printString(string& inputedString)
{
	if (inputedString.length() != 0)
	{
		cout << inputedString << endl;
	}
	else
	{
		cout << "Не введена\n";
	}
}


void printMenu(string& inputedString)
{
	cout << "Практическая работа #6 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание 6 - Рекурсивные алгоритмы.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n"
		"Введённая строка: ";
	printString(inputedString);
	cout << "Введите [1], чтобы ввести строку.\n"
		"Введите [2], чтобы узнать баланс скобок.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}


void inputString(string& inputedString)
{
	cout << "Введите строку, после нажмите клавишу [Enter]: ";
	getline(cin, inputedString);
}


void balanceCheckerHub(string inputedString)
{
	BracketsBalance balance;
	balance = checkBrcaketsBalance(inputedString, balance);

	if (balance.roundBalance == 0)
	{
		cout << "Баланc круглых скобок соблюдён\n";
	}
	else
	{
		cout << "В строке не хватает " << abs(balance.roundBalance) <<
			(balance.roundBalance < 0 ? " открывающих " : " закрывающих ") <<
			"круглых скобок\n";
	}

	if (balance.squareBalance == 0)
	{
		cout << "Баланc квадратных скобок соблюдён\n";
	}
	else 
	{
		cout << "В строке не хватает " << abs(balance.squareBalance) <<
			(balance.squareBalance < 0 ? " открывающих " : " закрывающих ") <<
			"квадратных скобок\n";
	}

	if (balance.bracesBalance == 0)
	{
		cout << "Баланc фигурных скобок соблюдён\n";
	}
	else
	{
		cout << "В строке не хватает " << abs(balance.bracesBalance) <<
			(balance.bracesBalance < 0 ? " открывающих " : " закрывающих ") <<
			"фигурных скобок\n";
	}
}


BracketsBalance checkBrcaketsBalance(string str, BracketsBalance balance, size_t ind)
{
	while (ind < str.size())
	{
		switch (str[ind])
		{
		case '(':
			balance.roundBalance++;
			break;
		case ')':
			balance.roundBalance--;
			break;
		case '[':
			balance.squareBalance++;
			break;
		case ']':
			balance.squareBalance--;
			break;
		case '{':
			balance.bracesBalance++;
			break;
		case '}':
			balance.bracesBalance--;
			break;
		}
		return checkBrcaketsBalance(str, balance, ind + 1);
	}
	return (balance);
}