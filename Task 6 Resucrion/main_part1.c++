#include <iostream>
#include <string>
#include <windows.h>
#include <locale>

#include "BracketsBalance.h"

using namespace std;


void printMenu(string& inputedString);

void printString(string& inputedString);

void inputString(string& inputedString);

void balanceCheckerHub(string inputedString);

BracketsBalance checkBrcaketsBalanse(string str, size_t ind, BracketsBalance balance);



void main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������� ����������
	string inputedString;

	//���������� ��� ����������������� �����.
	int userMenuChoice = -1;

	// ������� ����-����.
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
				cout << "�������� ����������. ������� ������.\n";
			}
			system("pause");
			break;

		case 0:
			cout << "�� ��������!\n";
			userMenuChoice = 0;
			system("pause");
			break;

		default:
			cout << "� �� ������� ���, ��������� ����\n";
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
		cout << "�� �������\n";
	}
}


void printMenu(string& inputedString)
{
	cout << "������������ ������ #6 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� 6 - ����������� ���������.\n"
		"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n"
		"�������� ������: ";
	printString(inputedString);
	cout << "������� [1], ����� ������ ������.\n"
		"������� [2], ����� ������ ������ ������.\n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "��� �����: ";
}


void inputString(string& inputedString)
{
	cout << "������� ������, ����� ������� ������� [Enter]: ";
	getline(cin, inputedString);
}


void balanceCheckerHub(string inputedString)
{
	BracketsBalance balance;
	balance = checkBrcaketsBalanse(inputedString, 0, balance);

	if (balance.roundBalance == 0)
	{
		cout << "�����c ������� ������ �������\n";
	}
	else
	{
		cout << "� ������ �� ������� " << balance.roundBalance <<
			(balance.roundBalance < 0 ? " ����������� " : " ����������� ") <<
			"������� ������\n";
	}

	if (balance.squareBalance == 0)
	{
		cout << "�����c ���������� ������ �������\n";
	}
	else 
	{
		cout << "� ������ �� ������� " << balance.squareBalance <<
			(balance.squareBalance < 0 ? " ����������� " : " ����������� ") <<
			"���������� ������\n";
	}

	if (balance.bracesBalance == 0)
	{
		cout << "�����c �������� ������ �������\n";
	}
	else
	{
		cout << "� ������ �� ������� " << balance.bracesBalance <<
			(balance.bracesBalance < 0 ? " ����������� " : " ����������� ") <<
			"�������� ������\n";
	}
}


BracketsBalance checkBrcaketsBalanse(string str, size_t ind,  BracketsBalance balance)
{
	while (ind < str.size())
		switch (str[ind])
		{
		case '(': 
			balance.roundBalance++;
			return checkBrcaketsBalanse(str, ind + 1, balance);
		case ')':
			balance.roundBalance--;
			return checkBrcaketsBalanse(str, ind + 1, balance);
		case '[': 
			balance.squareBalance++;
			return checkBrcaketsBalanse(str, ind + 1, balance);
		case ']': 
			balance.squareBalance--;
			return checkBrcaketsBalanse(str, ind + 1, balance);
		case '{': 
			balance.bracesBalance++;
			return checkBrcaketsBalanse(str, ind + 1, balance);
		case '}': 
			balance.bracesBalance--;
			return checkBrcaketsBalanse(str, ind + 1, balance);
		}
	return (balance);
}