#include <iostream>
#include "list.c++"

using namespace std;

template<typename T>
void printMenu(List<T>& list);

template<typename T>
void createList(List<T>& l);

template<typename T>
void printList(List<T>& listToPrint);

template<typename T>
T findMinumim(List<T>& list, size_t ind, T minVal = 0);


void main()
{
	setlocale(LC_ALL, "ru");

	// Главные переменные
	List<int> list;

	//Переменные для пользовательского ввода.
	int userMenuChoice = -1;

	// Главный меню-цикл.
	while (userMenuChoice != 0)
	{
		system("cls");
		printMenu(list);

		cin >> userMenuChoice;
		cin.ignore();

		switch (userMenuChoice)
		{
		case 1:
			list.clear();
			createList(list);
			system("pause");
			break;

		case 2:
			if (list.getSize() != 0)
			{
				cout << "Минимальное значение списка: " << findMinumim(list, 0) << "\n";
			}
			else
			{
				cout << "Действие невозможно. Заполните список.\n";
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


template<typename T>
void printMenu(List<T>& list)
{
	cout << "Практическая работа #6 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание 5 - Рекурсивные алгоритмы.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n"
		"Введённая строка: ";
	printList(list);
	cout << "Введите [1], чтобы ввести список.\n"
		"Введите [2], чтобы получить минимальное значение в списке.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}


//Функция задания списка
template<typename T>
void createList(List<T>& l)
{
	size_t size;
	T currentVal;
	cout << "Введите количество вводимых ячеек: ";
	cin >> size;
	cout << "Введите " << size << " значений: ";
	for (size_t i = 0; i < size; i++)
	{
		cin >> currentVal;
		l.pushBack(currentVal);
	}
}


//Функция вывода списка
template<typename T>
void printList(List<T>& listToPrint)
{
	if (listToPrint.getSize())
	{
		size_t printSize = listToPrint.getSize();
		for (size_t i = 0; i < printSize; i++)
		{
			cout << listToPrint[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "Пуст\n";
	}
}


template<typename T>
T findMinumim(List<T>& list, size_t ind, T minVal)
{
	if (ind >= list.getSize())
	{
		return minVal;
	}
	else
	{
		if (ind == 0)
		{
			minVal = list[ind];
		}

		if (minVal > list[ind])
		{
			minVal = list[ind];
		}
		return findMinumim(list, ind + 1, minVal);
	}
}