#include <iostream>
#include <vector>
#define ROWS 50
#define COLS 50

using namespace std;

int in_matrix(int arr[ROWS][COLS], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> arr[i][j];
		}
	}
	return arr[ROWS][COLS];
}

int** in_d_matrix(int** arr, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> arr[i][j];
		}
	}
	return arr;
}

int random_in(int arr[ROWS][COLS], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			arr[i][j] = (rand() % 10);
		}
	}
	return arr[ROWS][COLS];
}

int** random_d_in(int** arr, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			arr[i][j] = (rand() % 10);
		}
	}
	return arr;
}

void out_matrix(int arr[ROWS][COLS], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void out_d_matrix(int** arr, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void out_char_matrix(char arr[ROWS][COLS], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void out_char_d_matrix(char** arr, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int new_matrix(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int n, int k)
{
	arr2[n - 1][k - 1] = arr1[n - 1][k - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		arr2[i][k - 1] = arr1[i][k - 1] + arr2[i + 1][k - 1];
	}

	for (int i = k - 2; i >= 0; i--)
	{
		arr2[n - 1][i] = arr1[n - 1][i] + arr2[n - 1][i + 1];
	}

	for (int i = k - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			arr2[i][j] = arr1[i][j] + min(arr2[i][j + 1], arr2[i + 1][j]);
		}
	}

	return arr2[ROWS][COLS];
}

int** new_d_matrix(int** arr1, int** arr2, int n, int k)
{
	arr2[n - 1][k - 1] = arr1[n - 1][k - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		arr2[i][k - 1] = arr1[i][k - 1] + arr2[i + 1][k - 1];
	}

	for (int i = k - 2; i >= 0; i--)
	{
		arr2[n - 1][i] = arr1[n - 1][i] + arr2[n - 1][i + 1];
	}

	for (int i = k - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			arr2[i][j] = arr1[i][j] + min(arr2[i][j + 1], arr2[i + 1][j]);
		}
	}

	return arr2;
}

char way(char way_matrix[ROWS][COLS], int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int n, int k)
{
	way_matrix[0][0] = '*';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if ((matrix2[i][j] - matrix2[i + 1][j] == matrix1[i][j] && way_matrix[i][j] == '*')
				|| (matrix2[i][j] - matrix2[i][j + 1] == matrix1[i][j] && way_matrix[i][j] == '*'))
			{
				if (matrix2[i][j] - matrix2[i + 1][j] == matrix1[i][j])
				{
					way_matrix[i + 1][j] = '*';
					break;
				}
				else
				{
					way_matrix[i][j + 1] = '*';
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (way_matrix[i][j] != '*')
			{
				way_matrix[i][j] = '0';
			}
		}
	}
	return way_matrix[ROWS][COLS];
}

char** way_d(char** way_matrix, int** matrix1, int** matrix2, int n, int k)
{
	way_matrix[0][0] = '*';
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if ((matrix2[i][j] - matrix2[i + 1][j] == matrix1[i][j] && way_matrix[i][j] == '*')
				|| (matrix2[i][j] - matrix2[i][j + 1] == matrix1[i][j] && way_matrix[i][j] == '*'))
			{
				if (matrix2[i][j] - matrix2[i + 1][j] == matrix1[i][j])
				{
					way_matrix[i + 1][j] = '*';
					break;
				}
				else
				{
					way_matrix[i][j + 1] = '*';
				}
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (way_matrix[i][j] != '*')
			{
				way_matrix[i][j] = '0';
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		if (way_matrix[n - 2][i] == '*')
		{
			way_matrix[n - 2][i + 1] = '*';
		}
	}
	return way_matrix;
}

vector<vector<int>> in_vector(int rows)
{
	vector<vector<int>> vector1;
	vector1.resize(rows);

	for (int i = 0; i < rows; i++)
	{
		vector1[i].resize(2);
		for (int j = 0; j < 2; j++)
		{
			int val;
			cin >> val;
			vector1[i][j] = val;
		}
	}

	return vector1;
}

void out_vector(vector<vector<int>> vector1)
{
	for (int i = 0; i < vector1.size(); i++)
	{
		for (int j = 0; j < vector1[i].size(); j++)
		{
			cout << vector1[i][j] << " ";
		}
		cout << endl;
	}
}

vector<double> two_points_circle(vector<vector<int>> vector1)
{
	double min_radius = INT_MAX;
	vector<double> args = { 0, 0, 0 };
	for (int i = 0; i < vector1.size() - 1; i++)
	{
		for (int j = i + 1; j < vector1.size(); j++)
		{
			double x1 = vector1[i][0], y1 = vector1[i][1], x2 = vector1[j][0], y2 = vector1[j][1];
			double center_x = (x1 + x2) * 0.5;
			double center_y = (y1 + y2) * 0.5;
			double radius = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5) * 0.5;
			bool flag = true;
			for (int f = 0; f < vector1.size(); f++)
			{
				if ((pow(center_x - vector1[f][0], 2) + pow(center_y - vector1[f][1], 2)) > pow(radius, 2))
				{
					flag = false;
				}
			}
			if (((flag == true) && (radius < min_radius)) || vector1.size() == 2)
			{
				min_radius = radius;
				args[0] = center_x;
				args[1] = center_y;
				args[2] = min_radius;
			}
		}
	}
	return args;
}

vector<double> three_points_circle(vector<vector<int>> vector1)
{
	double min_radius = INT_MAX;
	vector<double> args = { 0, 0, 0 };
	for (int i = 0; i < vector1.size() - 2; i++)
	{
		for (int j = i + 1; j < vector1.size() - 1; j++)
		{
			for (int t = j + 1; t < vector1.size(); t++)
			{
				double x1 = vector1[i][0], y1 = vector1[i][1], x2 = vector1[j][0], y2 = vector1[j][1], x3 = vector1[t][0], y3 = vector1[t][1];
				double x12 = x1 - x2, x23 = x2 - x3, x31 = x3 - x1;
				double y12 = y1 - y2, y23 = y2 - y3, y31 = y3 - y1;
				double z1 = pow(x1, 2) + pow(y1, 2), z2 = pow(x2, 2) + pow(y2, 2), z3 = pow(x3, 2) + pow(y3, 2);
				double zx = y12 * z3 + y23 * z1 + y31 * z2, zy = x12 * z3 + x23 * z1 + x31 * z2, z = x12 * y31 - y12 * x31;
				double center_x = (-1) * zx * pow(2 * z, -1);
				double center_y = zy * pow(2 * z, -1);
				double radius = pow(pow(x1 - center_x, 2) + pow(y1 - center_y, 2), 0.5);
				bool flag = true;
				for (int f = 0; f < vector1.size(); f++)
				{
					if ((pow(vector1[f][0] - center_x, 2) + pow(vector1[f][1] - center_y, 2)) > pow(radius, 2))
					{
						flag = false;
					}
				}
				if ((flag == true) && (radius < min_radius))
				{
					min_radius = radius;
					args[0] = center_x;
					args[1] = center_y;
					args[2] = min_radius;
				}
			}
		}
	}
	return args;
}

int main()
{
	setlocale(0, "Russian");
	int changed;

	cout << "С какой структурой планируете работать?" << endl;
	cout << "1 - статический массив." << endl;
	cout << "2 - динамичсекий массив." << endl;
	cout << "3 - вектор." << endl << endl;
	cin >> changed;
	cout << endl;

	if (changed == 1)
	{
		int matrix[ROWS][COLS];
		int n, k, min_s, changed1;

		cout << "Введите количество строк и столбцов матрицы." << endl << endl;;
		cin >> n >> k;

		cout << endl << "Как заполнить матрицу? (1 - с клавиатуры, 2 - случайными числами)" << endl << endl;
		cin >> changed1;
		if (changed1 == 1)
		{
			cout << endl << "Введите элементы матрицы (числа от 0 до 9)." << endl << endl;
			matrix[ROWS][COLS] = in_matrix(matrix, n, k);
			cout << endl;
		}
		else if (changed1 == 2)
		{
			matrix[ROWS][COLS] = random_in(matrix, n, k);
			cout << endl;
		}
		else
		{
			cout << endl << "Ошибка ввода." << endl;
			return 0;
		}

		cout << "Введенная матрица имеет следующий вид:" << endl << endl;
		out_matrix(matrix, n, k);

		int n_matrix[ROWS][COLS];
		n_matrix[ROWS][COLS] = new_matrix(matrix, n_matrix, n, k);

		//ЕСЛИ ПОНАДОБИТСЯ ОБЪЯСНИТЬ РЕШЕНИЕ
		/*cout << endl << "Матрица сумм элементов имеет следующий вид:" << endl << endl;
		out_matrix(n_matrix, n, k);*/

		min_s = n_matrix[0][0];
		cout << endl << "Минимальная сумма чисел: " << min_s << endl << endl;

		char way_matrix[ROWS][COLS];
		way_matrix[ROWS][COLS] = way(way_matrix, matrix, n_matrix, n, k);

		cout << "Пройденный путь (обозначен *) имеет следующий вид:" << endl << endl;
		out_char_matrix(way_matrix, n, k);
	}
	else if (changed == 2)
	{
		int n, m, min_s, changed1;

		cout << "Введите количество строк и столбцов матрицы." << endl << endl;;
		cin >> n >> m;

		int** arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[m];
		}

		cout << endl << "Как заполнить матрицу? (1 - с клавиатуры, 2 - случайными числами)" << endl << endl;
		cin >> changed1;
		if (changed1 == 1)
		{
			cout << endl << "Введите элементы матрицы (числа от 0 до 9)." << endl << endl;
			arr = in_d_matrix(arr, n, m);
			cout << endl;
		}
		else if (changed1 == 2)
		{
			arr = random_d_in(arr, n, m);
			cout << endl;
		}
		else
		{
			cout << endl << "Ошибка ввода." << endl;
			return 0;
		}

		cout << "Введенная матрица имеет следующий вид:" << endl << endl;
		out_d_matrix(arr, n, m);

		int** n_matrix = new int* [n];
		for (int i = 0; i < n; i++)
		{
			n_matrix[i] = new int[m];
		}

		n_matrix = new_d_matrix(arr, n_matrix, n, m);

		min_s = n_matrix[0][0];
		cout << endl << "Минимальная сумма чисел: " << min_s << endl << endl;

		char** way_matrix = new char* [n + 1];
		for (int i = 0; i < n; i++)
		{
			way_matrix[i] = new char[m];
		}

		way_matrix = way_d(way_matrix, arr, n_matrix, n + 1, m);

		cout << "Пройденный путь (обозначен *) имеет следующий вид:" << endl << endl;
		out_char_d_matrix(way_matrix, n, m);

		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
			delete[] n_matrix[i];
			delete[] way_matrix[i];
		}
		delete[] arr;
		delete[] n_matrix;
		delete[] way_matrix;
	}
	else if (changed == 3)
	{
		int quantity;

		cout << "Введите количество точек на плоскости." << endl;
		cin >> quantity;

		if (quantity <= 0)
		{
			cout << "Данные введены неверно." << endl;
			return 0;
		}
		else if (quantity == 1)
		{
			cout << "Введите координаты (x, y) точки." << endl;
			vector<vector<int>> points = in_vector(quantity);
			cout << "Заданный вектор точек имеет вид:" << endl;
			out_vector(points);
			cout << endl;
			cout << "Координаты центра окружности: " << points[0][0] << " " << points[0][1] << endl;
			cout << "Длина радиуса: 0" << endl;
			return 0;
		}
		else if (quantity == 2)
		{
			cout << "Вводите координаты (x, y) точек." << endl;
			vector<vector<int>> points = in_vector(quantity);
			cout << "Заданный вектор точек имеет вид:" << endl;
			out_vector(points);
			cout << endl;
			vector<double> circle1;
			circle1.resize(3);
			circle1 = two_points_circle(points);
			cout << "Координаты центра окружности: " << circle1[0] << " " << circle1[1] << endl;
			cout << "Длина радиуса: " << circle1[2] << endl;
			return 0;
		}
		else
		{
			cout << "Вводите координаты (x, y) точек." << endl;
			vector<vector<int>> points = in_vector(quantity);
			cout << "Заданный вектор точек имеет вид:" << endl;
			out_vector(points);
			cout << endl;
			vector<double> circle1;
			vector<double> circle2;
			circle1.resize(3);
			circle2.resize(3);
			circle1 = two_points_circle(points);
			circle2 = three_points_circle(points);

			if (circle1[2] == 0 && circle2[2] != 0)
			{
				cout << "Координаты центра окружности: " << circle2[0] << " " << circle2[1] << endl;
				cout << "Длина радиуса: " << circle2[2] << endl;
			}
			else if (circle2[2] == 0 && circle1[2] != 0)
			{
				cout << "Координаты центра окружности: " << circle1[0] << " " << circle1[1] << endl;
				cout << "Длина радиуса: " << circle1[2] << endl;
			}
			else if (circle1[2] != 0 && circle2[2] != 0)
			{
				if (circle1[2] < circle2[2])
				{
					cout << "Координаты центра окружности: " << circle1[0] << " " << circle1[1] << endl;
					cout << "Длина радиуса: " << circle1[2] << endl;
				}
				else if (circle1[2] > circle2[2])
				{
					cout << "Координаты центра окружности: " << circle2[0] << " " << circle2[1] << endl;
					cout << "Длина радиуса: " << circle2[2] << endl;
				}
				else
				{
					cout << "Координаты центра окружности: " << circle2[0] << " " << circle2[1] << endl;
					cout << "Длина радиуса: " << circle2[2] << endl;
				}
			}
		}
	}
	else
	{
		cout << "Ошибка ввода!" << endl;
		return 0;
	}
}