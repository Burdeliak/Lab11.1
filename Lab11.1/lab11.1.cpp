#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname) // створення файлу з введених рядків
{
    ofstream fout(fname); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    string s; // введений користувачем рядок
    do
    {
        cin.get(); // очищуємо буфер клавіатури
        cin.sync();
        cout << "enter line: ";
        getline(cin, s); // ввели рядок
        fout << s << endl; // записали його у файл
        cout << "continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}

void PrintTXT(char* fname) // виведення файлу на екран
{
    ifstream fin(fname); // відкрили файл для зчитування
    string s; // прочитаний рядок
    while (getline(fin, s)) // поки можна прочитати рядок
    {
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
}

// Функція для підрахунку входжень літер 'a', 'b', 'c' у файлі
int CountABC(char* fname)
{
    ifstream fin(fname); // відкрили файл для зчитування
    string s; // прочитаний рядок
    int count = 0; // лічильник для букв 'a', 'b', 'c'
    while (getline(fin, s)) // поки можна прочитати рядок
    {
        for (char ch : s) // проходимо по кожному символу в рядку
        {
            if (ch == 'a' || ch == 'b' || ch == 'c') // перевіряємо, чи є символ 'a', 'b' або 'c'
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    char fname[100]; // ім'я файлу
    cout << "enter file name 1: ";
    cin >> fname;

    // Створюємо та виводимо вміст першого файлу
    CreateTXT(fname); // ввели рядки файлу з клавіатури
    PrintTXT(fname); // вивели вміст першого файлу на екран

    // Підрахунок входжень букв 'a', 'b', 'c'
    int abcCount = CountABC(fname);
    cout << "'a', 'b', 'c': " << abcCount << endl;

    return 0;
}
