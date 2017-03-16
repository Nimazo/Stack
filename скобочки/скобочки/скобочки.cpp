#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;
struct Par
{
	int first;  // ������ (
	int second; // ������ )
};
struct Node
{
	Par data;          // ������� ������
	struct Node* next;
};
Node* Push(Node** stack, const Par data) // ������� ���������� ������ � ����
{
	Node* node = new Node;
	node->data = data;
	node->next = *stack;
	*stack = node;
	return *stack;
}
Par Pop(Node** stack) // ������� ���������� �� �����
{
	Node* node = *stack;
	*stack = node->next;
	Par data = node->data;
	delete(node);
	return data;
}
void Print(const Node* stack) // ������� ������� ��� �������� �����
{
	for (; stack; stack = stack->next)
	{
		cout << " (" << stack->data.first;
		cout << ";" << stack->data.second << ") ";
	}
}

Node* PushSort(Node** stack, const Par data, int(*func)(const Par*, const Par*))//���������� ����� ������ ������ � ����������.
{
	Node* head = new Node;
	head->next = *stack;
	Node* cur = head; // ������ ������� � ����� ����������� �� ������
	for (; cur->next && (func(&data, &cur->next->data) > 0); cur = cur->next)
	{
		;
	} // ���� ������ �����
	Push(&cur->next, data);// ��������� ��������� ������� ���� ��������
	*stack = head->next;
	delete(head);
	return *stack;
}

int Compare(const Par* a, const Par* b) // ������� ��������� ���� �������� Par.
{
	return (a->first - b->first);
}

void PosBrecket(char* C)
{
	Node* temp = NULL;
	Node* result = NULL;
	Par data; // ��������������� ����������
	int pos = 0;
	for (; *C; C++)
	{
		pos++;
		switch (*C)
		{
		case '(':
		{
			data.first = pos;
			Push(&temp, data);
			break;
		}
		case ')':
		{
			data = Pop(&temp);
			data.second = pos;
			PushSort(&result, data, Compare);
			break;
		}
		}
	}
	Print(result);
}

int main()
{
	char C[110];
	ifstream fin("Log.txt");
	fin.getline(C, 50);
	cout << C << endl;
	PosBrecket(C);
	fin.close();
	return 0;
}