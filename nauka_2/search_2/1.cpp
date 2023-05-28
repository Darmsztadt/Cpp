#include <iostream>
using namespace std;

int szukajNaiwny(string wzorzec, string tekst)
{
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    while (i < N && j < M)
    {
        if (tekst[i] != wzorzec[j])
        {
            i = i - j;
            j = -1;
        }
        i++;
        j++;
    }
    if (j == M)
        return i - M;
    else
        return -1;
}

void printSzukanie(string s, int l, int p, int poziom)
{
    for (int i = 0; i < poziom; i++)
        cout << " ";
    cout << s.substr(l, p) << endl;
}

int szukajNaiwnyOpis(string wzorzec, string tekst)
{
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    while (i < N && j < M)
    {
        cout << "i=" << i << " j=" << j << endl;
        cout << tekst << endl;
        printSzukanie(wzorzec, 0, M, i - j);
        if (tekst[i] != wzorzec[j])
        {
            i = i - j;
            j = -1;
        }
        if (j != -1)
            cout << "Znak " << j << " wzorca zgodny ze znakiem " << i << " tekstu";
        else
            cout << "\nNiezgodnosc znakow";
        cout << endl
             << endl;
        i++;
        j++;
    }
    if (j == M)
        return i - M;
    else
        return -1;
}

int main()
{
    string txt = "AAAAAAAAAAAAAAAAAB", wz = "AAAB";
    int wynik = szukajNaiwnyOpis(wz, txt);
    if (wynik == -1)
        cout << "Nie znaleziono\n";
    else
        cout << "Indeks znalezionego wzorca: " << wynik << endl;
}