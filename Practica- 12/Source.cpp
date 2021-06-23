#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <stdio.h.>
#include <cstdlib>

using namespace std;

double sum(double* a, double* b)// Для задания №1, функция для поиска суммы двух чисел
{
    double result = *a + *b;
    return result;
}

double mini(double* a, double* b)// Для задания №1, функция для вычитания двух чисел
{
    double result = *a - *b;
    return result;
}

double umn(double* a, double* b)// Для задания №1, функция для умножения двух чисел
{
    double result = *a * *b;
    return result;
}

double del(double* a, double* b)// Для задания №1, функция для деления двух чисел
{
    double result = *a / *b;
    return result;

}

void zamena(string& s, char h = ' ', char u = '\t')
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == h) {
            s[i] = u;
        }
    }
}

void fun(double* dig, double* dig1, double dig12[2], int n,int n1)// Для задания №2
{
    double sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + dig[i];
    }
    dig12[0] = sum;
   
    for (int i = 0; i < n1; i++)
    {
        sum1 = sum1 + dig1[i];
    }
    dig12[1] = sum1;

    cout << "Массив c суммами двух массивов  >>> { ";
    for (int i = 0; i < 2; i++)
    {
        cout << dig12[i] << ", ";
    }
    cout << "}\n";
}

int eng(string& str, int i = 0, int  d = 0, int l = 0)
{
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            d++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) l++;
        i++;
    }
    cout << "\nЧисел - " << d << endl;
    cout << "Английских букв - " << l << endl;
    i = i - d - l;
    return i;
}

int rus(string& str)
{
    int r;
    char vowels[20] = { 'а', 'у', 'о', 'ы', 'и', 'э', 'я', 'ю', 'ё', 'е', 'А', 'У', 'О', 'Ы', 'И', 'Э', 'Я', 'Ю', 'Ё', 'Е' };
    char consonants[42] = { 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'Б', 'В', 'Г', 'Д', 'Ж', 'З', 'Й', 'К', 'Л', 'М', 'Н', 'П', 'Р', 'С', 'Т', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ' };
    int vowels_quantity = 0, consonants_quantity = 0;
    for (int f = 0; f <= (int)str.size(); f++) {
        for (int v = 0; v <= 19; v++)
            if (str[f] == vowels[v]) vowels_quantity += 1;

        for (int c = 0; c <= 41; c++)
            if (str[f] == consonants[c]) consonants_quantity += 1;
    }
    r = consonants_quantity + vowels_quantity;
    cout << "Гласных русских букв: " << vowels_quantity;
    cout << "\nСогласных русских букв: " << consonants_quantity;
    return r;
}

bool check_polindrom(string word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; ++i)
    {
        if (word[i] != word[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

void a1()//№1 Калькулятор без условий if, switch
{
    setlocale(LC_ALL, "rus");
    int i; 
    double a, b, result;

    for (int k = 0;; k++)
    {
        cout << "Калькулятор без условий if, switch" << endl;
        cout << "1 - сумма, 2 - вычитание, 3 - умножение, 4 - деление, 0 - выход" << endl;
        cin >> i;

        if (i != 0)
        {
            i--;
            cout << "Введите первое число: " << endl; cin >> a;
            cout << "Введите второе число: " << endl; cin >> b;
           
            if (i < 4)
            {
                double(*Arr[4])(double*, double*) = { sum, mini, umn, del };
                double(*ptFunc)(double*, double*) = Arr[i];
                result = ptFunc(&a, &b);
                cout << "Результат:  " << result << endl << endl;
                i++;
            }
            else
            {
                cout << "Error: 404\n" << endl;
                Beep(523, 500);
                Beep(523, 500);
                Beep(523, 500);
            }
        }
        else
        {
            cout << "Exit:" << endl;
            break;
        }
    }
}

void a2()// Задание №2, улучшенное, сделал динамические массивы, вместо статических.
{
    int n,n1; double dig12[2];
    cout << "Введите размер 1 массива: ";
    cin >> n;
    cout << "Введите размер 2 массива: ";
    cin >> n1;
    double* dig = new  double[n];
    double* dig1 = new  double[n1];
    cout << "Массив №1  >>> { ";
    for (int i = 0; i < n; i++) 
    {
        dig[i] = rand() % 101 - 50;
        cout << dig[i] << ", ";
    }
    cout << "}\n";
    cout << "Массив №2  >>> { ";
    for (int f = 0; f < n1; f++)
    {
        dig1[f] = rand() % 101 - 50;
        cout << dig1[f] << ", ";
    }
    cout << "}\n";

    fun(dig, dig1, dig12, n, n1);

}

void a3()// Задание №3 заменяет пробелы на табуляцию
{
    string s; 
    cout << "Введите строку: ";
    cin.ignore();
    getline(cin, s);
    cin.ignore();
    zamena(s);
    cout << "Измененная строка >>> " << s << "\n";
}

void a4()// Задание №4 счет чисел, букв и т.д.
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str; int r, i, s;
    cout << "Введите строку: ";
    cin.ignore();
    getline(cin, str);
    cin.ignore();
    s = eng(str) - rus(str);
    cout << "\nДругого - " << s << endl;
}

void a5()// Задание №5 подсчет слов
{
    int counter = 0;
    cout << "Введите предложение: ";
    string st;
    cin.ignore();
    getline(cin, st);
    cin.ignore();

    for (int i = 1; i < st.size(); i++)
    {
        if (st[i - 1] != ' ' && (st[i] == ' ' || st[i + 1] == '\0')) counter++;
    }

    cout << "Количество слов в данном предложении " << counter << endl;
}

void a6()// Задание №6 Палиндром
{
    string str;
    cout << "Введите слово: ";
    cin >> str;
    if (check_polindrom(str))
    {
        cout << "Слово палиндром.\n";
    }
    else
    {
        cout << "Слово не палиндром.\n";
    }
}

void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int f;
    do {
        cout << "\n1 - 6  >>> "; cin >> f;
        switch (f)
        {
        case 1:
            a1();
            break;
        case 2:
            a2();
            break;
        case 3:
            a3();
            break;
        case 4:
            a4();
            break;
        case 5:
            a5();
            break;
        case 6:
            a6();
            break;
    } while (f != 0);
}