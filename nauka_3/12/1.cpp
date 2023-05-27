#include <iostream>

using namespace std;

void wypisz(int tab[], int p, int k) {
    for (int i = p; i <= k; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}
void wypisz(int tab[], int r) {
    for (int i = 0; i < r; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}
void sort_szybkie(int t[], int p, int k)
{
    int i, j, wtemp, pivot;
    i = p; j = k;
    pivot = t[i];
    while (i <= j)
    {
        while (t[i] < pivot) i++;
        while (t[j] > pivot) j--;
        if (i <= j) {
            wtemp = t[i]; t[i] = t[j]; t[j] = wtemp;
            i++; j--;
        }
    }
    wypisz(t, p, k);
    if (p < j) sort_szybkie(t, p, j);
    if (i < k) sort_szybkie(t, i, k);
}
void sort_wstaw(int t[], int r)
{
    int j, wtemp;
    for (int i = 1; i < r; i++)
    {
        j = i; wtemp = t[j];
        while (j > 0 && t[j - 1] > wtemp)
        {
            t[j] = t[j - 1];
            j--;
        }
        t[j] = wtemp;
        wypisz(t, r);
    }
}
void sort_bub(int t[], int r) {
    for (int i = 0; i < r-1; i++) {
        for (int j = 1; j < r - i; j++) {
            if (t[j] < t[j - 1]) swap(t[j], t[j - 1]);
        }
        wypisz(t, r);
    }
}


int main()
{
    setlocale(LC_CTYPE, "Polish");
    //int tab[] = { 5, 6, 7, 4, 1, 2, 3 };
    //int tab[] = { 7,9,2,4,1,5,8 };
    //int tab[] = { 4, 2, 1, 5, 6, 3, 7 };
    int tab[] = { 5, 6, 3, 2, 1, 4, 7 };
    int tab2[7], tab3[7];
    for (int i = 0; i < 7; i++) {
        tab2[i] = tab[i];
        tab3[i] = tab[i];
    }
    wypisz(tab, 7);
    cout << endl;
    cout << "Quicksort:" << endl;
    sort_szybkie(tab, 0, 6);
    wypisz(tab, 7);

    cout << endl;
    wypisz(tab2, 7);
    cout << endl;
    cout << "Wstawianie:" << endl;
    sort_wstaw(tab2, 7);

    cout << endl;
    wypisz(tab3, 7);
    cout << endl;
    cout << "B�belkowe:" << endl;
    sort_bub(tab3, 7);
}
