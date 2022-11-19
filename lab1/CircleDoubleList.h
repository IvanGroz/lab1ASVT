#pragma once
#include "Collection.h"


template<typename T>
class CircleDoubleList : public Collection<T>
{
	Collection<T>::Node* head = nullptr;
	Collection<T>::Node* tail = nullptr;
public:

	int countMovingInsert = 0;				// Кол-во пройденных элементов при выполнении операции - вставка
	int countMovingDelete = 0;				// Кол-во пройденных элементов при выполнении операции - удаление
	int countMovingFind = 0;				// Кол-во пройденных элементов при выполнении операции - поиск

	CircleDoubleList() {

	}
	CircleDoubleList(CircleDoubleList& list) {
		for (typename Collection<T>::Node* temp = list.head; this->_size != list._size; temp = temp->next) {
			add(temp->value);

		}

	}
	~CircleDoubleList() {
		clear();
	}
	void clear();
	void add(T value);

	int size();		// Возвращает значения текущего размера списка
	bool empty();


	void insert(int index, T value);	// Включение нового значения в указанную позицию

	T get(int index);	// Возвращает значение по указанной позиции
	void set(int index, T value);	// Изменение значения заданного элемента коллекции

	void remove(int index);	// Удаление значения по указанной позиции
	void removeByValue(T value);	// Удаление указанного значения из коллекции

	bool contains(T value);	// Наличие указанного элемента в коллекции
	int indexOf(T value);

	class iterator
	{
	protected:
		typename Collection<T>::Node* current;
	public:
		iterator();
		iterator(typename Collection<T>::Node* current);
		iterator(const iterator& iterator);
		~iterator() {}

		T& operator*();				// Доступ по чтению/записи (возвращает значение элемента)

		iterator operator++(int);	// Оператор постфиксного инкремента
		iterator& operator++();		// Оператор префиксного инкремента

		iterator operator--(int);	// Оператор постфиксного декремента
		iterator& operator--();		// Оператор префиксного декремента

		iterator& operator=(const iterator& iterator);	// Присваивание новой ссылки
		bool operator==(const iterator& iterator);	// Проверка равенства
		bool operator!=(const iterator& iterator);	// Проверка неравенства
	};
	class r_iterator {
		typename Collection<T>::Node* current;
	public:
		r_iterator();
		r_iterator(typename Collection<T>::Node* current);
		r_iterator(const r_iterator& rit);
		~r_iterator() {}

		T& operator*();				// Доступ по чтению/записи (возвращает значение элемента)

		r_iterator operator++(int);	// Оператор постфиксного инкремента
		r_iterator& operator++();		// Оператор префиксного инкремента

		r_iterator operator--(int);	// Оператор постфиксного декремента
		r_iterator& operator--();		// Оператор префиксного декремента

		r_iterator& operator=(const r_iterator& rit);	// Присваивание новой ссылки
		bool operator==(const r_iterator& rit);	// Проверка равенства
		bool operator!=(const r_iterator& rit);	// Проверка неравенства
	};
	iterator itbegin();
	r_iterator ritbegin();

	iterator itend();
	r_iterator ritend();

	void showDirectly(ostream& os);
	void showBack(ostream& os);
};


template<class T>
void CircleDoubleList<T>::add(T value)
{
	typename Collection<T>::Node* temp = { new typename Collection<T>::Node(value) };
	if (this->head == nullptr) {

		//Collection<T>::Node* temp1 = new class Collection<T>::Node(value);

		this->head = temp;
		this->tail = temp;
		this->head->prev = this->tail;
		this->head->next = this->tail;
		this->tail->next = this->head;
		this->tail->prev = this->head;
	}
	else
	{

		this->tail->next = temp;
		temp->prev = this->tail;
		this->tail = temp;
		this->tail->next = this->head;
		this->head->prev = this->tail;

	}
	this->_size++;
}
template<typename T>
int CircleDoubleList<T>::size()
{
	return this->_size;
}
template<typename T>
bool CircleDoubleList<T>::empty()
{
	return this->head == nullptr;
}
template<typename T>
void CircleDoubleList<T>::clear()
{
	while (this->head != nullptr) {
		if (this->head->prev == this->head && this->head->next == this->head)
		{
			delete this->head;
			this->head = this->tail = nullptr;
			this->_size--;
			return;
		}
		this->head->prev = this->tail->prev;
		this->tail->prev->next = this->head;
		this->tail->prev = nullptr;
		this->tail->next = nullptr;
		delete this->tail;
		this->tail = this->head->prev;
		this->_size--;
	}
}

