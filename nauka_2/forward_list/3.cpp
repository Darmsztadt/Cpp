#include <iostream>
#include <forward_list>
#include <math.h>
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
unsigned int obliczHash2(int klucz)
{
    return (klucz * (klucz + 3)) % Rmax;
}
unsigned int obliczHash3(int klucz)
{
    double c = (sqrt(5) - 1) / 2; // 1 mozliwosc wartosci stalej
    return floor((fmod(klucz * c, 1)) * Rmax);
}
unsigned int obliczHash4(int klucz)
{
    double c = (sqrt(5) - 1) / 2;
    c = 1 - c; // 2 mozliwosc wartosci stalej
    return floor((fmod(klucz * c, 1)) * Rmax);
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
void wstaw(forward_list<int> *tablica, int element, int &zderzenia)
{
    int pozycja = obliczHash1(element);
    if (!tablica[pozycja].empty())
        zderzenia++;
    tablica[pozycja].push_front(element);
}

void wstawPLin(int tablica[], int element, int &przesuniecia)
{
    int pozycja = obliczHash1(element);
    while (tablica[pozycja] != 0)
    {
        pozycja = pozycja % Rmax + 1;
        przesuniecia++;
    }
    tablica[pozycja] = element;
}

void wstaw2H(int tablica[], int element)
{
    int ix = obliczHash1(element);
    int ix1 = ix;
    int ix2 = obliczHash2(element);
    while (tablica[ix] != 0)
    {
        ix = ix % Rmax + ix2;
        if (ix == ix1)
            break;
    }
    while (tablica[ix] != 0)
    {
        ix = ix % Rmax + 1;
    }
    tablica[ix] = element;
}

int main()
{
    int pomocnicza[10] = {14, 15, 1, 7, 3, 13, 5, 10, 6, 19};
    int glowna[Rmax] = {0};
    int zderzenia1 = 0, zderzenia2 = 0;
    for (int i = 0; i < 10; i++)
    {
        // cout << pomocnicza[i] << " nadpisuje " << glowna[obliczHash1(pomocnicza[i])] << endl;
        if (glowna[obliczHash1(pomocnicza[i])] != 0)
            zderzenia1++;
        wstawZKolizja(glowna, pomocnicza[i]);
    }
    printArray(glowna, Rmax);
    cout << "Ilosc zderzen: " << zderzenia1 << endl;
    forward_list<int> *tablicaH2 = new forward_list<int>[Rmax];
    for (int i = 0; i < 10; i++)
    {

        wstaw(tablicaH2, pomocnicza[i], zderzenia2);
    }
    printArray(tablicaH2, Rmax);
    cout << "Liczba zderzen: " << zderzenia2 << endl;
    int plin[Rmax] = {0};
    int zderzenia3 = 0, przesuniecia = 0;
    for (int i = 0; i < 10; i++)
    {
        if (plin[obliczHash1(pomocnicza[i])] != 0)
            zderzenia3++;
        wstawPLin(plin, pomocnicza[i], przesuniecia);
    }
    printArray(plin, Rmax);
    cout << "Liczba zderzen: " << zderzenia3 << " \nPrzesuniecia: " << przesuniecia << endl;
    int dblhash[Rmax] = {0};
    int zderzenia4 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (glowna[obliczHash2(pomocnicza[i])] != 0)
            zderzenia4++;
        wstaw2H(dblhash, pomocnicza[i]);
    }
    printArray(dblhash, Rmax);
    cout << "Liczba zderzen: " << zderzenia4 << endl;
}