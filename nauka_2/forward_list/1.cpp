#include <iostream>
#include <forward_list>
using namespace std;

const int Rmax = 10;

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
unsigned int obliczHash1(int klucz)
{
    return klucz % Rmax;
}
void wstawZKolizja(int tablica[], int element)
{
    int pozycja = obliczHash1(element);
    tablica[pozycja] = element;
}

void printList(forward_list<int> &lista)
{
    for (auto el : lista)
    {
        cout << el << ", ";
    }
}
void printArray(forward_list<int> *tablica, int dlugosc)
{
    for (int i = 0; i < dlugosc; i++)
    {
        cout << "Poz. " << i << ": ";
        printList(tablica[i]);
        cout << endl;
    }
    cout << endl;
}
void wstaw(forward_list<int> *tablica, int element)
{
    int pozycja = obliczHash1(element);
    tablica[pozycja].push_front(element);
}

int main()
{
    int pomocnicza[10] = {14, 15, 1, 7, 3, 13, 5, 10, 6, 19};
    int glowna[Rmax] = {0};
    int zderzenia = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << pomocnicza[i] << " nadpisuje " << glowna[obliczHash1(pomocnicza[i])] << endl;
        if (glowna[obliczHash1(pomocnicza[i])] != 0)
            zderzenia++;
        wstawZKolizja(glowna, pomocnicza[i]);
    }
    printArray(glowna, Rmax);
    cout << "Ilosc zderzen: " << zderzenia << endl;
}