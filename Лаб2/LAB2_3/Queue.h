#pragma once
#include <iostream>
#include <string>

template<class T>
class Queue // класс очередь
{
public:
	Queue() :_head(0), _tail(NULL) //конструктор класса
	{
	}

	~Queue() //деструктор класса
	{
		while (_head)
		{
			_tail = _head->next;
			delete _head;
			_head = _tail;
		}
	}

	void push(T val) //добавление элемента в очередь
	{
		Node* Temp = new Node;
		Temp->element = val;
		if (_head == 0)
		{
			_head = Temp;
			_tail = Temp;
			return;
		}
		_tail->next = Temp;
		_tail = Temp;
	}

	
	T& pop() //извлечение из очереди (если эл. нет, то крашится)
	{
		if (_tail == NULL)
		{
			printf("Queue is empty");
		}
		else
		{
			T tmp = _head->element;
			Node* delPtr = _head;
			_head = _head->next;
			delete delPtr;
			return tmp;
		}
	}
	
	void print()  // печать состояния очереди
	{
		if (_tail == NULL)
		{
			printf("Error: Queue is empty\n");
		}
		else
		{
			for (Node* ptr = _head; ptr != 0; ptr = ptr->next)
				std::cout << ptr->element << ' ';
			std::cout << '\n';
		}
	}

private:
	struct Node
	{
		Node() :next(0), element(0)
		{
		}
		Node* next;
		T element;
	};
	Node* _head;
	Node* _tail;
};