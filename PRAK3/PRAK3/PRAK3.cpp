#include <iostream>
#include <string>

using namespace std;

void out_matrix(char* no_spaces, int* nums, int symbols)
{
	for (int i = 0; i < symbols - 1; i++)
	{
		cout << no_spaces[i] << " " << nums[i] << endl;
	}
}

char* bubble_sort(int c1, int c2, char* arr)
{
	for (int j = c1 + 1; j < c2; j++)
	{
		int f = 0;
		for (int i = c1; i < c2 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{ 
				swap(arr[i], arr[i + 1]);
				f = 1;
			}
		}
		if (f == 0) { break; }
	}
	return arr;
}

int space_counter(char* line, int len)
{
	int spaces = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] == ' ')
		{
			spaces += 1;
		}
	}
	return spaces;
}

int str_space_counter(string line, int len)
{
	int spaces = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] == ' ')
		{
			spaces += 1;
		}
	}
	return spaces;
}

void search(int* nums, char* no_spaces, char* no_spaces2, int words, int symbols)
{
	int count1 = 0, count2 = 0;
	int count3 = 0, count4 = 0, size1, size2;
	for (int i = 0; i < words - 1; i++)
	{
		count1 = count2;
		for (int j = 0; j < symbols; j++)
		{
			if (nums[j] == i) { count2 += 1; }
		}
		count3 = count2;
		count4 = count3;
		for (int x = i; x < words - 1; x++)
		{
			count3 = count4;
			for (int j = count3; j < symbols; j++)
			{
				if (nums[j] == x + 1) { count4 += 1; }
			}
			size1 = count2 - count1;
			size2 = count4 - count3;
			if (size1 != size2) { continue; }
			else
			{
				bool flag = true;
				int z = count3;
				for (int y = count1; y < count2; y++)
				{
					if (no_spaces2[y] != no_spaces2[z]) { flag = false; }
					z++;
				}
				if (flag == true)
				{
					for (int y = count1; y < count2; y++)
					{
						cout << no_spaces[y];
					}
					cout << " ";
					for (int y = count3; y < count4; y++)
					{
						cout << no_spaces[y];
					}
					cout << endl;
				}
			}
		}
	}
}

void str_search(int* nums, string no_spaces, string no_spaces2, int words, int symbols)
{
	int count1 = 0, count2 = 0;
	int count3 = 0, count4 = 0, size1, size2;
	for (int i = 0; i < words - 1; i++)
	{
		count1 = count2;
		for (int j = 0; j < symbols; j++)
		{
			if (nums[j] == i) { count2 += 1; }
		}
		count3 = count2;
		count4 = count3;
		for (int x = i; x < words - 1; x++)
		{
			count3 = count4;
			for (int j = count3; j < symbols; j++)
			{
				if (nums[j] == x + 1) { count4 += 1; }
			}
			size1 = count2 - count1;
			size2 = count4 - count3;
			if (size1 != size2) { continue; }
			else
			{
				bool flag = true;
				int z = count3;
				for (int y = count1; y < count2; y++)
				{
					if (no_spaces2[y] != no_spaces2[z]) { flag = false; }
					z++;
				}
				if (flag == true)
				{
					for (int y = count1; y < count2; y++)
					{
						cout << no_spaces[y];
					}
					cout << " ";
					for (int y = count3; y < count4; y++)
					{
						cout << no_spaces[y];
					}
					cout << endl;
				}
			}
		}
	}
}

int words_counter(char* line, int len)
{
	int j = 0, tmpwords = 0, words = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] != ' ' && line[i] != '\0')
		{
			tmpwords = 1;
			j++;
		}
		else if (line[i] != '\0')
		{
			words += tmpwords;
			tmpwords = 0;
		}
	}
	words += tmpwords;
	return words;
}

int str_words_counter(string line, int len)
{
	int j = 0, tmpwords = 0, words = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] != ' ' && line[i] != '\0')
		{
			tmpwords = 1;
			j++;
		}
		else if (line[i] != '\0')
		{
			words += tmpwords;
			tmpwords = 0;
		}
	}
	words += tmpwords;
	return words;
}

int* numbers_creator(char* line, int* nums, int len)
{
	int j = 0, tmpwords = 0, words = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] != ' ' && line[i] != '\0')
		{
			tmpwords = 1;
			if (line[i] != '\0') { nums[j] = words; }
			j++;
		}
		else if (line[i] != '\0')
		{
			words += tmpwords;
			tmpwords = 0;
		}
	}
	words += tmpwords;
	return nums;
}

int* str_numbers_creator(string line, int* nums, int len)
{
	int j = 0, tmpwords = 0, words = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] != ' ' && line[i] != '\0')
		{
			tmpwords = 1;
			if (line[i] != '\0') { nums[j] = words; }
			j++;
		}
		else if (line[i] != '\0')
		{
			words += tmpwords;
			tmpwords = 0;
		}
	}
	words += tmpwords;
	return nums;
}

