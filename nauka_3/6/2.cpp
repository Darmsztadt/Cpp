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

void bubbleSort(int tab[], int size)
{
    int count = 0, empty = 0;

    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                swap(tab, j, j + 1);
                flag = true;
            }
            count++;
            printArray(tab, size);
        }
        if (!flag)
            // empty++;
            break;
        cout << " Licznik: " << count << " Puste przebiegi: " << empty << endl;
    }
}

int main()
{
    int size = 6;
    int tab[] = {11, 13, 8, 1, 15, 6};
    bubbleSort(tab, size);
}