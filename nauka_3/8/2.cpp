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
void wstaw(forward_list<int> *tablica, int element, int &zderzenia)
{
    int pozycja = obliczHash1(element);
    if (!tablica[pozycja].empty())
        zderzenia++;
    tablica[pozycja].push_front(element);
}

int main()
{
    int pomocnicza[10] = {14, 15, 1, 7, 3, 13, 5, 10, 6, 19};
    forward_list<int> *tablicaH2 = new forward_list<int>[Rmax];
    int zderzenia = 0;
    for (int i = 0; i < 10; i++)
    {

        wstaw(tablicaH2, pomocnicza[i], zderzenia);
    }
    printArray(tablicaH2, Rmax);
    cout << "Liczba zderzen: " << zderzenia;
}