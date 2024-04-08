#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#define test_size 500000

#include <iostream>
#include <string>
#include <regex>


using namespace std;

void suffix_first(int* shift, int* pos, string pattern, int m)
{
    int i = m, j = m + 1;
    pos[i] = j;

    while (i > 0)
    {
        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = pos[j];
        }
        i--;
        j--;
        pos[i] = j;
    }
}

void bad_symbol(int* shift, int* pos, int m)
{
    int i, j;
    j = pos[0];
    for (i = 0; i <= m; i++)
    {
        if (shift[i] == 0)
            shift[i] = j;
        if (i == j)
            j = pos[j];
    }
}

int search(string text, string pattern, long long& C)
{
    int s = 0, j;
    int m = pattern.length();
    int n = text.length();

    int* pos = new int[m + 1];
    int* shift = new int[m + 1];

    for (int i = 0; i < m + 1; i++) shift[i] = 0;

    suffix_first(shift, pos, pattern, m);
    bad_symbol(shift, pos, m);

    while (s <= n - m)
    {
        j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
            C++;
        }

        if (j < 0)
        {
            return s;
            s += shift[0];
        }
        else
            s += shift[j + 1];
    }

    return -1;
}

int main()
{
	setlocale(0, "Russian");

    while (1)
    {
        int chosen;
        cout << "Выберите, какое упражнение продемонстрировать:" << endl;
        cout << "1 - поиск строки в тексте по алгоритму Бойера-Мура" << endl;
        cout << "2 - замена подряд идущих гласных, при помощи регулярных выражений" << endl;
        cout << "3 - завершение работы программы" << endl << endl;
        cin >> chosen;
        cout << endl;

        if (chosen == 1)
        {
            long long C1 = 0;
            string text, word;
            char ch_text[test_size];
            cout << "Программа работает с текстом размера " << test_size << " символов" << endl;

            const char* file_name = "file.txt";
            FILE* records_file = fopen(file_name, "r");
            fseek(records_file, 0, SEEK_SET);
            fread(&ch_text, sizeof(char), test_size, records_file);
            text = string(ch_text);

            //cout << "Введите тескт:" << endl << endl;
            cin.clear();
            cin.ignore();
            //getline(cin, text);
            cout << endl << "Введите искомое слово" << endl << endl;
            getline(cin, word);
            cout << endl;

            // Подсчет количества вхождений искомого слова
            int cnt = 0;
            while (true)
            {
                if (search(text, word, C1) == -1) break;
                cnt++;
                text = text.substr(search(text, word, C1) + word.length(), text.length() - search(text, word, C1));
            }
            cout << "Искомое слово встречается в тексте " << cnt << " раз" << endl;
            cout << "Количество проведённых сравнений: " << C1 << endl << endl;
        }
        else if (chosen == 2)
        {
            regex exep(R"((E|U|I|O|A|Y|e|u|i|o|a|y)\1{1,}(\1))");
            string str;
            string replace(R"(_$2)");
            cout << "Введите текст" << endl;
            cin.clear();
            cin.ignore();
            getline(cin, str);
            cout << endl;
            str = regex_replace(str, exep, replace);
            cout << "После замены символов строка имеет следующий вид:" << endl;
            cout << str << endl << endl;;

        }
        else if (chosen == 3)
        {
            break;
        }
    }
}