char* no_spaces_creator(char* no_spaces, char* line, int len)
{
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] != ' ' && line[i] != '\0')
		{
			no_spaces[j] = line[i];
			j++;
		}
	}
	return no_spaces;
}

string str_no_spaces_creator(string no_spaces, string line, int len)
{
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (line[i] != ' ' && line[i] != '\0')
		{
			no_spaces[j] = line[i];
			j++;
		}
	}
	return no_spaces;
}

char* letters_sorting(int* nums, char* no_spaces, char* no_spaces2, int words, int symbols)
{
	int count1 = 0, count2 = 0;

	for (int i = 0; i < words; i++)
	{
		count1 = count2;

		for (int j = 0; j < symbols; j++)
		{
			if (nums[j] == i) { count2 += 1; }
		}

		char tmp[1000];
		int k = 0;
		for (int j = count1; j < count2; j++)
		{
			tmp[k] = no_spaces[j];
			k++;
		}

		bubble_sort(0, count2 - count1, tmp);

		k = 0;
		for (int j = count1; j < count2; j++)
		{
			no_spaces2[j] = tmp[k];
			k++;
		}
	}
	return no_spaces2;
}

string str_letters_sorting(int* nums, string no_spaces, string no_spaces2, int words, int symbols)
{
	int count1 = 0, count2 = 0;

	for (int i = 0; i < words; i++)
	{
		count1 = count2;

		for (int j = 0; j < symbols; j++)
		{
			if (nums[j] == i) { count2 += 1; }
		}

		char tmp[1000];
		int k = 0;
		for (int j = count1; j < count2; j++)
		{
			tmp[k] = no_spaces[j];
			k++;
		}

		bubble_sort(0, count2 - count1, tmp);

		k = 0;
		for (int j = count1; j < count2; j++)
		{
			no_spaces2[j] = tmp[k];
			k++;
		}
	}
	return no_spaces2;
}

int main()
{
	setlocale(0, "Russian");
	int chosen;

	cout << "Какую структуру данных использовать?" << endl;
	cout << "1 - нуль терминальная строка" << endl;
	cout << "2 - строка string STL" << endl << endl;
	cin >> chosen;
	cout << endl;

	if (chosen == 1)
	{
		int len;

		cout << "Cколько символов вы планируете вводить?" << endl << endl;
		cin >> len;
		cout << endl;

		len += 1;
		char* line = (char*)malloc(sizeof(char) * len);

		cout << "Введите текст" << endl << "(Можно вводить только латинские символы и цифры)" << endl << endl;
		cin.ignore();
		//cin.getline(line, len, '\n');
		gets_s(line, len);

		int spaces = space_counter(line, len);

		int symbols = len - spaces;
		char* no_spaces = (char*)malloc(sizeof(char) * symbols);
		char* no_spaces2 = (char*)malloc(sizeof(char) * symbols);
		int* nums = (int*)malloc(sizeof(int) * (symbols - 1));

		int words = words_counter(line, len);
		nums = numbers_creator(line, nums, len);
		no_spaces = no_spaces_creator(no_spaces, line, len);

		/*cout << endl;
		out_matrix(no_spaces, nums, symbols);*/

		no_spaces2 = letters_sorting(nums, no_spaces, no_spaces2, words, symbols);

		/*cout << endl;
		out_matrix(no_spaces, nums, symbols);
		cout << endl << endl;
		out_matrix(no_spaces2, nums, symbols);*/

		cout << endl << "Искомые слова: " << endl << endl;
		search(nums, no_spaces, no_spaces2, words, symbols);

		free(line);
		free(no_spaces);
		free(no_spaces2);
		free(nums);
	}
	else if (chosen == 2)
	{
		string line;

		cout << "Введите текст" << endl << "(Можно вводить только латинские символы и цифры)" << endl << endl;
		cin.ignore();
		getline(cin, line);

		int len = line.size();
		int spaces = str_space_counter(line, len);
		int symbols = len - spaces;
		
		string no_spaces, no_spaces2;
		no_spaces.resize(symbols);
		no_spaces2.resize(symbols);
		int* nums = (int*)malloc(sizeof(int) * symbols);

		int words = str_words_counter(line, len);
		nums = str_numbers_creator(line, nums, len);
		no_spaces = str_no_spaces_creator(no_spaces, line, len);

		no_spaces2 = str_letters_sorting(nums, no_spaces, no_spaces2, words, symbols);

		cout << endl << "Искомые слова: " << endl << endl;
		str_search(nums, no_spaces, no_spaces2, words, symbols);

		free(nums);
	}
	else
	{
		cout << "Ошибка ввода!" << endl;
		return 0;
	}
}