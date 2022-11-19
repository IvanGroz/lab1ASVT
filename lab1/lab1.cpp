// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "pch.h"
#include "Collection.h"
#include "CircleDoubleList.h"

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;


void repaintConsole()
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd;
	cd.X = 0;
	cd.Y = 0;
	SetConsoleCursorPosition(hd, cd);
}

void checkInt(istream& ios, int& value) {
	while (!(ios >> value) || ios.get() != '\n') // cin.fail() возвращает 1 если установлет failbit
	{
		cout << "Нужны только цифры!\n";
		ios.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
		ios.sync();//Удалим данные из буффера
		cin.ignore(999, '\n');
		cout << "Введите число: ";
	}
}

void drawMenu(int& index) {
	string head = " Циклический двусвязный список (Выберите стрелочками одну из доступных команд )\n";
	string arrStr[] = {
		" Размер('size')\n",
		" Очистка списка('clear')\n",
		" Проверка списка на пустоту('empty')\n" ,
		" Добавление в конец('add')\n",
		" Вставка по индексу('insert')\n" ,
		" Получение значения по индексу('get')\n",
		" Назначить значение по индексу('set')\n" ,
		" Удалить элемент по индексу('remove')\n",
		" Удалить по значению('removeByValue')\n" ,
		" Содержит ли список значение('contains')\n",
		" Позизия элемента по значению('indexOf')\n" ,
		" Показать('show')[пробел]\n",
		" Тестирование('test')\n",
		" Выйти('exit')\n " };

	int size = sizeof(arrStr) / sizeof(string);
	if (index >= size) {
		index = 0;
	}
	else {
		if (index < 0) {
			index = size - 1;
		}
	}
	arrStr[index].insert(arrStr[index].begin(), '>');
	repaintConsole();
	cout << head;
	for (string var : arrStr)
	{
		cout << var;
	}
}

void hideCursor() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

int main()
{
	system("chcp 1251 > nul");

	hideCursor();

	CircleDoubleList<int> list, test_list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);

	list.insert(5, 6);


	CircleDoubleList<int>::iterator it(list.itbegin());
	++it;

	int index = 0;
	while (1) {
		try
		{

			drawMenu(index);
			switch (_getch())//27-esc 13-enter 8 - backspace 32-space
			{
			case 80://up
				index++;
				break;
			case 72://down
				index--;
				break;
			case 32://space
				system("cls");
				cout << "\nПрямой список (от head к tail):\n";
				list.showDirectly(cout);
				system("pause");
				system("cls");
				break;
			case 8:
			case 27://exit
				return 0;
				break;
			case 13://enter
				switch (index)
				{
				case 0://размер

					system("cls");
					cout << "Текущий размер списка: " << list.size() << endl;
					system("pause");
					system("cls");
					break;
				case 1://очистка списка
					system("cls");
					list.clear();
					cout << "Список был очищен\n";
					system("pause");
					system("cls");
					break;
				case 2://Пустой?
					system("cls");
					list.empty() ? cout << "Список пустой\n" : cout << "Список содержит элементы\n";
					system("pause");
					system("cls");
					break;

				case 3://Добавление
					system("cls");
					cout << "Введите значение: ";
					int val;
					checkInt(cin, val);
					list.add(val);

					system("pause");
					system("cls");
					break;
				case 4://Вставка по индексу
					system("cls");

					cout << "Введите индекс: ";
					int ind, value;
					checkInt(cin, ind);
					cout << "Введите значение: ";
					checkInt(cin, value);
					list.insert(ind, value);

					system("pause");
					system("cls");
					break;
				case 5://Получение элемента по индексу
					system("cls");
					cout << "Введите индекс того элемента, который хотите получить:";
					checkInt(cin, ind);
					cout << "Значение элемента №" << ind << " равняется: " << list.get(ind) << endl;
					system("pause");
					system("cls");
					break;
				case 6://Изменение элемента по индексу
					system("cls");

					cout << "Введите индекс: ";
					checkInt(cin, ind);
					cout << "Введите значение: ";
					checkInt(cin, value);
					list.set(ind, value);

					system("pause");
					system("cls");
					break;
				case 7://Удалить элемента по индексу
					system("cls");
					cout << "Введите индекс: ";
					checkInt(cin, ind);
					list.remove(ind);
					system("pause");
					system("cls");
					break;
				case 8://удаление по значению
					system("cls");
					cout << "Введите значение: ";
					checkInt(cin, value);
					list.removeByValue(value);
					system("pause");
					system("cls");
					break;
				case 9://Сожержит ли значение
					system("cls");
					cout << "Введите значение: ";
					checkInt(cin, value);
					list.contains(value) ? cout << "\nТакое значение есть в списке\n" : cout << "\nТакого значения нет в списке\n";
					system("pause");
					system("cls");
					break;
				case 10://Кол-во элементов с таким то значением
					system("cls");
					cout << "Введите значение: ";
					checkInt(cin, value);
					cout << "Позиция первого элемента со значением " << value << " равна:" << list.indexOf(value) << endl;
					system("pause");
					system("cls");
					break;

				case 11://Показать все 
					system("cls");
					cout << "Выберите каким образом показать список:\n1. Прямо \n2. Обратно\n";
					int num;
					cout << "Комманда:";
					checkInt(cin, num);
					if (num == 1) {
						cout << "\nПрямой список (от head к tail):\n";
						list.showDirectly(cout);
					}
					else
					{
						if (num == 2) {
							cout << "\nОбратный список (от tail к head)\n";
							list.showBack(cout);
						}
						else
						{
							cout << "\nТакой комманды нет!\n";
						}
					}
					system("pause");
					system("cls");
					break;
				case 12://Тестирование
					system("cls");
					int amount, range;
					cout << "Введите кол-во элементов списка:";
					checkInt(cin, amount);
					cout << "Диапазон значений будет от 0 до ";
					checkInt(cin, range);
					for (int i = 0; i < amount; i++) {
						test_list.add(rand() % range);
					}
					for (int i = 0; i < amount / 2; i++) {
						test_list.insert(rand() % amount, rand() % range);
						test_list.remove(rand() % (amount + 1));
						test_list.contains(rand() % range);
					}
					cout << "\nКол-во итераций для функции insert() :" << test_list.countMovingInsert << endl;
					cout << "\nКол-во итераций для функции contains() :" << test_list.countMovingFind << endl;
					cout << "\nКол-во итераций для функции delete() :" << test_list.countMovingFind << endl;
					system("pause");
					system("cls");
					break;
				case 13://Exit
					exit(0);
					break;

				}
				break;
			}

		}
		catch (const std::out_of_range& ex)
		{
			system("cls");
			cerr << ex.what() << endl;

			system("pause");
			system("cls");
		}
	}

}


