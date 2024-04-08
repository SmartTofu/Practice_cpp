#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <iostream>
#include <chrono>

#define arr_size 20000
#define name_size 8
#define f_size 30

using namespace std;

struct reference
{
	int city_code;
	int tariff;
	char name[name_size];
};

struct searchrecord
{
	int key;
	int byte;
};

void array_generator(reference* arr, int size, int keys[arr_size])
{
	for (int i = 0; i < size; i++)
	{
		reference tmp;

		tmp.city_code = i;
		tmp.tariff = rand() % 1000 + 1;

		for (int j = 0; j < name_size - 1; j++)
		{
			tmp.name[j] = rand() % 25 + 65;
		}
		tmp.name[name_size - 1] = '\0';

		arr[i] = tmp;
	}
}

reference get_last_record(FILE* file, int size)
{
	fseek(file, (size - 1) * sizeof(reference), SEEK_SET);
	reference tmp;
	fread(&tmp, sizeof(reference), 1, file);
	return tmp;
}

reference linear_search(FILE* file, int size, int key)
{
	reference tmp;
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		fread(&tmp, sizeof(reference), 1, file);
		if (tmp.city_code == key) return tmp;
	}
}

void sort_table(searchrecord* table, int size)
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (table[j].key > table[j + 1].key)
			{
				swap(table[j], table[j + 1]);
			}
		}
	}
}

void table_out(searchrecord* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << table[i].key << " ";
	}
}

void create_search_table(searchrecord* table, int size, FILE* file)
{
	reference tmp;
	for (int i = 0; i < size; i++)
	{
		fread(&tmp, sizeof(reference), 1, file);
		table[i].key = tmp.city_code;
		table[i].byte = i * sizeof(reference);
	}
	sort_table(table, size);
}

void fibonacci_generator(int* arr, int size)
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < size; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int fibonacci_search(searchrecord* table, int size, int* fibonacci_arr, int key)
{
	int cnt, high = size - 1, low = 0, mid = 0;

	for (int i = 0; fibonacci_arr[i] - 1 < size; i++)
	{
		cnt = i;
		/*cout << fibonacci_arr[cnt] << " ";*/
	}

	while (low <= high)
	{
		mid = low + fibonacci_arr[cnt - 1] - 1;
		if (table[mid].key > key)
		{
			high = mid - 1;
			cnt -= 1;
		}
		else if (table[mid].key < key)
		{
			low = mid + 1;
			cnt -= 2;
		}
		else
		{
			if (mid <= high)
				return table[mid].byte;
			else
				return -1;
		}

	}
}

reference get_record(int position, FILE* file)
{
	fseek(file, position, SEEK_SET);
	reference tmp;
	fread(&tmp, sizeof(reference), 1, file);
	return tmp;
}

int main()
{
	setlocale(0, "Russian");
	srand(time(NULL));

	// EX. 1

	const char* file_name = "file.txt";
	reference* records = new reference[arr_size];
	int keys[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		keys[i] = i;
	}


	array_generator(records, arr_size, keys);

	FILE* records_file = fopen(file_name, "wb");
	fwrite(records, sizeof(reference), arr_size, records_file);
	fclose(records_file);


	// ПОДСЧЁТ КОЛИЧЕСТВА БАЙТ и ВЗЯТИЕ ПОСЛЕДНЕЙ ЗАПИСИ
	records_file = fopen(file_name, "rb");

	size_t bytes = 0;
	reference last_record = get_last_record(records_file, arr_size);
	if (records_file)
	{
		fseek(records_file, 0, SEEK_END);
		bytes = ftell(records_file);
	}

	cout << arr_size << " " << bytes << "    " << last_record.city_code << " " << last_record.tariff << " " << last_record.name << endl;


	// EX. 2
	
	int key;
	cout << endl << "Введите значение ключа" << endl;
	cin >> key;
	cout << endl;

	fseek(records_file, 0, SEEK_SET);

	auto start = std::chrono::steady_clock::now();
	last_record = linear_search(records_file, arr_size, key);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds1 = end - start;

	cout << "Найденная запись имеет следующий вид:" << endl;
	cout << last_record.city_code << " " << last_record.tariff << " " << last_record.name << endl << endl;
	cout << "Время линейного поиска: " << elapsed_seconds1.count() << endl;


	// EX. 3

	int key_2;
	cout << endl << "Введите значение ключа" << endl;
	cin >> key_2;
	cout << endl;

	searchrecord* table = new searchrecord[arr_size];
	fseek(records_file, 0, SEEK_SET);

	start = std::chrono::steady_clock::now();
	create_search_table(table, arr_size, records_file);
	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end - start;

	int* fibonacci_arr = new int[f_size];
	fibonacci_generator(fibonacci_arr, f_size);
	
	start = std::chrono::steady_clock::now();
	int position = fibonacci_search(table, arr_size, fibonacci_arr, key_2);
	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end - start;

	cout << "Позиция записи в байтах: ";
	cout << position << endl << endl;
	last_record = get_record(position, records_file);
	cout << "Искомая запись имеет следующий вид:" << endl;
	cout << last_record.city_code << " " << last_record.tariff << " " << last_record.name << endl << endl;

	cout << "Время создания таблицы ключ - позиция: " << elapsed_seconds2.count() << endl;
	cout << "Время поиска Фибоначчи: " << elapsed_seconds3.count() << endl;


	fclose(records_file);
}