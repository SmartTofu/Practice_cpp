#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <iostream>
#define queue_size 1000

using namespace std;

class queue
{
public:

	int max_size;
	int* content;
	int head;
	int tail;

	queue(int size)
	{
		max_size = size;
		content = new int[max_size];
		head = 0;
		tail = -1;
	}

	void enqueue(int num)
	{
		if (tail == max_size - 1)
		{
			tail = -1;
		}
		content[++tail] = num;
	}

	int dequeue()
	{
		int tmp = content[head++];
		if (head == max_size) { head = 0; }
		return tmp;
	}
};

class stack
{
public:

	int max_size;
	int* content;
	int quantity;

	stack(int size)
	{
		max_size = size;
		content = new int[max_size];
		quantity = 0;
	}

	void push(int num)
	{
		content[quantity] = num;
		quantity++;
		if (quantity == max_size)
		{
			quantity--;
		}
	}

	int pop()
	{
		int res = content[quantity - 1];
		content[quantity - 1] = NULL;
		quantity--;
		return res;
	}
};

void char_arr_reverse(char str1[queue_size])
{
	for (int i = 0; i < queue_size; i++)
	{
		str1[queue_size - 1 - i] = str1[i];
	}

	for (int i = 0; i < queue_size; i++)
	{
		if ((i < queue_size / 2) || (str1[i] < '0' || str1[i] >'9')) { str1[i] = NULL; }
	}
}

void from_char_to_queue(char str1[queue_size], queue queue1)
{
	for (int i = 0; i < queue_size; i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')
		{
			int tmp_int = str1[i] - '0';
			queue1.enqueue(tmp_int);
		}
	}
}

void addition(queue queue1, queue queue2, queue queue3)
{
	int term1, term2, sum, transfer = 0;
	for (int i = 0; i < queue_size; i++)
	{
		term1 = queue1.dequeue();
		if (term1 < 0 || term1 > 9)
		{
			term1 = 0;
		}

		term2 = queue2.dequeue();
		if (term2 < 0 || term2 > 9)
		{
			term2 = 0;
		}

		sum = term1 + term2 + transfer;
		transfer = sum / 10;
		queue3.enqueue(sum % 10);
	}
}

void result_reverse(queue queue3, stack addition_res)
{
	for (int i = 0; i < queue_size; i++)
	{
		int tmp = queue3.dequeue();
		addition_res.push(tmp);
	}

	for (int i = 0; i < queue_size; i++)
	{
		int tmp = addition_res.pop();
		queue3.enqueue(tmp);
	}
}

void result_out(queue queue3)
{
	int flag = 0;
	for (int i = 0; i < queue_size; i++)
	{
		int tmp = queue3.dequeue();
		if (tmp > 0 && tmp <= 9)
		{
			cout << tmp;
			flag = 1;
		}
		else if (tmp == 0 && flag == 1)
		{
			cout << tmp;
		}
	}
}

void char_arr_reverse_s(char str1[queue_size])
{
	for (int i = 0; i < queue_size; i++)
	{
		str1[queue_size - 1 - i] = str1[i];
	}

	for (int i = 0; i < queue_size; i++)
	{
		if ((i < queue_size / 2) || ((str1[i] < '0' || str1[i] >'9') && (str1[i] != '+' && str1[i] != '-' && str1[i] != '*' && str1[i] != '/'))){ str1[i] = NULL; }
	}
}

int operations(char str1[queue_size], stack operands)
{
	int term1, term2, res;
	for (int i = 0; i < queue_size; i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')
		{
			int tmp_int = str1[i] - '0';
			operands.push(tmp_int);
		}
		else if (str1[i] == '+')
		{
			term1 = operands.pop();
			term2 = operands.pop();
			res = term1 + term2;
			operands.push(res);
		}
		else if (str1[i] == '-')
		{
			term1 = operands.pop();
			term2 = operands.pop();
			res = term1 - term2;
			operands.push(res);
		}
		else if (str1[i] == '*')
		{
			term1 = operands.pop();
			term2 = operands.pop();
			res = term1 * term2;
			operands.push(res);
		}
		else if (str1[i] == '/')
		{
			term1 = operands.pop();
			term2 = operands.pop();
			res = term1 / term2;
			operands.push(res);
		}
	}
	res = operands.pop();
	return res;
}

int main()
{
	setlocale(0, "Russian");
	int chosen;
	while (1)
	{
		cout << "Выберите задачу" << endl;
		cout << "1 - вычислить значение выражения в префиксной форме" << endl;
		cout << "2 - сложить два больших числа" << endl;
		cout << "3 - завершить работу программы" << endl << endl;;
		cin >> chosen;
		cout << endl;

		if (chosen == 1)
		{
			char str1[queue_size];

			cout << "Введите выражение в префиксной форме" << endl;
			cin.ignore();
			gets_s(str1);
			cout << endl;

			char_arr_reverse_s(str1);
			stack operands(queue_size);

			int res = operations(str1, operands);
			cout << "Значение выражения:" << endl;
			cout << res << endl << endl;;
		}
		else if (chosen == 2)
		{
			char str1[queue_size];
			char str2[queue_size];

			cout << "Введите первое большое число" << endl;
			cin.ignore();
			gets_s(str1);
			cout << endl;
			cout << "Введите второе большое число" << endl;
			gets_s(str2);
			cout << endl;

			// РАЗВОРОТ СТРОК
			char_arr_reverse(str1);
			char_arr_reverse(str2);

			// ОБЪЯВЛЕНИЕ ОЧЕРЕДЕЙ
			queue queue1(queue_size);
			queue queue2(queue_size);

			// ПЕРЕНОС ИЗ СТРОКИ В ОЧЕРЕДЬ
			from_char_to_queue(str1, queue1);
			from_char_to_queue(str2, queue2);

			queue queue3(queue_size);
			stack addition_res(queue_size);

			// СЛОЖЕНИЕ
			addition(queue1, queue2, queue3);

			// РАЗВОРОТ ОТВЕТА
			result_reverse(queue3, addition_res);

			// ВЫВОД ОТВЕТА
			cout << "Результат сложения этих чисел:" << endl;
			result_out(queue3);
			cout << endl << endl;
		}
		else if (chosen == 3)
		{
			return 0;
		}
		else
		{
			cout << "Ошибка ввода!" << endl << endl;
		}
	}
}