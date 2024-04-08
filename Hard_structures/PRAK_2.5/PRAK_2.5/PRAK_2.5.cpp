#include <iostream>
#include <vector>

using namespace std;


void dijcstraSearch(vector<vector<int>> GR, int st, int c) {

	int count, index, i, u, m = st + 1;		// Объявление используемых сущностей

	vector<int> distance;
	vector<bool> visited;

	for (i = 0; i < c; i++) {				// Предварительное заполнение векторов
		distance.push_back(INT_MAX);
		visited.push_back(false);
	}

	distance[st] = 0;

	for (count = 0; count < c - 1; count++) {  // Поиск минимальных путей из текущей вершины
		int min = INT_MAX;

		for (i = 0; i < c; i++)
			if (!visited[i] && distance[i] <= min) {
				min = distance[i]; index = i;
			}

		u = index;
		visited[u] = true;

		for (i = 0; i < c; i++)				// Присваивание меток с длинами путей от заданой вершины
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}

											// Вывод полученных значений
	cout << "Длины путей из начальной вершины до остальных:" << endl;
	for (i = 0; i < c; i++)
		if (distance[i] != INT_MAX)
			cout << m << " -> " << i + 1 << " = " << distance[i] << endl;
		else cout << m << " -> " << i + 1 << " = " << "маршрут недоступен" << endl;
}



int main() {
	setlocale(0, "Russian");
	int chosen;

	cout << "Выберите режим работы программы: " << endl;
	cout << "1 - поиск кратчайшего пути в заданом графе" << endl;
	cout << "2 - поиск кратчайшего пути в произвольном графе" << endl << endl;
	cin >> chosen;

	if (chosen == 1)
	{
		int start;
		vector<vector<int>> GR = { // Инициализаци графа
		{0, 3, 4, 2, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 6, 0, 0, 0, 0},
		{0, 0, 0, 0, 5, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 6, 0, 12, 0},
		{0, 0, 0, 0, 1, 0, 8, 7, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
		{0, 0, 0, 0, 0, 0, 0, 6, 0, 11},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		};

		cout << "Введите номер начальной вершины: ";
		cin >> start;			  // Ввод начальной вершины

		dijcstraSearch(GR, start - 1, 10);  // Запуск алгоритма Дейкстры
	}
	else if (chosen == 2)
	{
		int start, count;
		cout << "Введите количество вершин графа" << endl;
		cin >> count;

		vector<vector<int>> GR;		// Обхявление графа как двумерного вектора
		for (int i = 0; i < count; i++)   // Заполнение пользователем матрицы смежности
		{
			vector<int> row;
			for (int j = 0; j < count; j++) // Заполнение данных одной строки
			{
				if (i == j) row.push_back(0); // Путь из вершины в саму себя равен нулю
				else if (i == count - 1) row.push_back(0); // Из последней вершины нет путей
				else
				{
					cout << "Введите длину ребра между " << i + 1 << " вершиной и " << j + 1 << " вершиной:" << endl;
					int tmp;
					cin >> tmp;
					row.push_back(tmp);
				}
			}
			GR.push_back(row);
		}

		cout << endl << "Введите номер начальной вершины: ";
		cin >> start;

		dijcstraSearch(GR, start - 1, count); // Запуск алгоритма Дейкстры
	}

	return 0;
}