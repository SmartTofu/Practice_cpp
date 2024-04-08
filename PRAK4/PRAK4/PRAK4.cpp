#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif


#include "supermarket.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "Russian");
	Product first_product;
	first_product.vendor_code = 1001;
	strcpy(first_product.name, "Tomato");
	first_product.quantity = 10;
	first_product.price_for_one = 100;

	Product second_product;
	second_product.vendor_code = 1002;
	strcpy(second_product.name, "Apple");
	second_product.quantity = 20;
	second_product.price_for_one = 200;

	Product third_product;
	third_product.vendor_code = 1003;
	strcpy(third_product.name, "Lemon");
	third_product.quantity = 30;
	third_product.price_for_one = 300;

	Product fourth_product;
	fourth_product.vendor_code = 1004;
	strcpy(fourth_product.name, "Cabage");
	fourth_product.quantity = 40;
	fourth_product.price_for_one = 400;

	Order first_order;
	first_order.product_list.size = 4;
	first_order.product_list.allocation();
	first_order.product_list.content[0] = first_product;
	first_order.product_list.content[1] = second_product;
	first_order.product_list.content[2] = first_product;
	first_order.product_list.content[3] = third_product;
	first_order.number = 1;
	strcpy(first_order.date, "10.12.2022");
	strcpy(first_order.customer_surname, "Lenin");
	strcpy(first_order.telephone_number, "81234567890");

	Order second_order;
	second_order.product_list.size = 4;
	second_order.product_list.allocation();
	second_order.product_list.content[0] = first_product;
	second_order.product_list.content[1] = fourth_product;
	second_order.product_list.content[2] = third_product;
	second_order.product_list.content[3] = third_product;
	second_order.number = 2;
	strcpy(second_order.date, "11.01.2023");
	strcpy(second_order.customer_surname, "Lenin");
	strcpy(second_order.telephone_number, "81234567890");



	int chosen;
	cout << "Использовать набор тестовых данных или заполнить таблицу вручную?" << endl;
	cout << "1 - тестовые данные" << endl;
	cout << "2 - заполнить вручную" << endl << endl;
	cin >> chosen;
	cout << endl;

	Supermarket orders;

	if (chosen == 1)
	{
		orders.order_list.size = 2;
		orders.order_list.allocation();
		orders.order_list.content[0] = first_order;
		orders.order_list.content[1] = second_order;
		output(orders);
	}
	else if (chosen == 2)
	{
		int quantity_orders;
		cout << "Сколько заказов будет в таблице?" << endl << endl;
		cin >> quantity_orders;
		cout << endl;

		for (int i = 0; i < quantity_orders; i++)
		{
			orders = new_order(orders);
		}

		output(orders);
	}
	else
	{
		cout << "Ошибка ввода!";
		return 0;
	}

	while (1)
	{
		int flag;
		cout << "Выбирете действие" << endl;
		cout << "1 - добавить новый заказ" << endl;
		cout << "2 - добавить новый товар" << endl;
		cout << "3 - удалить заказ" << endl;
		cout << "4 - посчитать цену заказа" << endl;
		cout << "5 - завершить работу программы" << endl << endl;
		cin >> flag;
		cout << endl;

		if (flag == 1)
		{ 
			orders = new_order(orders); 
			output(orders);
		}
		else if (flag == 2)
		{ 
			int num;
			cout << "В какой заказ добавить товар?" << endl << endl;
			cin >> num;
			cout << endl;

			int idx = 0;
			for (int i = 0; i < orders.order_list.size; i++)
			{
				if (orders.order_list.content[i].number == num)
				{
					idx = i;
				}
			}
			
			orders.order_list.content[idx] = new_product(orders.order_list.content[idx]);
			output(orders);
		}
		else if (flag == 3)
		{ 
			int num;
			cout << "Введите номер заказа, который надо удалить" << endl << endl;
			cin >> num;
			cout << endl;
			orders = delete_order(orders, num);
			output(orders);
		}
		else if (flag == 4)
		{ 
			int num;
			cout << "Цену какого заказа нужно посчитать?" << endl << endl;
			cin >> num;
			cout << endl;
			cout << "Цена заказа:" << endl;
			cout << price_count(orders, num) << endl << endl;
		}
		else if (flag == 5) { break; }
		else { cout << "Ошибка ввода!" << endl; }
	}
}