#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Collection
{
protected:
	class Node		// ����� ��� �������� ������� ���������
	{
	public:
		Node();		// ����������� �� ���������
		Node(T value, Node* prev = nullptr, Node* next = nullptr); // ����������� � �����������
		Node(const Node& node);	// ����������� �����������
		~Node();				// ����������

		T value;				// �������� ������
		Node* next;				// ��������� �� ��������� �������
		Node* prev;				// ��������� �� ���������� �������
	};
	int _size = 0;				// ������ ��������� (����� ��������� � �������)
public:
	virtual int size() = 0;		// ���������� �������� �������� ������� ������
	virtual void clear() = 0;	// ������� ��������� ���������
	virtual bool empty() = 0;	// �������� ��������� �� �������

	virtual void add(T value) = 0;	// ���������� ������ �������� (� ����� ���������)
	virtual void insert(int index, T value) = 0;	// ��������� ������ �������� � ��������� �������

	virtual T get(int index) = 0;	// ���������� �������� �� ��������� �������
	virtual void set(int index, T value) = 0;	// ��������� �������� ��������� �������� ���������

	virtual void remove(int index) = 0;	// �������� �������� �� ��������� �������
	virtual void removeByValue(T value) = 0;	// �������� ���������� �������� �� ���������

	virtual bool contains(T value) = 0;	// ������� ���������� �������� � ���������
	virtual int indexOf(T value) = 0;	// ��������� ������� �������� � ���������

	virtual ~Collection() {}	// ����������� ����������
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
