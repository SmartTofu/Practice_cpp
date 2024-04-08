#pragma once

#include <iostream>
#include <stdlib.h>
#include "stdio.h"



using namespace std;

struct Product
{
	int vendor_code;
	char name[100] = {};
	int quantity;
	int price_for_one;
};

struct Table
{
	int size = 0;
	Product* content;

	void allocation()
	{
		content = new Product[size];
	}

	void output()
	{
		cout << "артикул  название  количество  цена" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << content[i].vendor_code << "    ";
			cout << content[i].name << "    ";
			cout << content[i].quantity << "    ";
			cout << content[i].price_for_one << endl;
		}
	}

	void order_list_output()
	{
		cout << "артикул  название  количество  цена" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "    " << content[i].vendor_code << "    ";
			cout << content[i].name << "    ";
			cout << content[i].quantity << "    ";
			cout << content[i].price_for_one << endl;
		}
	}
};

struct Order
{
	int number;
	char date[100] = {};
	char customer_surname[100] = {};
	char telephone_number[100] = {};
	Table product_list;
};

struct Table2
{
	int size = 0;
	Order* content;

	void allocation()
	{
		content = new Order[size];
	}
};

struct Supermarket
{
	Table2 order_list;
};

Order new_product(Order my_order)
{
	int chosen;
	cout << "Как запонить параметры нового товара?" << endl;
	cout << "1 - вручную" << endl;
	cout << "2 - автоматически" << endl << endl;
	cin >> chosen;
	cout << endl;

	if (chosen == 1)
	{
		my_order.product_list.size++;
		Product* tmp_content;
		tmp_content = new Product[my_order.product_list.size];
		for (int i = 0; i < my_order.product_list.size - 1; i++)
		{
			tmp_content[i] = my_order.product_list.content[i];
		}
		my_order.product_list.allocation();
		for (int i = 0; i < my_order.product_list.size; i++)
		{
			my_order.product_list.content[i] = tmp_content[i];
		}
		delete[] tmp_content;

		cout << endl << "Введите артикул нового товара" << endl;
		cin >> my_order.product_list.content[my_order.product_list.size - 1].vendor_code;
		cout << "Введите название нового товара" << endl;
		cin.ignore();
		gets_s(my_order.product_list.content[my_order.product_list.size - 1].name);
		cout << "Введите количество нового товара" << endl;
		cin >> my_order.product_list.content[my_order.product_list.size - 1].quantity;
		cout << "Введите цену нового товара" << endl;
		cin >> my_order.product_list.content[my_order.product_list.size - 1].price_for_one;
		return my_order;
	}
	else if (chosen == 2)
	{
		my_order.product_list.size++;
		Product* tmp_content;
		tmp_content = new Product[my_order.product_list.size];
		for (int i = 0; i < my_order.product_list.size - 1; i++)
		{
			tmp_content[i] = my_order.product_list.content[i];
		}
		my_order.product_list.allocation();
		for (int i = 0; i < my_order.product_list.size; i++)
		{
			my_order.product_list.content[i] = tmp_content[i];
		}
		delete[] tmp_content;

		my_order.product_list.content[my_order.product_list.size - 1].vendor_code = 1004;
		strcpy(my_order.product_list.content[my_order.product_list.size - 1].name, "Cabage");
		my_order.product_list.content[my_order.product_list.size - 1].quantity = 40;
		my_order.product_list.content[my_order.product_list.size - 1].price_for_one = 400;

		return my_order;
	}
	else
	{
		cout << "Ошибка ввода!" << endl;
	}
}

