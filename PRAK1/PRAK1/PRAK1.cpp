#include <iostream>
#include <malloc.h>
#include <vector>

using namespace std;

bool degree(int num)
{
	if (num == 0)
	{
		return false;
	}

	if (num == 1)
	{
		return true; // Единица в любой натуральной степени = единице
	}

	if ((num / 2 == 1) && (num % 2 == 0)) // конец рекурсивного деления на основание
	{
		return true;
	}
	else if ((num / 2 != 1) && (num % 2 == 0)) // если число без остатка поделилось на основание, проверяем делится ли делимое на основание (рекурсия)
	{
		return degree(num / 2);
	}
	else if ((num / 2 != 1) && (num % 2 != 0) && (num != 1))
	{
		return false;
	}
	else if ((num / 2 == 1) && (num % 2 != 0)) // если число не делится на основание без остатка, то оно не является степенью этого основания
	{
		return false;
	}
}

bool Mersenn(int num)
{
	if (num <= 1)
	{
		return false; // Простое число не может быть отрицательным
	}

	for (int i = 2; i < 10000; i++)
	{
		if ((num % i == 0) && (num != i))
		{
			return false; // Число не является простым 
		}
	}

	if (degree(num + 1) != true)
	{
		return false;
	}

	return true;
}

int dinamic_count_Mersenn(int* arr, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (Mersenn(arr[i]) == true)
		{
			cnt += 1;
		}
	}

	return cnt;
}

void dinamic_out(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* dinamic_in(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	return arr;
}

int static_count_Mersenn(int arr[1000])
{
	int cnt = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (Mersenn(arr[i]) == true)
		{
			cnt += 1;
		}
	}
	return cnt;
}

void static_out(int arr[1000])
{
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] != -858993460) 
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

int* static_in(int arr[1000], int n)
{
	for (int i = 350; i < 350 + n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	return arr;
}

int vect_count_Mersenn(vector<int> arr)
{
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (Mersenn(arr[i]) == true)
		{
			cnt += 1;
		}
	}
	return cnt;
}