template<typename T>
void CircleDoubleList<T>::remove(int index)
{
	if (empty()) throw out_of_range("Список пуст!");
	if (index < 0 || index >= this->_size) throw out_of_range("В списке такого индекса нет!");
	typename Collection<T>::Node* temp;
	int i;
	if (index < this->_size / 2) {
		temp = this->head;
		i = 0;
	}
	else {
		temp = this->tail;
		i = this->_size - 1;
	}
	for (; true; index < this->_size / 2 ? i++ : i--) {

		if (i == index) {
			if (index == 0) {
				this->head = temp->next;
			}
			if (index == this->_size - 1) {
				this->tail = temp->prev;
			}
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = nullptr;
			temp->prev = nullptr;
			delete temp;
			this->_size--;
			return;
		}
		index < this->_size / 2 ? temp = temp->next : temp = temp->prev;
		countMovingDelete++;
	}
}

template<typename T>
void CircleDoubleList<T>::insert(int index, T value)
{
	if (empty()) throw out_of_range("Список пуст");
	if (index < 0 || index > this->_size) throw out_of_range("В списке такого индекса нет!");
	if (index == this->_size) { this->add(value); return; }
	typename Collection<T>::Node* insertNode = { new typename Collection<T>::Node(value) };
	typename Collection<T>::Node* temp;
	int i;
	if (index < this->_size / 2) {
		temp = this->head;//в случае если ближе к голове
		i = 0;
	}
	else {
		temp = this->tail;
		i = this->_size - 1;
	}
	for (; true; index < this->_size / 2 ? i++ : i--) {
		if (i == index) {
			if (index == 0) {
				this->head = insertNode;
			}
			temp->prev->next = insertNode;
			insertNode->prev = temp->prev;
			insertNode->next = temp;
			temp->prev = insertNode;
			this->_size++;
			return;
		}
		index < this->_size / 2 ? temp = temp->next : temp = temp->prev;
		countMovingInsert++;
	}
}

template<typename T>
T CircleDoubleList<T>::get(int index)
{
	if (empty()) throw out_of_range("Список пуст!");
	if (index < 0 || index >= this->_size) throw out_of_range("В списке такого индекса нет!");
	typename Collection<T>::Node* temp;
	int i;
	if (index < this->_size / 2) {
		temp = this->head;
		i = 0;
	}
	else {
		temp = this->tail;
		i = this->_size - 1;
	}
	for (; true; index < this->_size / 2 ? i++ : i--) {

		if (i == index) {

			return temp->value;
		}
		index < this->_size / 2 ? temp = temp->next : temp = temp->prev;
	}
}

template<typename T>
void CircleDoubleList<T>::set(int index, T value)
{
	if (empty()) throw out_of_range("Список пуст!");
	if (index < 0 || index >= this->_size) throw out_of_range("В списке такого индекса нет!");
	typename Collection<T>::Node* temp;
	int i;
	if (index < this->_size / 2) {
		temp = this->head;
		i = 0;
	}
	else {
		temp = this->tail;
		i = this->_size - 1;
	}
	for (; true; index < this->_size / 2 ? i++ : i--) {

		if (i == index) {

			temp->value = value;
			return;
		}
		index < this->_size / 2 ? temp = temp->next : temp = temp->prev;
	}
}



template<typename T>
void CircleDoubleList<T>::removeByValue(T value)
{
	typename Collection<T>::Node* temp = this->head;
	for (int i = 0; i < this->_size; i++) {

		if (temp->value == value) {
			temp = temp->next;
			this->remove(i);
			removeByValue(value);
		}
		temp = temp->next;

	}

}

template<typename T>
bool CircleDoubleList<T>::contains(T value)
{
	typename Collection<T>::Node* temp = this->head;
	for (int i = 0; i < this->_size; i++) {

		if (temp->value == value) {
			return true;
		}
		temp = temp->next;
		countMovingFind++;
	}
	return false;
}

template<typename T>
int CircleDoubleList<T>::indexOf(T value)
{
	if (head == nullptr)
		throw out_of_range("Список пуст!");
	typename Collection<T>::Node* temp = this->head;
	for (int i = 0; i < this->_size; i++) {

		if (temp->value == value) {
			return i;
		}
		temp = temp->next;

	}
	throw out_of_range("Такого элемента нет!");
	return -1;
}

