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
		printf("Стек\n");

		Stack<int> st;

		printf("Добвление в стек: 15, 3, 64, 7\n");
		st.push(15);
		st.push(3);
		st.push(64);
		st.push(7);

		printf("Стек:\n");
		st.print();

		printf("Извлечение из стека : %i\n", st.pop());
		printf("Стек:\n");
		st.print();

		st.~Stack();

		system("pause");
	}
	{
		system("cls");
		printf("Очередь\n");

		Queue<int> qu;

		printf("Добавление в очередь: 5, 2, 64, 4\n");
		qu.push(5);
		qu.push(2);
		qu.push(64);
		qu.push(4);

		printf("Очередь:\n");
		qu.print();

		printf("Извлечение из очереди : %i\n", qu.pop());
		printf("Очередь:\n");
		qu.print();

		qu.~Queue();

		system("pause");
	}
	{
		system("cls");
		printf("Дек\n");

		Deque<int> deq;

		printf("Добавление в дек слева: 8, 11\n");
		deq.push_left(8);
		deq.push_left(11);

		printf("Добавление в дэк справа: 16, 3\n");
		deq.push_right(16);
		deq.push_right(3);

		printf("Дек (left):\n");
		deq.print_left();
		printf("Дек (right):\n");
		deq.print_right();

		printf("Извлечение из дека слева: %i\n", deq.pop_left());
		printf("Извлечение из дека справа: %i\n", deq.pop_right());

		printf("Дек (Слева):\n");
		deq.print_left();
		printf("Дек (Справа):\n");
		deq.print_right();

		deq.~Deque();

	}
	
	return 0;
}

