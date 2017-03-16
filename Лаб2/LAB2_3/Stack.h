#pragma once
#include <string>

template<class T>
class Stack  // ����� ����
{
public:
	Stack() :_tail(0), _head(0) //�����������
	{
	}

	~Stack() // ����������
	{
		while (_head)
		{
			_tail = _head->next;
			delete _head;
			_head = _tail;
		}
	}

	void push(T val) // ��������� �������� � ����
	{
		Node* Temp;
		Temp = new Node;
		Temp->element = val;
		if (_tail == 0)
		{
			_tail = Temp;
		}
		else
		{
			Temp->next = _tail;
			_tail = Temp;
		}
	}

	T pop() // ����� �������� �� ����� � �������������� ��� ������� ������ (���� �������� ���, �� ������ �����)
	{       
		if (_tail == 0)
		{
			throw std::string("Stack is empty!");
		}
		else
		{                      
			T tmp = _tail->element;
			Node* delptr = _tail;
			_tail = _tail->next;
			delete delptr;
			return tmp; 
		}
	}

	void print() // ������ ��������� ����� 
	{
		if (_tail == NULL)
		{
			printf("Error: Stack is empty!\n");
		}
		else
		{
			for (Node* ptr = _tail; ptr != 0; ptr = ptr->next)
			{
				std::cout << ptr->element << ' ';
			}
			std::cout << '\n';
		}
	}
private:
	struct Node // ��������� ��� �������� ��������� (������)
	{
		Node() :element(0), next(0)
		{
		}
		Node* next;
		T element;
	};
	Node* _head;
	Node* _tail;
};

