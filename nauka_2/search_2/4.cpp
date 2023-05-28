#include <iostream>
using namespace std;

const int K = 26 * 2 + 1;

int indeks(char c)
{
    switch (c)
    {
    case ' ':
        return 0;
    default:
        if (islower(c))
            return c - 'a' + 1;
        else
            return c - 'A' + 27;
    }
}

void printSzukanie(string s, int l, int p, int poziom)
{
    for (int i = 0; i < poziom; i++)
        cout << " ";
    cout << s.substr(l, p) << endl;
}

void obliczPrzesunieciaBM(int tablica[], string wzorzec, int M)
{
    for (int i = 0; i < K; i++)
        tablica[i] = M;
    for (int i = 0; i < M; i++)
        tablica[indeks(wzorzec[i])] = M - i - 1;
}

int szukajBM(string wzorzec, string tekst)
{
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    int przesun[K];
    obliczPrzesunieciaBM(przesun, wzorzec, M);
    for (int i = 0; i < K; i++)
        cout << przesun[i] << " ";
    for (i = M - 1, j = M - 1; j > 0; i--, j--)
    {
        cout << "\nWartosc i: " << i << ", wartosc j: " << j;
        while (tekst[i] != wzorzec[j])
        {
            cout << "\nWewnatrz while, wartosc i: " << i << ", wartosc j: " << j;
            cout << endl
                 << tekst << endl;
            printSzukanie(wzorzec, 0, M, i - j);
            int x = przesun[indeks(tekst[i])];
            if (M - j > x)
            {
                i = i + M - j;
            }
            else
            {
                i = i + x;
            }
            if (i >= N)
                return -1;
            j = M - 1;
        }
    }
    cout << endl
         << tekst << endl;
    printSzukanie(wzorzec, 0, M, i - j);
    cout << "\nCaly wzorzec zgodny";
    return i;
}

int main()
{
    string txt = "GCAATGCCTATGTG", wz = "TATGTG";
    int wynik = szukajBM(wz, txt);
    if (wynik == -1)
        cout << "\nNie znaleziono\n";
    else
        cout << "\nIndeks znalezionego wzorca: " << wynik << endl;
}