template<typename T>
typename CircleDoubleList<T>::iterator CircleDoubleList<T>::itbegin()
{
	return this->head;
}

template<typename T>
typename CircleDoubleList<T>::iterator CircleDoubleList<T>::itend()
{
	return this->tail;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator CircleDoubleList<T>::ritbegin()
{
	return this->tail;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator CircleDoubleList<T>::ritend()
{
	return this->head;
}

template<typename T>
inline void CircleDoubleList<T>::showDirectly(ostream& os)
{
	if (empty()) {
		os << "Показывать нечего, коллекция пуста!\n";
		return;
	}
	iterator it = itbegin();
	do
	{
		os << " " << *it << endl;
		++it;
	} while (it != itbegin());
}

template<typename T>
inline void CircleDoubleList<T>::showBack(ostream& os)
{
	if (empty()) {
		os << "Показывать нечего, коллекция пуста!\n";
		return;
	}
	r_iterator it = ritbegin();
	do
	{
		os << " " << *it << endl;
		++it;
	} while (it != ritbegin());
}

template<typename T>
CircleDoubleList<T>::iterator::iterator()
{
	this->current = nullptr;
}

template<typename T>
CircleDoubleList<T>::iterator::iterator(typename Collection<T>::Node* current)
{
	this->current = current;
}

template<typename T>
CircleDoubleList<T>::iterator::iterator(const iterator& iterator)
{
	this->current = iterator.current;
}

template<typename T>
T& CircleDoubleList<T>::iterator::operator*()
{
	return this->current->value;
}

template<typename T>
typename CircleDoubleList<T>::iterator CircleDoubleList<T>::iterator::operator++(int)
{
	iterator temp(*this);
	current = current->next;
	return temp;
}

template<typename T>
typename CircleDoubleList<T>::iterator& CircleDoubleList<T>::iterator::operator++()
{

	current = current->next;
	return *this;
}

template<typename T>
typename CircleDoubleList<T>::iterator CircleDoubleList<T>::iterator::operator--(int)
{
	iterator temp(*this);
	current = current->prev;
	return temp;
}

template<typename T>
typename CircleDoubleList<T>::iterator& CircleDoubleList<T>::iterator::operator--()
{
	current = current->prev;
	return *this;
}

template<typename T>
typename CircleDoubleList<T>::iterator& CircleDoubleList<T>::iterator::operator=(const iterator& it)
{
	this->current = it.current;
	return *this;
}

template<typename T>
bool CircleDoubleList<T>::iterator::operator==(const iterator& it)
{
	return this->current == it.current;
}

template<typename T>
bool CircleDoubleList<T>::iterator::operator!=(const iterator& it)
{
	return this->current != it.current;
}

template<typename T>
inline CircleDoubleList<T>::r_iterator::r_iterator()
{
	this->current == nullptr;
}

template<typename T>
inline CircleDoubleList<T>::r_iterator::r_iterator(typename Collection<T>::Node* currentN)
{
	this->current = currentN;
}

template<typename T>
inline CircleDoubleList<T>::r_iterator::r_iterator(const r_iterator& rit)
{
	this->current = rit.current;
}



template<typename T>
T& CircleDoubleList<T>::r_iterator::operator*()
{
	return this->current->value;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator CircleDoubleList<T>::r_iterator::operator++(int)
{
	r_iterator temp(*this);
	temp.current = this->current->prev;
	return temp;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator& CircleDoubleList<T>::r_iterator::operator++()
{
	this->current = this->current->prev;
	return  *this;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator CircleDoubleList<T>::r_iterator::operator--(int)
{
	r_iterator temp(*this);
	temp.current = this->current->next;

	return temp;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator& CircleDoubleList<T>::r_iterator::operator--()
{
	this->current = this->current->next;
	return *this;
}

template<typename T>
typename CircleDoubleList<T>::r_iterator& CircleDoubleList<T>::r_iterator::operator=(const r_iterator& rit)
{
	this->current = rit.current;
	return *this;
}

template<typename T>
inline bool CircleDoubleList<T>::r_iterator::operator==(const r_iterator& rit)
{
	return this->current == rit.current;
}

template<typename T>
inline bool CircleDoubleList<T>::r_iterator::operator!=(const r_iterator& rit)
{
	return this->current != rit.current;
}