Supermarket new_order(Supermarket my_supermarket)
{
	int chosen;
	cout << "Как запонить параметры нового заказа?" << endl;
	cout << "1 - вручную" << endl;
	cout << "2 - автоматически" << endl << endl;
	cin >> chosen;
	cout << endl;

	if (chosen == 1)
	{
		my_supermarket.order_list.size++;
		Order* tmp_order;
		tmp_order = new Order[my_supermarket.order_list.size];
		for (int i = 0; i < my_supermarket.order_list.size - 1; i++)
		{
			tmp_order[i] = my_supermarket.order_list.content[i];
		}
		my_supermarket.order_list.allocation();
		for (int i = 0; i < my_supermarket.order_list.size; i++)
		{
			my_supermarket.order_list.content[i] = tmp_order[i];
		}
		delete[] tmp_order;

		cout << endl << "Введите номер нового заказа" << endl;
		cin >> my_supermarket.order_list.content[my_supermarket.order_list.size - 1].number;
		cout << "Введите дату совершения заказа" << endl;
		cin.ignore();
		gets_s(my_supermarket.order_list.content[my_supermarket.order_list.size - 1].date);
		cout << "Введите фамилию заказчика" << endl;
		gets_s(my_supermarket.order_list.content[my_supermarket.order_list.size - 1].customer_surname);
		cout << "Введите номер телефона заказчика" << endl;
		gets_s(my_supermarket.order_list.content[my_supermarket.order_list.size - 1].telephone_number);
		cout << "Сколько товаров будет в заказе?" << endl;

		int tmp_n;
		cin >> tmp_n;
		for (int i = 0; i < tmp_n; i++)
		{
			my_supermarket.order_list.content[my_supermarket.order_list.size - 1] = new_product(my_supermarket.order_list.content[my_supermarket.order_list.size - 1]);
		}

		return my_supermarket;
	}
	else if (chosen == 2)
	{
		my_supermarket.order_list.size++;
		Order* tmp_order;
		tmp_order = new Order[my_supermarket.order_list.size];
		for (int i = 0; i < my_supermarket.order_list.size - 1; i++)
		{
			tmp_order[i] = my_supermarket.order_list.content[i];
		}
		my_supermarket.order_list.allocation();
		for (int i = 0; i < my_supermarket.order_list.size; i++)
		{
			my_supermarket.order_list.content[i] = tmp_order[i];
		}
		delete[] tmp_order;

		my_supermarket.order_list.content[my_supermarket.order_list.size - 1].number = rand()%10 + 3;
		strcpy(my_supermarket.order_list.content[my_supermarket.order_list.size - 1].date, "12.05.2022");
		strcpy(my_supermarket.order_list.content[my_supermarket.order_list.size - 1].customer_surname, "Ivanov");
		strcpy(my_supermarket.order_list.content[my_supermarket.order_list.size - 1].telephone_number, "89997770506");
		cout << "Сколько товаров будет в заказе?" << endl << endl;

		int tmp_n;
		cin >> tmp_n;
		cout << endl;
		for (int i = 0; i < tmp_n; i++)
		{
			my_supermarket.order_list.content[my_supermarket.order_list.size - 1] = new_product(my_supermarket.order_list.content[my_supermarket.order_list.size - 1]);
		}

		return my_supermarket;
	}
	else
	{
		cout << "Ошибка ввода!" << endl;
	}
}

Supermarket delete_order(Supermarket my_supermarket, int num)
{
	int idx = 0;
	int flag = 0;
	for (int i = 0; i < my_supermarket.order_list.size; i++)
	{
		if (my_supermarket.order_list.content[i].number == num)
		{
			idx = i;
			flag = 1;
		}
	}

	if (flag == 0) { return my_supermarket; }

	Table2 tmp_order_list;
	tmp_order_list.size = my_supermarket.order_list.size - 1;
	tmp_order_list.allocation();

	int j = 0;
	for (int i = 0; i < my_supermarket.order_list.size; i++)
	{
		if (i != idx)
		{
			tmp_order_list.content[j] = my_supermarket.order_list.content[i];
			j++;
		}
	}

	my_supermarket.order_list.size--;
	my_supermarket.order_list.allocation();

	for (int i = 0; i < my_supermarket.order_list.size; i++)
	{
		my_supermarket.order_list.content[i] = tmp_order_list.content[i];
	}

	delete[] tmp_order_list.content;

	return my_supermarket;
}

int price_count(Supermarket my_supermarket, int num)
{
	int idx = 0, price = 0;

	for (int i = 0; i < my_supermarket.order_list.size; i++)
	{
		if (my_supermarket.order_list.content[i].number == num)
		{
			idx = i;
		}
	}

	for (int i = 0; i < my_supermarket.order_list.content[idx].product_list.size; i++)
	{
		price += (my_supermarket.order_list.content[idx].product_list.content[i].quantity) * (my_supermarket.order_list.content[idx].product_list.content[i].price_for_one);
	}

	return price;
}

void output(Supermarket my_supermarket)
{
	cout << "номер  дата  фамилия  телефон" << endl;
	for (int i = 0; i < my_supermarket.order_list.size; i++)
	{
		cout << my_supermarket.order_list.content[i].number << "    ";
		cout << my_supermarket.order_list.content[i].date << "    ";
		cout << my_supermarket.order_list.content[i].customer_surname << "    ";
		cout << my_supermarket.order_list.content[i].telephone_number << endl;
		cout << endl << "    Список товаров " << my_supermarket.order_list.content[i].number << " заказа" << endl << endl;
		cout << "    ";
		my_supermarket.order_list.content[i].product_list.order_list_output();
		cout << endl;
	}
}