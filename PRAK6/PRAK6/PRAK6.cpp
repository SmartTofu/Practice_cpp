#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int key = 0;
    Node* ptr = nullptr;
};

Node* node_search(Node* node, int idx)
{
	if (idx == 0) { return node; }
	else { return node_search(node->ptr, idx - 1); }
}

void node_insertion(Node* flag, Node* node)
{
	node->ptr = flag->ptr;
	flag->ptr = node;
}

Node* list_generator(int n)
{
	Node* tmp_list = new Node;
	tmp_list->key = rand() % 1000 + 1;
	for (int i = 0; i < n - 1; i++)
	{
		Node* tmp_node = new Node;
		tmp_node->key = rand() % 1000 + 1;
		node_insertion(tmp_list, tmp_node);
	}
	return tmp_list;
}

void list_out(Node* list)
{
	int cnt = 0;
	while (node_search(list, cnt) != nullptr)
	{
		cout << node_search(list, cnt)->key << " ";
		cnt++;
	}
}

int list_size(Node* list)
{
	int cnt = 0;
	while (node_search(list, cnt) != nullptr)
	{
		cnt += 1;
	}
	return cnt;
}

int delete_list(Node* list, int size)
{
	if (size > 1)
	{
		delete node_search(list, size - 1);
		node_search(list, size - 2)->ptr = nullptr;
		size--;
		// Выводы для наглядности
		list_out(list);
		cout << endl;
	}
	else if (size == 1)
	{
		delete node_search(list, size - 1);
		size--;
		// Выводы для наглядности
		cout << endl;
		cout << "Список успешно удалён" << endl << endl;
	}

	if (size == 0) { return 0; }
	else { return delete_list(list, size); }
}

void create_towers(int towers[8][3])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			towers[i][j] = 0;
		}
	}
}

void create_first_tower(int towers[8][3])
{
	int cnt = 1;
	for (int i = 0; i < 8; i++)
	{
		towers[i][0] = cnt;
		cnt++;
	}
}

void towers_out(int arr[8][3])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void towers_out(int tower1[8], int tower2[8], int tower3[8])
{
	for (int i = 0; i < 8; i++)
	{
		cout << tower1[i] << " " << tower2[i] << " " << tower3[i] << endl;
	}
}

int last_disk(int arr[8][3], int n)
{
	for (int i = 0; i < 8; i++)
	{
		if (arr[i][n] != 0) { return arr[i][n]; }
	}
	return arr[7][n];
}

int last_disk_adress(int arr[8][3], int n)
{
	for (int i = 0; i < 8; i++)
	{
		if (arr[i][n] != 0) { return i; }
	}
	return 7;
}

void iter_towers(int towers[8][3])
{
	int cnt = 0;
	while (towers[0][2] != 1)
	{
		// Перенос с первого колышка на второй или наоборот
		if (last_disk(towers, 1) == 0)
		{
			towers[7][1] = last_disk(towers, 0);
			towers[last_disk_adress(towers, 0)][0] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 1) > last_disk(towers, 0) && last_disk(towers, 0) != 0)
		{
			towers[last_disk_adress(towers, 1) - 1][1] = last_disk(towers, 0);
			towers[last_disk_adress(towers, 0)][0] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 1) < last_disk(towers, 0))
		{
			towers[last_disk_adress(towers, 0) - 1][0] = last_disk(towers, 1);
			towers[last_disk_adress(towers, 1)][1] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 1) > last_disk(towers, 0) && last_disk(towers, 0) == 0)
		{
			towers[7][0] = last_disk(towers, 1);
			towers[last_disk_adress(towers, 1)][1] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}

		// Перенос с первого колышка на третий или наоборот
		if (last_disk(towers, 2) == 0)
		{
			towers[7][2] = last_disk(towers, 0);
			towers[last_disk_adress(towers, 0)][0] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 2) > last_disk(towers, 0))
		{
			towers[last_disk_adress(towers, 2) - 1][2] = last_disk(towers, 0);
			towers[last_disk_adress(towers, 0)][0] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 2) < last_disk(towers, 0))
		{
			towers[last_disk_adress(towers, 0) - 1][0] = last_disk(towers, 2);
			towers[last_disk_adress(towers, 2)][2] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}

		// Перенос со второго колышка на третий или наоборот
		if (last_disk(towers, 2) == 0)
		{
			towers[7][2] = last_disk(towers, 1);
			towers[last_disk_adress(towers, 1)][1] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 1) == 0)
		{
			towers[7][1] = last_disk(towers, 2);
			towers[last_disk_adress(towers, 2)][2] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 2) > last_disk(towers, 1))
		{
			towers[last_disk_adress(towers, 2) - 1][2] = last_disk(towers, 1);
			towers[last_disk_adress(towers, 1)][1] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
		else if (last_disk(towers, 2) < last_disk(towers, 1))
		{
			towers[last_disk_adress(towers, 1) - 1][1] = last_disk(towers, 2);
			towers[last_disk_adress(towers, 2)][2] = 0;
			towers_out(towers);
			cout << endl;
			cnt++;
		}
	}
	cout << "Количество действий: " << cnt << endl;
}

