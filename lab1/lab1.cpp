// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Collection.h"
#include "CircleDoubleList.h"

#include <iostream>
#include <string>

using namespace std;



int main()
{
	CircleDoubleList<int> list;
	list.add(1);
	list.add(4);
	list.add(3);
	list.add(4);
	list.add(5);

	list.insert(5,6);

	list.removeByValue(4);

	list.clear();

	return 0;
}

