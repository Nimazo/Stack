#pragma once

#include <iostream>
#include <string>

template<class T>
class Deque // класс очередь
{
public:
	Deque(): _head(NULL), _last(NULL)
	{
	}

	~Deque()
	{
		while (_head)
		{
			Node* tmpNode;
			tmpNode = _head->next;
			delete _head;
			_head = tmpNode;
		}
	}

	void push_left(T val) //добавление элемента с левого края
	{
		
		Node* Temp = new Node;
		Node* current = _head;
		Temp->element = val;
		if (_head == 0)
		{
			_head = Temp;
			_head->next = NULL;
			
			_last = _head;
			return;
		}
		Temp->next = _head;
		_head = Temp;
		Temp->next->prev = _head;
	}

	void push_right(T val) //добавление элемента с правого края
	{
		Node* Temp = new Node;
		Node* current = _last;
		Temp->element = val;
		if (_head == 0)
		{
			_head = Temp;
			_head->next = NULL; 
			_head->prev = NULL;

			_last = _head;
			return;
		}
		_last->next = Temp;
		_last = Temp;
		_last->prev = current;
	}

	T pop_left() //извлечение элемента с левого края
	{
		if (_last == NULL)
		{
			printf("Queue is empty");
		}
		else
		{
			T TempElement = _head->element;

			_head = _head->next;

			Node* delPtr = _head->prev;
			delete delPtr;
			_head->prev = NULL;

			return TempElement;
		}
	}

	T pop_right() //извлечение элемента с правого края
	{
		if (_last == NULL)
		{
			printf("Queue is empty");
		}
		else
		{
			T TempElement = _last->element;

			_last = _last->prev;

			Node* delPtr = _last->next;
			delete delPtr;
			_last->next = NULL;
			
			return TempElement;
		}
	}

	void print_left()
	{
		if (_head == NULL)
		{
			printf("Error: deque is empty!\n");
		}
		else
		{
			for (Node* ptr = _head; ptr != NULL; ptr = ptr->next)
				std::cout << ptr->element << ' ';
			std::cout << '\n';
		}
	}

	void print_right()
	{
		if (_head == NULL)
		{
			printf("Error: deque is empty!\n");
		}
		else
		{
			for (Node* ptr = _last; ptr != NULL; ptr = ptr->prev)
				std::cout << ptr->element << ' ';
			std::cout << '\n';
		}
	}

private:          // двусвязный список
	struct Node
	{
		Node() : element(NULL), next(NULL), prev(NULL)
		{
		}
		Node* next;
		Node* prev;
		T element;
	};
	Node* _head;
	Node* _last;
};