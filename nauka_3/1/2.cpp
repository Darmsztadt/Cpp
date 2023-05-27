#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
const int n = 12;
char lab[n][n];
int tabRuchow[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int xStart, yStart, xKoniec, yKoniec;
bool czyKoniec = false;
void wczytajLabirynt()
{
    ifstream plik;
    plik.open("lab.txt");
    if (!plik)
    {
        cerr << "\n nie udalo sie otworzyc pliku...";
        system("pause");
    }
    else
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                plik >> lab[i][j];
                if (lab[i][j] == '0')
                    lab[i][j] = static_cast<char>(219);
                else
                    lab[i][j] = ' ';
            }
    }
    plik.close();
}
void rysujLabirynt()
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
            cout << lab[i][j];
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
void szukajWyjscia(int x, int y)
{
    int j = 0;  //licznik możliwych przemieszczeń z danego pola, j=1..4
    int xn, yn; //x,y -> współrzędne aktualnej pozycji, xn,yn -> nowe współrzędne
    do
    {
        xn = x + tabRuchow[j][0];
        yn = y + tabRuchow[j][1]; //nowa pozycja
        if (xn >= 0 && xn < n && yn >= 0 && yn < n && (lab[xn][yn] == ' ' || lab[xn][yn] == 'k'))
        {
            lab[xn][yn] = 'o'; //wstawienie znaku do tablicy
            gotoxy(xn + 2, yn + 2);
            cout << 'o';
            Sleep(500); // wyświetl. na ekranie
            if (xn == xKoniec && yn == yKoniec)
                czyKoniec = true;
            else
            {
                szukajWyjscia(xn, yn);
                if (!czyKoniec)
                {
                    lab[xn][yn] = '.'; //sprawdzone, nie tworzą drogi do wyjścia
                    {
                        gotoxy(xn + 2, yn + 2);
                        cout << '.';
                        Sleep(500);
                    }
                }
            }
        }
        //jeżeli poz. {xn,yn} niedostępna -> dzięki pętli sprad. pozostałe kier., j++
        //wywołanie dla pozycji {xn,yn} kończy definitywnie po zakończ. while -> j>4
    } while (czyKoniec == false && j++ < 3);
}
//koniec działania gdy jest przejście:
//czyKoniec = true, if(xn,yn==koniec) -> brak kolejnych wywołań szukania w else
//czyKoniec = true przerywa pętlę while -> nie sprawdzane inne przejścia z punktu przed wyjściem
//dokańczanie wcześniejszych wywołań bez akcji, break przerywa też pętle w wcześniejszch wywołań
int main()
{
    wczytajLabirynt();
    rysujLabirynt();
    cout << "\n\n podaj wsp. x startu (0-11): ";
    cin >> xStart;
    cout << "\n podaj wsp. y startu (0-11): ";
    cin >> yStart;
    lab[xStart][yStart] = 's';
    {
        gotoxy(xStart + 2, yStart + 2);
        cout << 's';
    };
    //+2, +2 -> uwzględnienie punktu początku labiryntu na ekranie ↑
    {
        gotoxy(18, 0);
    };
    cout << "\n podaj wsp. x wyjscia z lab. (0-11): ";
    cin >> xKoniec;
    cout << "\n podaj wsp. y wyjscia z lab. (0-11): ";
    cin >> yKoniec;
    lab[xKoniec][yKoniec] = 'k';
    {
        gotoxy(xKoniec + 2, yKoniec + 2);
        cout << 'k';
    };
    gotoxy(23, 0);
    system("pause");
    CONSOLE_CURSOR_INFO kursor;
    kursor.bVisible = false;
    kursor.dwSize = 100;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &kursor); //ukrycie kursora
    szukajWyjscia(xStart, yStart);                                  //pierwsze wywołanie, początek działania algorytmu
    gotoxy(25, 0);
    if (czyKoniec)
    {
        gotoxy(23, 0);
        cout << "\n\n wyznaczono droge przejscia! ";
    }
    else
    {
        gotoxy(20, 0);
        cout << "\n\n nie ma przejscia!!!";
    }
    cout << "\n\n";
}