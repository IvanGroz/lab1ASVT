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


template<typename T>
 void CircleDoubleList<T>::add(T value)
{
    
    if (this->head == nullptr) {
        
        Collection<T>::Node* temp1 = new typename Collection<T>::Node(value);
        this->head = temp1;
        this->tail = temp1;
        this->head->prev = this->tail;
        this->tail->next = this->head;
    }
    else
    {
        Collection<T>::Node* temp2 = new typename Collection<T>::Node(value,nullptr,nullptr);
        this->head->next = temp2;
        this->tail->prev = temp2;
        this->tail = temp2;

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


