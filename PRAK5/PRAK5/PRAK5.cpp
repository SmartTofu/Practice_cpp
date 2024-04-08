#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
	int key = 0;
	Node* ptr = nullptr;
};

void node_insertion(Node* flag, Node* node)
{
	node->ptr = flag->ptr;
	flag->ptr = node;
}

Node* node_search(Node* node, int idx)
{
	if (idx == 0) { return node; }
	else { return node_search(node->ptr, idx - 1); }
}

Node* list_generator(int n)
{
	Node* tmp_list = new Node;
	tmp_list->key = rand() % 1000 + 1;
	for (int i = 0; i < n; i++)
	{
		Node* tmp_node = new Node;
		tmp_node->key = rand() % 1000 + 1;
		node_insertion(tmp_list, tmp_node);
	}
	return tmp_list;
}

Node** array_generator(int n)
{
	Node** arr = new Node*[n];

	for (int i = 0; i < n; i++)
	{
		Node* tmp_list = new Node;
		tmp_list = list_generator(n);
		arr[i] = tmp_list;
	}

	return arr;
}

void list_out(Node* list, int n)
{
	int cnt = 0;
	while (node_search(list, cnt) != nullptr)
	{
		cout << node_search(list, cnt)->key << " ";
		cnt++;
	}
}

void array_out(Node** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		list_out(arr[i], n);
		cout << endl;
	}
}

bool key_search(Node* list, int n, int key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (node_search(list, i) != nullptr)
		{
			if (node_search(list, i)->key == key) { flag = true; }
		}
	}
	return flag;
}

int position_search(Node* list, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (node_search(list, i)->key == key) { return i; }
	}
}

Node* delete_node(Node* list, int pos, int n)
{
	if (pos == 0)
	{
		Node* new_list = list->ptr;
		delete list;
		return new_list;
	}
	node_search(list, pos - 1)->ptr = node_search(list, pos + 1);
	list = node_search(list, 0);
	delete node_search(list, n-1);
	return list;
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

int main()
{
	setlocale(0, "Russian");
	srand(time(0));

	int n = rand() % 5 + 3; // Инициализация переменной n (размера массива и списков) случайным целочисленныйм значением
	int n1 = n;
	Node** peaks = array_generator(n); // Инициализация массива указателей на вершины списков

	cout << "Сгенерированные значения ключей списков: " << endl;
	cout << "(C новой строки выводятся значения ключей нового списка)" << endl << endl;
	array_out(peaks, n);

	while (1)
	{
		int chosen;
		cout << endl << "Выберите действе:" << endl << endl;
		cout << "1 - вставить значение ключа в список" << endl;
		cout << "2 - удалить значение ключа из списка" << endl;
		cout << "3 - найти узел с введённым значением ключа" << endl;
		cout << "4 - завершить работу программы" << endl << endl;
		cin >> chosen;
		cout << endl;

		if (chosen == 1)
		{
			int key;
			cout << "Введите значение ключа, которое нужно добавить в один из списков" << endl << endl;
			cout << "Номер списка рассчитывается по формуле:" << endl;
			cout << "idx = key % n" << endl << endl;
			cin >> key;
			cout << endl;

			int idx = key % n;
			cout << "Значение будет вставлено в " << idx << " список" << endl << endl;

			cout << "Введите, после какого узла вставить новый" << endl << endl;
			int pos;
			cin >> pos;
			if (pos > n + 1)
			{
				cout << endl << "Вставка невозможна" << endl;
				continue;
			}
			cout << endl;

			Node* tmp_node = new Node;
			tmp_node->key = key;
			Node* flag_node = node_search(peaks[idx], pos);
			node_insertion(flag_node, tmp_node);
			/*n += 1;*/

			cout << "Изменённый список имеет вид:" << endl << endl;
			list_out(peaks[idx], n);
			cout << endl;
		}
		if (chosen == 2)
		{
			int idx, key;
			cout << "Введите номер списка, узел которого надо удалить" << endl << endl;
			cin >> idx;
			cout << endl;
			if (idx > n1 || idx < 0)
			{
				cout << "Нет списка с таким номером" << endl;
				continue;
			}
			cout << "Введите значение ключа" << endl << endl;
			cin >> key;
			cout << endl;

			bool flag = key_search(peaks[idx], list_size(peaks[idx]), key);
			if (flag == false)
			{
				cout << "Нет ключа с таким значением" << endl;
				continue;
			}

			int pos = position_search(peaks[idx], list_size(peaks[idx]), key);
			peaks[idx] = delete_node(peaks[idx], pos, list_size(peaks[idx]));
			n--;
			list_out(peaks[idx], n);
		}
		if (chosen == 3)
		{
			int idx, key;
			cout << "Введите номер списка, где надо вести поиск" << endl << endl;
			cin >> idx;
			cout << endl;
			if (idx > n || idx < 0)
			{
				cout << "Нет списка с таким номером" << endl;
				continue;
			}
			cout << "Введите значение ключа" << endl << endl;
			cin >> key;
			cout << endl;

			bool flag = key_search(peaks[idx], list_size(peaks[idx]) + 1, key);
			if (flag == false)
			{
				cout << "Нет ключа с таким значением" << endl;
				continue;
			}

			int pos = position_search(peaks[idx], list_size(peaks[idx]) + 1, key);
			cout << "Указатель на узел с заданным ключём имеет вид:" << endl;
			cout << node_search(peaks[idx], pos) << endl;

		}
		if (chosen == 4)
		{
			break;
		}
	}
}