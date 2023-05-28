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

void swap(int tab[], int adr1, int adr2)
{
    int temp = tab[adr1];
    tab[adr1] = tab[adr2];
    tab[adr2] = temp;
}

int podzial(int tablica[], int lewy, int prawy)
{
    // wybor lewego skrajnego elementu jako osi
    int x = lewy;
    for (int i = lewy + 1; i <= prawy; i++)
    {
        if (tablica[i] < tablica[lewy])
        {
            x++;
            swap(tablica, x, i);
        }
    }
    swap(tablica, lewy, x);
    return x;
}

void quickSort(int tab[], int left, int right)
{
    if (left < right)
    {
        int os = podzial(tab, left, right);
        printArray(tab, 6);
        quickSort(tab, left, os - 1);
        quickSort(tab, os + 1, right);
    }
}

int main()
{
    int size = 6;
    int tab[] = {11, 13, 8, 1, 15, 6};
    quickSort(tab, 0, size - 1);
}