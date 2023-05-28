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

void printSUParts(int tab[], int ix, int size)
{
    if (ix > 0)
        cout << "Czesc posortowana: " << tab[0];
    for (int i = 1; i < ix; i++)
    {
        cout << ", " << tab[i];
    }
    cout << " Czesc nieposortowana: ";
    for (int i = ix; i < size; i++)
    {
        cout << ", " << tab[i];
    }
    if (ix == size)
        cout << "NULL";
    cout << endl;
}

void insertionSort(int tablica[], int dlugosc)
{
    // w petli zakladamy, że element tablica[0] jest juz posortowany na poczatku
    for (int i = 1; i < dlugosc; i++)
    {
        int j = i;
        int transpose = 0;
        int element = tablica[j];
        while (j > 0 && tablica[j - 1] > element)
        {
            tablica[j] = tablica[j - 1];
            j--;
            transpose++;
        }
        tablica[j] = element;
        // printArray(tablica, dlugosc);
        // cout << " Traspozycje: "
        //      << transpose << endl;
        printSUParts(tablica, i, dlugosc);
    }
    printSUParts(tablica, dlugosc, dlugosc);
}

int main()
{
    int size1 = 6, size2 = 15;
    int tab1[] = {11, 13, 8, 1, 15, 6}, tab2[] = {5, 12, 3, 18, 15, 14}, tab3[] = {9, 20, 3, 11, 2, 16, 12, 18, 19, 13, 6, 8, 14, 7, 17};
    cout << "\nTablica 1:\n";
    insertionSort(tab1, size1);
    cout << "\nTablica 2:\n";
    insertionSort(tab2, size1);
    cout << "\nTablica 3:\n";
    insertionSort(tab3, size2);
}