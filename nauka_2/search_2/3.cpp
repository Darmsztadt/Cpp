#include <iostream>
using namespace std;

void obliczPrzesunieciaKMP(int tablica[], string wzorzec, int M)
{
    int i = 0, j = 0;
    tablica[0] = -1;
    for (i = 0, j = -1; i < M; i++, j++)
    {
        tablica[i] = j;
        while (j >= 0 && wzorzec[i] != wzorzec[j])
            j = tablica[j];
    }
}

void printSzukanie(string s, int l, int p, int poziom)
{
    for (int i = 0; i < poziom; i++)
        cout << " ";
    cout << s.substr(l, p) << endl;
}

int szukajKMP(string wzorzec, string tekst)
{
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    int *przesun = new int[M];
    obliczPrzesunieciaKMP(przesun, wzorzec, M);
    for (int k = 0; k < M; k++)
        cout << przesun[k] << " ";
    for (i = 0, j = 0; i < N && j < M; i++, j++)
    {
        cout << "\n Wartosc i: " << i << ", wartosc j: " << j;
        while (j >= 0 && tekst[i] != wzorzec[j])
        {
            j = przesun[j];
        }
        cout << endl
             << tekst << endl;
        printSzukanie(wzorzec, 0, M, i - j);
        for (int k = 0; k <= j; k++)
            cout << wzorzec[k];
        cout << endl;
        for (int t = i - j; t <= i; t++)
            cout << tekst[t];
        cout << endl;
    }
    delete[] przesun;
    if (j == M)
        return i - M;
    else
        return -1;
}

int main()
{
    string txt = "AAAAAAAAAAAAAAAAAB", wz = "AAAB";
    int wynik = szukajKMP(wz, txt);
    if (wynik == -1)
        cout << "\nNie znaleziono\n";
    else
        cout << "\nIndeks znalezionego wzorca: " << wynik << endl;
}