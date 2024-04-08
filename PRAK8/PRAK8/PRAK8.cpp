#include <iostream>
#include <Windows.h>
#include <chrono>

using namespace std;

void ArrayOut(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void CopyArray(int* from_arr, int* to_arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		to_arr[i] = from_arr[i];
	}
}

int* ReverseArray(int* arr, int n)
{
	int* new_arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		new_arr[i] = arr[n - i - 1];
	}
	return new_arr;
}

void RandomGenerator(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}
}

void InsertionSort(int* arr, int n, long long& C, long long& M)
{
	int key;
	for (int j = 1; j < n; j++)
	{
		C++;
		key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			C++;
			M++;
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}

void ShellSort(int* arr, int* gaps, int quantity, long long& C, long long& M)
{
	int n;
	for (int i = 0; i < 10; i++)
	{
		if (quantity > gaps[i]) { n = i; }
		C++;
	}

	int tmp, j;
	bool flag = true;
	for (int step = gaps[n]; flag; step = gaps[n])
	{
		if (step == 1) { flag = false; }
		C++;
		for (int i = step; i < quantity; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				C++;
				if (tmp < arr[j - step])
				{
					arr[j] = arr[j - step];
					M++;
				}
				else
					break;
			}
			arr[j] = tmp;
		}
		n--;
	}
}

void Merge(int* arr, int left, int middle, int right, long long& C, long long& M)
{
	// Инициализация размеров подчинённых массивов
	int exstra_size_one = middle - left + 1;
	int exstra_size_two = right - middle;

	// Выделение памяти под подчинённые массивы
	int* exstra_arr_one = new int[exstra_size_one];
	int* exstra_arr_two = new int[exstra_size_two];

	// Заполнение подчинённых массивов данными
	for (int i = 0; i < exstra_size_one; i++)
	{
		exstra_arr_one[i] = arr[left + i];
	}
	for (int j = 0; j < exstra_size_two; j++)
	{
		exstra_arr_two[j] = arr[middle + 1 + j];
	}

	// Инициализация начальных индексов для массивов
	int first_idx = 0, second_idx = 0;
	int main_idx = left;

	while (first_idx < exstra_size_one && second_idx < exstra_size_two)
	{
		C++;
		if (exstra_arr_one[first_idx] <= exstra_arr_two[second_idx])
		{
			arr[main_idx] = exstra_arr_one[first_idx];
			first_idx++;
		}
		else
		{
			arr[main_idx] = exstra_arr_two[second_idx];
			second_idx++;
		}
		M++;
		main_idx++;
	}

	// Перенос из дополнительных массивов в основной
	while (first_idx < exstra_size_one)
	{
		arr[main_idx] = exstra_arr_one[first_idx];
		first_idx++;
		main_idx++;
	}
	
	while (second_idx < exstra_size_two)
	{
		arr[main_idx] = exstra_arr_two[second_idx];
		second_idx++;
		main_idx++;
	}

	// Очистка памяти
	delete[] exstra_arr_one;
	delete[] exstra_arr_two;
}

void MergeSort(int* arr, int begin, int end, long long& C, long long& M)
{
	C++;
	if (begin >= end) return;

	int middle = begin + (end - begin) / 2;
	MergeSort(arr, begin, middle, C, M);
	MergeSort(arr, middle + 1, end, C, M);
	Merge(arr, begin, middle, end, C, M);
}


int main()
{
	setlocale(0, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	long long  C1 = 0, M1 = 0, C2 = 0, M2 = 0, C3 = 0, M3 = 0;

//============================================================  AVG  =========================================================================

	int n;
	cout << "Введите количество элементов массива" << endl << endl;
	cin >> n;
	cout << endl;

	
	int* arr = new int[n];
	int* copy = new int[n];

	RandomGenerator(arr, n);
	CopyArray(arr, copy, n);

	/*ArrayOut(arr, n);
	cout << endl;*/

#pragma region GAPS_GENERATOR

	int* gaps = new int[10];
	int d;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			d = 9 * (pow(2, i) - pow(2, i / 2)) + 1;
		}
		else
		{
			d = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
		}
		gaps[i] = d;
	}

