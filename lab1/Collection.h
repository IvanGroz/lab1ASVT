#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Collection
{
protected:
	class Node		// Класс для элемента связной структуры
	{
	public:
		Node();		// Конструктор по умолчанию
		Node(T value, Node* prev = nullptr, Node* next = nullptr); // Конструктор с параметрами
		Node(const Node& node);	// Конструктор копирования
		~Node();				// Деструктор

		T value;				// Значение данных
		Node* next;				// Указатель на следующий элемент
		Node* prev;				// Указатель на предыдущий элемент
	};
	int _size = 0;				// Размер коллекции (число элементов с данными)
public:
	virtual int size() = 0;		// Возвращает значения текущего размера списка
	virtual void clear() = 0;	// Очищает коллекцию полностью
	virtual bool empty() = 0;	// Проверка коллекции на пустоту

	virtual void add(T value) = 0;	// Добавление нового элемента (в конец коллекции)
	virtual void insert(int index, T value) = 0;	// Включение нового значения в указанную позицию

	virtual T get(int index) = 0;	// Возвращает значение по указанной позиции
	virtual void set(int index, T value) = 0;	// Изменение значения заданного элемента коллекции

	virtual void remove(int index) = 0;	// Удаление значения по указанной позиции
	virtual void removeByValue(T value) = 0;	// Удаление указанного значения из коллекции

	virtual bool contains(T value) = 0;	// Наличие указанного элемента в коллекции
	virtual int indexOf(T value) = 0;	// Получении позиции элемента в коллекции

	virtual ~Collection() {}	// Виртуальный деструктор
};

template<typename T>
Collection<T>::Node::Node()
{
	this->value = nullptr;
	this->next = nullptr;
	this->prev = nullptr;
}

template<typename T>
Collection<T>::Node::Node(T value, Node* prev, Node* next)
{
	this->value = value;
	this->prev = prev;
	this->next = next;
}

template<typename T>
Collection<T>::Node::Node(const Node& node)
{
	this->value = node.value;
	this->prev = node.prev;
	this->next = node.next;
}

template<typename T>
Collection<T>::Node::~Node()
{
	delete this->prev;
	delete this->next;
}
