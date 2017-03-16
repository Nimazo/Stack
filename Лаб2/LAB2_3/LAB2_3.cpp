#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	{
		setlocale(LC_ALL, "Russian");
		printf("����\n");

		Stack<int> st;

		printf("��������� � ����: 15, 3, 64, 7\n");
		st.push(15);
		st.push(3);
		st.push(64);
		st.push(7);

		printf("����:\n");
		st.print();

		printf("���������� �� ����� : %i\n", st.pop());
		printf("����:\n");
		st.print();

		st.~Stack();

		system("pause");
	}
	{
		system("cls");
		printf("�������\n");

		Queue<int> qu;

		printf("���������� � �������: 5, 2, 64, 4\n");
		qu.push(5);
		qu.push(2);
		qu.push(64);
		qu.push(4);

		printf("�������:\n");
		qu.print();

		printf("���������� �� ������� : %i\n", qu.pop());
		printf("�������:\n");
		qu.print();

		qu.~Queue();

		system("pause");
	}
	{
		system("cls");
		printf("���\n");

		Deque<int> deq;

		printf("���������� � ��� �����: 8, 11\n");
		deq.push_left(8);
		deq.push_left(11);

		printf("���������� � ��� ������: 16, 3\n");
		deq.push_right(16);
		deq.push_right(3);

		printf("��� (left):\n");
		deq.print_left();
		printf("��� (right):\n");
		deq.print_right();

		printf("���������� �� ���� �����: %i\n", deq.pop_left());
		printf("���������� �� ���� ������: %i\n", deq.pop_right());

		printf("��� (�����):\n");
		deq.print_left();
		printf("��� (������):\n");
		deq.print_right();

		deq.~Deque();

	}
	
	return 0;
}