void vect_out(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

vector<int> vect_in(vector<int> arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	return arr;
}

int static_min_id(int static_arr[1000])
{
	int min = INT_MAX, min_id;

	for (int i = 0; i < 1000; i++)
	{
		if (degree(static_arr[i]) == true)
		{
			if (static_arr[i] < min)
			{
				min = static_arr[i];
				min_id = i;
			}
		}
	}
	if (min == INT_MAX) { return 0; }
	else{ return min_id; }
}

int static_min(int static_arr[1000])
{
	int min = INT_MAX;

	for (int i = 0; i < 1000; i++)
	{
		if (degree(static_arr[i]) == true)
		{
			if (static_arr[i] < min)
			{
				min = static_arr[i];
			}
		}
	}
	return min;
}

int* static_del(int static_arr[1000], int min_id)
{
	for (int i = min_id + 1; i < 1000; i++)
	{
		static_arr[i - 1] = static_arr[i];
	}

	return static_arr;
}

int static_max_id(int static_arr[1000])
{
	int max = INT_MIN, max_id = 0;

	for (int i = 0; i < 1000; i++)
	{
		if (Mersenn(static_arr[i]) == true)
		{
			if (static_arr[i] > max)
			{
				max = static_arr[i];
				max_id = i;
			}
		}
	}

	if (max == INT_MIN) { return 0; }
	else { return max_id; }
}

int static_max(int static_arr[1000])
{
	int max = INT_MIN;

	for (int i = 0; i < 1000; i++)
	{
		if (Mersenn(static_arr[i]) == true)
		{
			if (static_arr[i] > max)
			{
				max = static_arr[i];
			}
		}
	}

	return max;
}

int* static_insert(int static_arr[1000], int max_id, int new_el)
{
	for (int i = 0; i < max_id; i++)
	{
		static_arr[i] = static_arr[i + 1];
	}
	static_arr[max_id] = new_el;

	return static_arr;
}

int dinamic_min_id(int* dinamic_arr, int elements)
{
	int min = INT_MAX, min_id;
	for (int i = 0; i < elements; i++)
	{
		if (degree(dinamic_arr[i]) == true)
		{
			if (dinamic_arr[i] < min)
			{
				min = dinamic_arr[i];
				min_id = i;
			}
		}
	}

	if (min == INT_MAX) { return 0; }
	else { return min_id; }
}

int dinamic_min(int* dinamic_arr, int elements)
{
	int min = INT_MAX;
	for (int i = 0; i < elements; i++)
	{
		if (degree(dinamic_arr[i]) == true)
		{
			if (dinamic_arr[i] < min)
			{
				min = dinamic_arr[i];
			}
		}
	}

	return min;
}

int* dinamic_del(int* dinamic_arr, int min_id, int elements)
{
	for (int i = min_id + 1; i < elements; i++)
	{
		dinamic_arr[i - 1] = dinamic_arr[i];
	}
	elements -= 1;
	dinamic_arr = (int*)realloc(dinamic_arr, sizeof(int) * (elements));

	return dinamic_arr;
}

int dinamic_max_id(int* dinamic_arr, int elements)
{
	int max = INT_MIN, max_id = 0;
	for (int i = 0; i < elements; i++)
	{
		if (Mersenn(dinamic_arr[i]) == true)
		{
			if (dinamic_arr[i] > max)
			{
				max = dinamic_arr[i];
				max_id = i;
			}
		}
	}

	if (max == INT_MAX) { return 0; }
	else { return max_id; }
}

int dinamic_max(int* dinamic_arr, int elements)
{
	int max = INT_MIN;
	for (int i = 0; i < elements; i++)
	{
		if (Mersenn(dinamic_arr[i]) == true)
		{
			if (dinamic_arr[i] > max)
			{
				max = dinamic_arr[i];
			}
		}
	}

	return max;
}

int* dinamic_insert(int* dinamic_arr, int elements, int max_id, int new_el)
{
	dinamic_arr = (int*)realloc(dinamic_arr, sizeof(int) * (elements));
	for (int i = elements; i > max_id; i--)
	{
		dinamic_arr[i] = dinamic_arr[i - 1];
	}
	dinamic_arr[max_id + 1] = new_el;

	return dinamic_arr;
}

int vector_min_id(vector<int> vect_arr)
{
	int min = INT_MAX, min_id;
	for (int i = 0; i < vect_arr.size(); i++)
	{
		if (degree(vect_arr[i]) == true)
		{
			if (vect_arr[i] < min)
			{
				min = vect_arr[i];
				min_id = i;
			}
		}
	}

	if (min == INT_MAX) { return 0; }
	else { return min_id; }
}

int vector_min(vector<int> vect_arr)
{
	int min = INT_MAX;
	for (int i = 0; i < vect_arr.size(); i++)
	{
		if (degree(vect_arr[i]) == true)
		{
			if (vect_arr[i] < min)
			{
				min = vect_arr[i];
			}
		}
	}

	return min;
}

int vector_max_id(vector<int> vect_arr)
{
	int max = INT_MIN, max_id = 0;
	for (int i = 0; i < vect_arr.size(); i++)
	{
		if (Mersenn(vect_arr[i]) == true)
		{
			if (vect_arr[i] > max)
			{
				max = vect_arr[i];
				max_id = i;
			}
		}
	}

	if (max == INT_MAX) { return 0; }
	else { return max_id; }
}

int vector_max(vector<int> vect_arr)
{
	int max = INT_MIN;
	for (int i = 0; i < vect_arr.size(); i++)
	{
		if (Mersenn(vect_arr[i]) == true)
		{
			if (vect_arr[i] > max)
			{
				max = vect_arr[i];
			}
		}
	}

	return max;
}

int main()
{
	setlocale(0, "Russian");
	int chosen;
	while (1)
	{
		cout << endl << "Выберите, с какой структурой будет работать программа." << endl;
		cout << "1 - статический массив." << endl;
		cout << "2 - динамический массив." << endl;
		cout << "3 - вектор." << endl;
		cout << "4 - остановить работу программы." << endl << endl;
		cin >> chosen;

		if (chosen == 1)
		{
			int static_arr[1000];
			int cnt, elements, new_el, selected;

			cout << "Укажите, сколько элементов массива вы планируете вводить." << endl;
			cin >> elements;

			cout << "Введите элементы статического массива." << endl;
			static_in(static_arr, elements);

			while (1)
			{
				cout << endl << "Выберите действие" << endl;
				cout << "1 - подсчет чисел Мерсенна." << endl;
				cout << "2 - удаление минимальной степени числа 2." << endl;
				cout << "3 - вставка нового числа, после максимального числа Мерсенна." << endl;
				cout << "4 - выбрать другую структуру и ввести новые данные." << endl << endl;
				cin >> selected;

				if (selected == 1)
				{
					// Подсчет чисел Мерсенна в массиве
					cnt = static_count_Mersenn(static_arr);
					cout << "В массиве содержится столько чисел Мерсенна: " << cnt << endl;
				}
				else if (selected == 2)
				{
					// удаление минимального числа = степени 2
					int min = static_min(static_arr);
					int min_id = static_min_id(static_arr);

					if (min == INT_MAX)
					{
						cout << "В массиве не встречаются степени числа 2." << endl;
					}
					else
					{
						static_del(static_arr, min_id);
						cout << "После удаления элемента массив имеет вид:" << endl;
						static_out(static_arr);
					}
				}
				else if (selected == 3)
				{
					// Вводится элемент, который будет вставлен в массив
					cout << "Введите значение нового элемента массива." << endl;
					cin >> new_el;

					// Поиск максимального числа мерсенна в массиве
					int max_id = static_max_id(static_arr);
					int max = static_max(static_arr);

					if (max == INT_MIN)
					{
						cout << "В массиве не встречаются числа Мерсенна." << endl;
					}
					else
					{
						// Вставка нового элемента в массив
						static_insert(static_arr, max_id, new_el);

						// Вывод массива после вставки нового элемента
						cout << "После вставки нового элемента массив имеет вид:" << endl;
						static_out(static_arr);
					}
				}
				else if (selected == 4)
				{
					break;
				}
			}
		}
		else if (chosen == 2)
		{
			int cnt = 0, elements, new_el, selected;

			cout << "Укажите, сколько элементов массива вы планируете вводить." << endl;
			cin >> elements;
			int* dinamic_arr = (int*)malloc(sizeof(int) * elements);

			cout << "Введите элементы динамического массива." << endl;

			dinamic_in(dinamic_arr, elements);

			while (1)
			{
				cout << endl << "Выберите действие" << endl;
				cout << "1 - подсчет чисел Мерсенна." << endl;
				cout << "2 - удаление минимальной степени числа 2." << endl;
				cout << "3 - вставка нового числа, после максимального числа Мерсенна." << endl;
				cout << "4 - выбрать другую структуру и ввести новые данные." << endl << endl;
				cin >> selected;

				if (selected == 1)
				{
					// Подсчет чисел Мерсенна в массиве
					cnt = dinamic_count_Mersenn(dinamic_arr, elements);
					cout << "В массиве содержится столько чисел Мерсенна: " << cnt << endl;
				}
				else if (selected == 2)
				{
					// Поиск минимального числа в массиве, являющегося степенью числа 2
					int min_id = dinamic_min_id(dinamic_arr, elements);
					int min = dinamic_min(dinamic_arr, elements);

					if (min == INT_MAX)
					{
						cout << "В массиве не встречаются степени числа 2." << endl;
					}
					else
					{
						// удаление минимального числа = степени 2
						dinamic_arr = dinamic_del(dinamic_arr, min_id, elements);
						elements--;

						//вывод массива после удаления элемента
						cout << "После удаления элемента массив имеет вид:" << endl;
						dinamic_out(dinamic_arr, elements);
					}
				}
				else if (selected == 3)
				{
					// Вводится элемент, который будет вставлен в массив
					cout << "Введите значение нового элемента массива." << endl;
					cin >> new_el;

					// Поиск максимального числа мерсенна в массиве

					int max_id = dinamic_max_id(dinamic_arr, elements);
					int max = dinamic_max(dinamic_arr, elements);

					if (max == INT_MIN)
					{
						cout << "В массиве не встречаются числа Мерсенна." << endl;
					}
					else
					{
						elements += 1;
						dinamic_arr = dinamic_insert(dinamic_arr, elements, max_id, new_el);

						// Вывод массива после вставки нового элемента
						cout << "После вставки нового элемента массив имеет вид:" << endl;
						dinamic_out(dinamic_arr, elements);
					}
				}
				else if (selected == 4)
				{
					break;
				}
			}
			free(dinamic_arr);
		}
		else if (chosen == 3)
		{
			int cnt, elements, new_el, selected;

			cout << "Укажите, сколько элементов вы планируете вводить." << endl;
			cin >> elements;
			vector<int> vect_arr;

			cout << "Введите элементы вектора." << endl;
			vect_arr = vect_in(vect_arr, elements);

			while (1)
			{
				cout << endl << "Выберите действие" << endl;
				cout << "1 - подсчет чисел Мерсенна." << endl;
				cout << "2 - удаление минимальной степени числа 2." << endl;
				cout << "3 - вставка нового числа, после максимального числа Мерсенна." << endl;
				cout << "4 - выбрать другую структуру и ввести новые данные." << endl << endl;
				cin >> selected;

				if (selected == 1)
				{
					// Подсчет чисел Мерсенна в массиве
					cnt = vect_count_Mersenn(vect_arr);
					cout << "В векторе содержится столько чисел Мерсенна: " << cnt << endl;
				}
				else if (selected == 2)
				{
					// Поиск минимального числа в векторе, являющегося степенью числа 2

					int min_id = vector_min_id(vect_arr);
					int min = vector_min(vect_arr);

					if (min == INT_MAX)
					{
						cout << "В векторе не встречаются степени числа 2." << endl;
					}
					else
					{
						vect_arr.erase(vect_arr.begin() + min_id);

						// вывод массива после удаления элемента
						cout << "После удаления элемента вектор имеет вид:" << endl;
						vect_out(vect_arr);
					}
				}
				else if (selected == 3)
				{
					// Вводится элемент, который будет вставлен в массив
					cout << "Введите значение нового элемента массива." << endl;
					cin >> new_el;

					// Поиск максимального числа мерсенна в массиве
					int max_id = vector_max_id(vect_arr);
					int max = vector_max(vect_arr);

					if (max == INT_MIN)
					{
						cout << "В векторе не встречаются числа Мерсенна." << endl;
					}
					else
					{
						vect_arr.insert(vect_arr.begin() + max_id + 1, new_el);

						// Вывод массива после вставки нового элемента
						cout << "После вставки нового элемента массив имеет вид:" << endl;
						vect_out(vect_arr);
					}
				}
				else if (selected == 4)
				{
					break;
				}
			}
		}
		else if (chosen == 4) { break; }
	}
}