#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

const int n = 5;
int kon[n][n];
int tabRuchow[8][2] = {{1, 2}, {-1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};
int xStart, yStart;

void zbudujPlansze()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            kon[i][j] = 0;
    }
}

void rysujPlansze()
{
    system("cls");
    cout << "\n";
    cout << " ";
    for (int j = 0; j < n; j++)
        cout << j % 10;
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        cout << i % 10 << " ";
        for (int j = 0; j < n; j++)
        {
            cout << kon[i][j];
        }
    }
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = y; //c.X -> położenie w poziomie
    c.Y = x; //c.X -> położenie w pionie
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void szukajRuchu(int x, int y)
{
    int j = 1;  //licznik
    int xn, yn; //x,y -> współrzędne aktualnej pozycji, xn,yn -> nowe współrzędne
    do
    {
        xn = x + tabRuchow[j][0];
        yn = y + tabRuchow[j][1]; //nowa pozycja
        if (xn >= 0 && xn < n && yn >= 0 && yn < n && (kon[xn][yn] == 0))
        {
            kon[xn][yn] = 1; //wstawienie znaku do tablicy
            gotoxy(xn + 2, yn + 2);
            cout << 1;
            Sleep(100); // wyświetl. na ekranie
            if (j == 25)
                cout << "Koniec";
            else
            {
                szukajRuchu(xn, yn);
                if (j != 25)
                {
                    kon[xn][yn] = 0; //sprawdzone, nie tworzą drogi do wyjścia
                    {
                        gotoxy(xn + 2, yn + 2);
                        cout << 0;
                        Sleep(100);
                    }
                }
            }
        }
        //jeżeli poz. {xn,yn} niedostępna -> dzięki pętli sprad. pozostałe kier., j++
        //wywołanie dla pozycji {xn,yn} kończy definitywnie po zakończ. while -> j>4
    } while (j++ < 25);
}

int main()
{
    zbudujPlansze();
    rysujPlansze();
    cout << "\n\n podaj wsp. x startu (0-11): ";
    cin >> xStart;
    cout << "\n podaj wsp. y startu (0-11): ";
    cin >> yStart;
    kon[xStart][yStart] = 1;
    {
        gotoxy(xStart + 2, yStart + 2);
        cout << 1;
    };
    //+2, +2 -> uwzględnienie punktu początku labiryntu na ekranie ↑
    {
        gotoxy(18, 0);
    };
    gotoxy(23, 0);
    system("pause");
    CONSOLE_CURSOR_INFO kursor;
    kursor.bVisible = false;
    kursor.dwSize = 100;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &kursor); //ukrycie kursora
    szukajRuchu(xStart, yStart);                                    //pierwsze wywołanie, początek działania algorytmu
    gotoxy(25, 0);
    cout << "\n\n";
}