#pragma endregion

	auto start = std::chrono::steady_clock::now();
	InsertionSort(arr, n, C1, M1);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds1 = end - start;

	/*ArrayOut(arr, n);
	cout << endl;*/

	CopyArray(copy, arr, n);

	/*ArrayOut(arr, n);
	cout << endl;*/

	start = std::chrono::steady_clock::now();
	ShellSort(arr, gaps, n, C2, M2);
	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end - start;

	/*ArrayOut(arr, n);
	cout << endl;*/

	CopyArray(copy, arr, n);

	/*ArrayOut(arr, n);
	cout << endl;*/

	start = std::chrono::steady_clock::now();
	MergeSort(arr, 0, n - 1, C3, M3);
	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end - start;

	/*ArrayOut(arr, n);
	cout << endl;*/

	cout << "avg Insertion C = " << C1 << "    M = " << M1 << "    t=" << elapsed_seconds1.count() << endl;
	cout << "avg Shell C = " << C2 << "    M = " << M2 << "        t=" << elapsed_seconds2.count() << endl;
	cout << "avg Merge C = " << C3 << "    M = " << M3 << "        t=" << elapsed_seconds3.count() << endl;
	cout << endl << endl;

//============================================================  BEST  =========================================================================

	C1 = C2 = C3 = M1 = M2 = M3 = 0;

	start = std::chrono::steady_clock::now();
	InsertionSort(arr, n, C1, M1);
	end = std::chrono::steady_clock::now();
	elapsed_seconds1 = end - start;

	start = std::chrono::steady_clock::now();
	ShellSort(arr, gaps, n, C2, M2);
	end = std::chrono::steady_clock::now();
	elapsed_seconds2 = end - start;

	start = std::chrono::steady_clock::now();
	MergeSort(arr, 0, n - 1, C3, M3);
	end = std::chrono::steady_clock::now();
	elapsed_seconds3 = end - start;

	/*ArrayOut(arr, n);
	cout << endl;*/

	cout << "best Insertion C = " << C1 << "    M = " << M1 << "    t=" << elapsed_seconds1.count() << endl;
	cout << "best Shell C = " << C2 << "    M = " << M2 << "        t=" << elapsed_seconds2.count() << endl;
	cout << "best Merge C = " << C3 << "    M = " << M3 << "        t=" << elapsed_seconds3.count() << endl;
	cout << endl << endl;

//============================================================  WORST  =========================================================================

	C1 = C2 = C3 = M1 = M2 = M3 = 0;
	arr = ReverseArray(arr, n);
	CopyArray(arr, copy, n);

	/*ArrayOut(arr, n);
	cout << endl;*/

	start = std::chrono::steady_clock::now();
	InsertionSort(arr, n, C1, M1);
	end = std::chrono::steady_clock::now();
	elapsed_seconds1 = end - start;
	CopyArray(copy, arr, n);

	start = std::chrono::steady_clock::now();
	ShellSort(arr, gaps, n, C2, M2);
	end = std::chrono::steady_clock::now();
	elapsed_seconds2 = end - start;
	CopyArray(copy, arr, n);

	start = std::chrono::steady_clock::now();
	MergeSort(arr, 0, n - 1, C3, M3);
	end = std::chrono::steady_clock::now();
	elapsed_seconds3 = end - start;

	cout << "worst Insertion C = " << C1 << "    M = " << M1 << "    t=" << elapsed_seconds1.count() << endl;
	cout << "worst Shell C = " << C2 << "    M = " << M2 << "        t=" << elapsed_seconds2.count() << endl;
	cout << "worst Merge C = " << C3 << "    M = " << M3 << "        t=" << elapsed_seconds3.count() << endl;
	cout << endl << endl;
}