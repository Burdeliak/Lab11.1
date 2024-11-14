#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname) // ��������� ����� � �������� �����
{
    ofstream fout(fname); // ������� ���� ��� ������
    char ch; // ������� ����������� � �� ������������ ��������
    string s; // �������� ������������ �����
    do
    {
        cin.get(); // ������� ����� ���������
        cin.sync();
        cout << "enter line: ";
        getline(cin, s); // ����� �����
        fout << s << endl; // �������� ���� � ����
        cout << "continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}

void PrintTXT(char* fname) // ��������� ����� �� �����
{
    ifstream fin(fname); // ������� ���� ��� ����������
    string s; // ���������� �����
    while (getline(fin, s)) // ���� ����� ��������� �����
    {
        cout << s << endl; // �������� ���� �� �����
    }
    cout << endl;
}

// ������� ��� ��������� �������� ���� 'a', 'b', 'c' � ����
int CountABC(char* fname)
{
    ifstream fin(fname); // ������� ���� ��� ����������
    string s; // ���������� �����
    int count = 0; // �������� ��� ���� 'a', 'b', 'c'
    while (getline(fin, s)) // ���� ����� ��������� �����
    {
        for (char ch : s) // ��������� �� ������� ������� � �����
        {
            if (ch == 'a' || ch == 'b' || ch == 'c') // ����������, �� � ������ 'a', 'b' ��� 'c'
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    char fname[100]; // ��'� �����
    cout << "enter file name 1: ";
    cin >> fname;

    // ��������� �� �������� ���� ������� �����
    CreateTXT(fname); // ����� ����� ����� � ���������
    PrintTXT(fname); // ������ ���� ������� ����� �� �����

    // ϳ�������� �������� ���� 'a', 'b', 'c'
    int abcCount = CountABC(fname);
    cout << "'a', 'b', 'c': " << abcCount << endl;

    return 0;
}
