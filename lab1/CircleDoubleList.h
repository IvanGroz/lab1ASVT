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
        for (typename Collection<T>::Node* temp = list.head; temp != list.tail->next; temp = temp->next) {
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

      
      void insert(int index, T value)  ;	// Включение нового значения в указанную позицию

      T get(int index)  ;	// Возвращает значение по указанной позиции
      void set(int index, T value)  ;	// Изменение значения заданного элемента коллекции

      void remove(int index)  ;	// Удаление значения по указанной позиции
      void removeByValue(T value)  ;	// Удаление указанного значения из коллекции

      bool contains(T value)  ;	// Наличие указанного элемента в коллекции
      int indexOf(T value)  ;
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
}
template<typename T>
 int CircleDoubleList<T>::size()
{
    return 0;
}
template<typename T>
inline bool CircleDoubleList<T>::empty()
{
    return false;
}
template<typename T>
inline void CircleDoubleList<T>::clear()
{
    while (head != nullptr) {
        remove(0);
    }
}

template<typename T>
inline void CircleDoubleList<T>::insert(int index, T value)
{
}

template<typename T>
inline T CircleDoubleList<T>::get(int index)
{
    return T();
}

template<typename T>
inline void CircleDoubleList<T>::set(int index, T value)
{
}

template<typename T>
inline void CircleDoubleList<T>::remove(int index)
{
}

template<typename T>
inline void CircleDoubleList<T>::removeByValue(T value)
{
}

template<typename T>
inline bool CircleDoubleList<T>::contains(T value)
{
    return false;
}

template<typename T>
inline int CircleDoubleList<T>::indexOf(T value)
{
    return 0;
}


