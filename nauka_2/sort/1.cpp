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

void insertionSort(int tablica[], int dlugosc)
{
    // w petli zakladamy, że element tablica[0] jest juz posortowany na poczatku
    for (int i = 1; i < dlugosc; i++)
    {
        int j = i;
        int element = tablica[j];
        while (j > 0 && tablica[j - 1] > element)
        {
            tablica[j] = tablica[j - 1];
            j--;
        }
        tablica[j] = element;
        printArray(tablica, dlugosc);
    }
}

int main()
{
    int size = 6;
    int tab[] = {11, 13, 8, 1, 15, 6};
    insertionSort(tab,size);
}