int tower_size(int tower[8])
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		if (tower[i] != 0) { cnt++; }
	}
	return cnt;
}

int last_disk(int tower[8])
{
	for (int i = 0; i < 8; i++)
	{
		if (tower[i] != 0) { return tower[i]; }
	}
	return tower[7];
}

int last_disk_adress(int tower[8])
{
	for (int i = 0; i < 8; i++)
	{
		if (tower[i] != 0) { return i; }
	}
	return 7;
}

void recur_towers(int tower1[8], int tower2[8], int tower3[8], int n)
{
	if (n == 1)
	{
		if (last_disk(tower3) == 0)
		{
			tower3[7] = last_disk(tower1);
			tower1[last_disk_adress(tower1)] = 0;
			towers_out(tower1, tower2, tower3);
			cout << endl;
		}
		else
		{
			tower3[last_disk_adress(tower3) - 1] = last_disk(tower1);
			tower1[last_disk_adress(tower1)] = 0;
			towers_out(tower1, tower2, tower3);
			cout << endl;
		}
	}
	else
	{
		//cout << "Поворот по часовой стрелке" << endl << endl;
		recur_towers(tower1, tower3, tower2, n - 1); // 1 3 2

		if (last_disk(tower3) == 0)
		{
			tower3[7] = last_disk(tower1);
			tower1[last_disk_adress(tower1)] = 0;
			towers_out(tower1, tower3, tower2);
			cout << endl;
		}
		else
		{
			tower3[last_disk_adress(tower3) - 1] = last_disk(tower1);
			tower1[last_disk_adress(tower1)] = 0;
			towers_out(tower1, tower3, tower2);
			cout << endl;
		}

		//cout << "Поворот против часовой стрелки" << endl << endl;
		recur_towers(tower2, tower1, tower3, n - 1); // 2 1 3
	}

}

int main()
{
    setlocale(0, "Russian");

	int chosen;

	cout << "Работу какого алгоритма продемонстрировать?" << endl << endl;
	cout << "1 - итерационый алгоритм решения задачи про Ханойские башни" << endl;
	cout << "2 - рекурсивный алгоритм решения задачи про Ханойские башни" << endl;
	cout << "3 - рекурсивный алгоритм удаления однонаправленного списка" << endl << endl;

	cin >> chosen;
	cout << endl;

	if (chosen == 1)
	{
		int towers[8][3];
		create_towers(towers);
		create_first_tower(towers);
		towers_out(towers);
		cout << endl;
		iter_towers(towers);
	}
	else if (chosen == 2)
	{
		int tower1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		int tower2[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		int tower3[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		recur_towers(tower1, tower2, tower3, tower_size(tower1));
	}
	else if (chosen == 3)
	{
		srand(time(0));

		int n = rand() % 10 + 5;
		Node* list = list_generator(n);

		cout << "Случайным образом был сгенерирован список:" << endl << endl;
		list_out(list);

		cout << endl << endl << "Рекурсивное удаление списка:" << endl << endl;
		delete_list(list, n);
	}
}