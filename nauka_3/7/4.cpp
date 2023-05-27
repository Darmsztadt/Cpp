#include <iostream>
using namespace std;

void zamien(int tablica[], int a, int b)
{
    int temp = tablica[a];
    tablica[a] = tablica[b];
    tablica[b] = temp;
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
            zamien(tablica, x, i);
        }
    }
    zamien(tablica, lewy, x);
    return x;
}
void quickSort(int tablica[], int lewy, int prawy)
{
    if (lewy < prawy)
    {
        int os = podzial(tablica, lewy, prawy);

        quickSort(tablica, lewy, os - 1);
        quickSort(tablica, os + 1, prawy);
    }
}

int hoare(int tab[], int left, int right, int k)
{
    if (left == right)
        return tab[left];
    int os = podzial(tab, left, right);
    if (k == os)
        return tab[k];
    else if (k < os)
        hoare(tab, left, os - 1, k);
    else
        hoare(tab, os + 1, right, k);
    return tab[k];
}

int main()
{
    // int size = 6;
    // int tab[] = {1, 10, 13, 12, 9, 18};
    // quickSort(tab, 0, size - 1);
    // int tab[] = {9, 14, 5, 4, 13, 12};
    int size = 12;
    int tab[] = {6, 15, 2, 14, 11, 10, 5, 20, 4, 17, 1, 8};
    // cout << endl
    //      << hoare(tab, 0, size - 1, 0) << " " << hoare(tab, 0, size - 1, 3) << " " << hoare(tab, 0, size - 1, 5);
    cout << endl
         << hoare(tab, 0, size - 1, 1) << " " << hoare(tab, 0, size - 1, 2) << " " << hoare(tab, 0, size - 1, size - 2);
}