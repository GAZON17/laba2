#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

int flag = 1;
int A, B, C, X, Y;
float Z, U;
string resultX, resultY, resultU;

const int x = 61;
const int y = 17;

int mas[y][x] = { { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
                { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

void Error(int z)
{
    gotoxy(21,14);
    cout << "Ошибка ввода данных!";
    gotoxy(28, z);
    cout << "                         ";
}

void Interface3_1()
{
    system("cls");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (mas[i][j] == 1)
                cout << "-";
            else if (mas[i][j] == 0)
                cout << " ";
            else if (mas[i][j] == 2)
                cout << "|";
        }
        cout << endl;
    }
    gotoxy(26, 5);
    cout << "Программа";
    gotoxy(28, 6);
    cout << "'lab2'";
    gotoxy(23, 7);
    cout << "Беспалов Даниил";
    gotoxy(27, 8);
    cout << "Гр. 1092";
    gotoxy(18, 15);
    cout << "Esc – выход, ENTER - далее";
}

void Interface3_2()
{
    flag = 2;
    system("cls");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (mas[i][j] == 1)
                cout << "-";
            else if (mas[i][j] == 0)
                cout << " ";
            else if (mas[i][j] == 2)
                cout << "|";
        }
        cout << endl;
    }
    gotoxy(22, 4);
    cout << "Ввeдите переменные";
    gotoxy(26, 5);
    cout << "[-1000...1000]";
    gotoxy(26, 6);
    cout << "A: ";
    gotoxy(26, 7);
    cout << "B: ";
    gotoxy(26, 8);
    cout << "C: ";
    gotoxy(24, 15);
    cout << "ENTER - далее";
}

void Interface3_4()
{
    flag = 4;
    system("cls");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (mas[i][j] == 1)
                cout << "-";
            else if (mas[i][j] == 0)
                cout << " ";
            else if (mas[i][j] == 2)
                cout << "|";
        }
        cout << endl;
    }
    gotoxy(22, 2);
    cout << "Полученные значения";
    gotoxy(26, 3);
    cout << "A=";
    gotoxy(26, 4);
    cout << "B=";
    gotoxy(26, 5);
    cout << "C=";
    gotoxy(26, 6);
    cout << "X=";
    gotoxy(26, 7);
    cout << "Y=";
    gotoxy(26, 8);
    cout << "Z=";
    gotoxy(26, 9);
    cout << "U=";
    gotoxy(14, 15);
    cout << "Esc - повтор ввода, ENTER - далее";
}

void Interface3_5()
{
    flag = 5;
    system("cls");
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (mas[i][j] == 1)
                cout << "-";
            else if (mas[i][j] == 0)
                cout << " ";
            else if (mas[i][j] == 2)
                cout << "|";
        }
        cout << endl;
    }
    gotoxy(26, 6);
    cout << "Программа";
    gotoxy(28, 7);
    cout << "'lab2'";
    gotoxy(20, 8);
    cout << "Завершила свою работу";
    gotoxy(20, 15);
    cout << "Нажмите любую клавишу";
    gotoxy(1, 18);
}

void Input(int* a, int z)
{
    gotoxy(29, z);
    while (!(cin >> *a) || (cin.peek() != '\n') || (*a < -1000) || (*a > 1000))
    {
        cin.clear();
        while (cin.get() != '\n');
        Error(z);
        gotoxy(29, z);
    }
}

void XYZ()
{
    X = (max(max(A, B), C));
    Y = (min(min(A, B), C));
    Z = (float)(A + B + C) / 2;
}

void Oblast(int x, int y)
{
    int fl = 0;
    if (((x >= 0) && (x <= 2)) && ((y <= 1) && (y >= 0)))
    {
        resultX = "Переменная X принадлежит области D1";
        resultY = "Переменная Y принадлежит области D1";
        resultU = "Значение U определялось по формуле U=X*X+Y*Y";
        U = pow(X, 2) + pow(Y, 2);
        gotoxy(13, 10);
        cout << resultX;
        gotoxy(13, 11);
        cout << resultY;
        gotoxy(7, 12);
        cout << resultU;
        fl = 1;
    }
    if (((pow(x, 2) + pow(y + 1, 2)) <= 1) && (y <= -1))
    {
        resultX = "Переменная Х принадлежит области D2";
        resultY = "Переменная Y принадлежит области D2";
        resultU = "Значение U определялось по формуле U=X*Y*Z";
        if (X == 0 || Y == 0 || Z == 0)
        {
            U = 0;
        }
        else U = X * Y * Z;
        gotoxy(13, 10);
        cout << resultX;
        gotoxy(13, 11);
        cout << resultY;
        gotoxy(9, 12);
        cout << resultU;
        fl = 1;
    }
    if (fl==0)
    {
        resultX = "Переменная Х не принадлежит ни области D1, ни области D2";
        resultY = "Переменная Y не принадлежит ни области D1, ни области D2";
        resultU = "Значение U определялось по формуле U=Z";
        U = Z;
        gotoxy(3, 10);
        cout << resultX;
        gotoxy(3, 11);
        cout << resultY;
        gotoxy(11, 12);
        cout << resultU;
    }
}

void Output()
{
    gotoxy(29, 3);
    cout << A;
    gotoxy(29, 4);
    cout << B;
    gotoxy(29, 5);
    cout << C;
    gotoxy(29, 6);
    cout << X;
    gotoxy(29, 7);
    cout << Y;
    gotoxy(29, 8);
    cout << Z;
    gotoxy(29, 9);
    cout << U;
    gotoxy(47,15);
}

int main()
{
    setlocale(LC_ALL, "ru");
    char keys;
    do
    {
        if (flag == 1)
        {
            Interface3_1();
            do
            {
                keys = _getch();
                {
                    if (keys == 13)
                    {
                        Interface3_2();
                    }
                    if (keys == 27)
                    {
                        Interface3_5();
                    }
                }
            } while (flag == 1);
        }
        if (flag == 2)
        {
            Input(&A,6);
            Input(&B,7);
            Input(&C,8);
            XYZ();
            gotoxy(37, 15);
            do
            {
                keys = _getch();
                if (keys == 13)
                {
                    Interface3_4();
                }
            } while (flag == 2);
        }
        if (flag == 4)
        {
            Oblast(X, Y);
            Output();
            do
            {
                keys = _getch();
                if (keys == 13)
                {
                    Interface3_5();
                }
                if (keys == 27)
                {
                    Interface3_2();
                }
            } while (flag == 4);
        }
    } while (flag != 5);
}