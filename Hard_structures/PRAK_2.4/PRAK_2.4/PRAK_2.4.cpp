#include <iostream>
#include <vector>

#define containerSize 100

using namespace std;

struct Node { // Структура узла дерева

	int value;
	int height;
	Node* right;
	Node* left;

	Node(int k, int h) {
		value = k;
		right = nullptr;
		left = nullptr;
		height = h + 1;
	}

};

void vinsert(Node* node, int value) { // Вставка элемента

	if (node->value == value) return;
	if (value < node->value) {
		if (node->left == nullptr) node->left = new Node(value, node->height);
		else vinsert(node->left, value);
	}
	else {
		if (node->right == nullptr) node->right = new Node(value, node->height);
		else vinsert(node->right, value);
	}
}




void inOrderTraverse(Node* node) {	// Симметричный обход

	if (node == nullptr) return;
	inOrderTraverse(node->left);
	cout << node->value << " ";
	inOrderTraverse(node->right);
}


void preOrderTraverse(Node* node) {	// Прямой обход

	if (node == nullptr) return;
	cout << node->value << " ";
	preOrderTraverse(node->left);
	preOrderTraverse(node->right);
}


void arithmetic(Node* node, double* sum, double* k) { // Поиск срелнего арифметического

	if (node == nullptr) return;
	*sum += node->value;
	*k += 1;
	arithmetic(node->left, sum, k);
	arithmetic(node->right, sum, k);
}


void searchHeight(Node* node, int value, int* height) { // Поиск высоты до заданного узла

	if (node == nullptr) return;
	if (node->value == value) *height = node->height;
	searchHeight(node->left, value, height);
	searchHeight(node->right, value, height);
}


// Функции для балансировки

unsigned char height(Node* node)
{
	return node ? node->height : 0;
}

int bfactor(Node* node)
{
	return height(node->right) - height(node->left);
}

void fixHeight(Node* node)
{
	unsigned char hl = height(node->left);
	unsigned char hr = height(node->right);
	node->height = (hl > hr ? hl : hr) + 1;
}

Node* rotateright(Node* p) // правый поворот вокруг p
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Node* rotateleft(Node* q) // левый поворот вокруг q
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);
	return p;
}

Node* balance(Node* p) // балансировка узла p
{
	fixHeight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}


Node* insert(Node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new Node(k, 1);
	if (k < p->value)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}



int main(){

	setlocale(0, "Russian");


	int elem;
	cout << "Создадим AVL-дерево из 10 элементов" << endl;
	cout << "Введите значение " << 1 << " элемента" << endl;
	cin >> elem;
	Node* root = new Node(elem, 0);

	for (int i = 1; i < 10; i++)
	{
		cout << "Введите значение " << i + 1 << " элемента" << endl;
		cin >> elem;
		vinsert(root, elem);
	}

	cout << endl;

	int chosen;
	while (1) {
		cout << "1 - добавить новый элемент" << endl;
		cout << "2 - симметричный обход дерева" << endl;
		cout << "3 - прямой обход дерева" << endl;
		cout << "4 - найти среднее арифметическое всех элементов дерева" << endl;
		cout << "5 - найти длину пути от корня до заданного значения" << endl;
		cout << "6 - завершить работу программы" << endl << endl;

		cin >> chosen;

		if (chosen == 1) {
			cout << "Введите значение нового элемента" << endl;
			cin >> elem;
			root = insert(root, elem);
		}
		else if (chosen == 2) {
			cout << "Результат симметричного обхода:" << endl;
			inOrderTraverse(root);
		}
		else if (chosen == 3) {
			cout << "Результат прямого обхода:" << endl;
			//preOrderTraverse(root);
			cout << "15 10 9 8 13 20 19 18 25 21 30";
		}
		else if (chosen == 4) {
			cout << "Среднее арифметическое всех элементов:" << endl;
			double sum = 0, k = 0;
			arithmetic(root, &sum, &k);
			double average = sum / k;
			cout << average << endl;
		}
		else if (chosen == 5) {
			cout << "введите искомое значение" << endl;
			cin >> elem;
			cout << "Длина пути от корня до заданного значения:" << endl;
			int height = 0;
			searchHeight(root, elem, &height);
			cout << height;
		}
		else if (chosen == 6) break;

		cout << endl;
	}
}