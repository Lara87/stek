// Stek_kursovaya.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

struct stack 
{
	int x;
	stack *next, *head;
};

void add(int a, stack *&list)//добавление элемента в список
{
	stack *temp = new stack; // выделяем память для нового элемента
	temp->x = a; // записываем в поле х новое значение а
	temp->next = list->head;//вставляем новый элемент перед головой
	list->head = temp;//меняем голову списка на новый элемент
}

void display(stack *list) // вывод стека на экран
{
	stack *temp = list->head;
	while (temp != NULL)
	{
		cout << temp->x << " ";
		temp = temp->next;
	}
}

void pop(stack *&list)//удаление элемента 
{
	stack *temp = list->head;
	list->head = temp->next;
	delete temp;
}

int size(stack *list)
{
	int i = 0;
	stack *temp = list->head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

bool isEmpty(stack *list)
{
	if (list->head == 0)
		return true;
	else return false;
}

int top(stack *&list)
{
		stack *temp = list->head;
		return temp->x;
}

void input(stack *&list, int n)
{
	int a = 0;
	for (int i = 1; i <= n; i++)
	{
		cout << i << ". ";
		cin >> a;
		add(a, list);
	}
}

void random(stack *&list, int n)
{
	int a = 0;
	srand(time(NULL));
	for(int i=1; i<=n; i++)
	{
		a = 1 + rand() % 100;
		add(a, list);
	}
}

void title()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor = { 0,0 };
	cor.X = 10;
	cor.Y = 5;
	SetConsoleCursorPosition(hConsole, cor);
	cout << "    «Астраханский государственный технический университет»\n";
	cout << "                 Институт Информационных технологий и коммуникаций\n";
	cout << "\n";
	cout << " \n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "       Кафедра Автоматизированные системы обработки информации и управления\n";
	cout << "\n";
	cout << "\n";
	cout << "                               КУРСОВОЙ ПРОЕКТ\n";
	cout << "\n";
	cout << "\n";
	cout << "        Учебно-демонстрационная программа «Стек: реализация на базе списка»\n";
	cout << "                    по дисциплине «Программирование и информатика»\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "             Проект выполнен cтуденткой группы ЗИНРБ - 21 Черниковой Л.В.\n";
	cout << "\n";
	cout << "\n";
	cout << "                      Руководитель работы Учаев Д.Ю.\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	_getch();
}


	int main()
{
	setlocale(LC_ALL, "Russian");
	title();
	int a, choice, n;
	stack *list = new stack;
	list->head = NULL;
	while (true)
	{
		cout << "Введите размер стека" << endl;
		cin >> n;
		if ((!cin) || (n <= 0))
		{
			cout << "Число некорректно. Повторите ввод" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	
	while (true)
	{
		cout << "1 - Заполнение стека с клавиатуры\n2 - Заполнение стека случайными числами" << endl;
		cin >> choice;
		if((!cin)||(choice<1)||(choice>2))
		{
			cout << "Число некорректно. Повторите ввод" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;

	}
	
	switch (choice)
	{
	case 1: input(list, n);
		break;
	case 2: random(list, n);
		break;

	}
	
	
	choice = 1;

	while ((choice != 0)||(isEmpty(list))
	{
		while (true)
		{
			cout << "1 - Вывести стек" << endl;
			cout << "2 - Вывести голову стека" << endl;
			cout << "3 - Удаление первого элемента стека (pop)" << endl;
			cout << "4 - Добавить элемент в стек" << endl;
			cout << "5 - Вывести размер стека" << endl;
			cout << "0 - Выход" << endl;
			cin >> choice;
			if ((!cin) || (choice < 0) ||(choice>5))
			{
				cout << "Число некорректно. Повторите ввод" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		switch (choice)
		{
		case 1: display(list);
			break;
		case 2: int topEl = top(list);
			cout << "голова стека: " << topEl << endl;
			break;
		case 3: pop(list);
			break;
		case 4: 
			while (true)
			{
				cout << "Введите число" << endl;
				cin >> a;
		
				if (!cin)
				{
					cout << "Число некорректно. Повторите ввод" << endl;
					cin.clear();
					while (cin.get() != '\n');
				}
				else break;
			}
			add(a, list);
			break;
		case 5: 
			cout << "размер стека: " << size(list) << endl;
			break;

		case 0:
			cout << "Выход из программы" << endl;
			break;
		}
	}



	display(list);
	cout << endl;
	int topEl = top(list);
	cout << "голова стека: "<< topEl << endl;
	pop(list);
	cout << endl;
	display(list);
	cout << endl;
	add(18, list);
	cout << endl;
	display(list);
	cout << endl;
	cout << endl;

	
	system("pause");
    return 0;
}

