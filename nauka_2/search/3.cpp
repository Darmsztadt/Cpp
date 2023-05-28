#include <iostream>
using namespace std;

void printArray(int tablica[], int dlugosc)
{
    if (dlugosc > 0)
        cout << tablica[0];
    for (int i = 1; i < dlugosc; i++)
    {
        cout << ", " << tablica[i];
    }
    cout << endl;
}
int linearSearch(int tablica[], int dlugosc, int x)
{
    for (int i = 0; i < dlugosc; i++)
    {
        if (x == tablica[i])
            return i;
    }
    return -1;
}

int binarySearchITER(int tablica[], int dlugosc, int x)
{
    int lewy = 0, prawy = dlugosc - 1;
    int srodek = 0;
    bool znaleziono = false;
    while (lewy <= prawy && znaleziono == false)
    {
        srodek = (lewy + prawy) / 2;
        if (x == tablica[srodek])
            znaleziono = true;
        else if (x > tablica[srodek])
            lewy = srodek + 1;
        else
            prawy = srodek - 1;
    }
    if (znaleziono)
        return srodek;
    else
        return -1;
}

int binarySearchITERrec(int tablica[], int left, int right, int x)
{
    if (left > right)
        return -1;
    int srodek = 0;
    if (left <= right)
    {
        srodek = (left + right) / 2;
        if (x == tablica[srodek])
            return srodek;
        else if (x > tablica[srodek])
            srodek = binarySearchITERrec(tablica, srodek + 1, right, x);
        else
            srodek = binarySearchITERrec(tablica, left, srodek - 1, x);
    }
    return srodek;
}

int main()
{
    int size = 6;
    int tab[] = {5, 7, 9, 11, 14, 16};
    int find[] = {0, 5, 11, 16};
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << binarySearchITERrec(tab, 0, size - 1, find[i]) << " ";
    }
}