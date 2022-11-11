#pragma once
#include "Collection.h"


template<typename T>
class CircleDoubleList : public Collection<T>
{
     Collection<T>::Node* head = nullptr;
      Collection<T>::Node* tail = nullptr;
public:

    int countMovingInsert = 0;				// ���-�� ���������� ��������� ��� ���������� �������� - �������
    int countMovingDelete = 0;				// ���-�� ���������� ��������� ��� ���������� �������� - ��������
    int countMovingFind = 0;				// ���-�� ���������� ��������� ��� ���������� �������� - �����

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

      int size();		// ���������� �������� �������� ������� ������
      bool empty();

      
      void insert(int index, T value)  ;	// ��������� ������ �������� � ��������� �������

      T get(int index)  ;	// ���������� �������� �� ��������� �������
      void set(int index, T value)  ;	// ��������� �������� ��������� �������� ���������

      void remove(int index)  ;	// �������� �������� �� ��������� �������
      void removeByValue(T value)  ;	// �������� ���������� �������� �� ���������

      bool contains(T value)  ;	// ������� ���������� �������� � ���������
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
    this->_size++;
}
template<typename T>
 int CircleDoubleList<T>::size()
{
    return this->_size;
}
template<typename T>
inline bool CircleDoubleList<T>::empty()
{
    return this->head == nullptr;
}
template<typename T>
inline void CircleDoubleList<T>::clear()
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
        delete this->tail ;
        this->tail = this->head->prev;
        this->_size--;
    }
}

template<typename T>
inline void CircleDoubleList<T>::remove(int index)
{
    if (empty()) throw out_of_range("COLLECTION IS EMPTY");
    if (index < 0 || index >= this->_size) throw out_of_range("DOES NOT EXIST BY INDEX");
    typename Collection<T>::Node* temp;
    int i;
    if (index < this->_size / 2) {
        temp = this->head;
        i = 0;
    }
    else {
        temp = this->tail;
        i = this->_size-1;
    }
    for (;true; index < this->_size / 2 ? i++:i--) {
        
        if (i == index) {
            if (index == 0) {
                this->head = temp->next;
            }
            if (index == this->_size-1) {
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
        index < this->_size/2?temp = temp->next:temp = temp->prev;
    }
}

template<typename T>
 void CircleDoubleList<T>::insert(int index, T value)
{
    if (empty()) throw out_of_range("COLLECTION IS EMPTY");
    if (index < 0 || index > this->_size) throw out_of_range("DOES NOT EXIST BY INDEX");
    if (index == this->_size) { this->add(value); return; }
    typename Collection<T>::Node* insertNode = { new typename Collection<T>::Node(value) };
    typename Collection<T>::Node* temp ;
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
    }
}

template<typename T>
inline T CircleDoubleList<T>::get(int index)
{
    if (empty()) throw out_of_range("COLLECTION IS EMPTY");
    if (index < 0 || index >= this->_size) throw out_of_range("DOES NOT EXIST BY INDEX");
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
    if (empty()) throw out_of_range("COLLECTION IS EMPTY");
    if (index < 0 || index >= this->_size) throw out_of_range("DOES NOT EXIST BY INDEX");
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
    for (int i = 0; i < this->_size;i++) {

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
    return false;
}

template<typename T>
inline int CircleDoubleList<T>::indexOf(T value)
{
    return 0;
}


