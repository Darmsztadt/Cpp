#include <iostream>
#include <forward_list>
#include <iterator>
#include <stack>
using namespace std;

struct element
{
    int id;
    string nazwa;
};

void wyswietl(forward_list<element> lista, string opis)
{
    cout << endl
         << opis;
    if (lista.empty())
    {
        cout << "\nLista pusta.";
        return;
    }

    cout << "\nLiczba elementow w liscie: " << distance(lista.begin(), lista.end());
    for (element e : lista)
    {
        cout << "\nid: " << e.id << " nazwa: " << e.nazwa;
    }
}

int main()
{
    // forward_list<element> lista;
    // wyswietl(lista, "Pusta lista ");
    // int idd;
    // cout << endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "Wpisz id: ";
    //     cin >> idd;
    //     lista.push_front({idd, "e" + to_string(idd)});
    // }
    // wyswietl(lista, "Lista po dodaniu 4 elementow: ");
    // cout << "\nPierwszy dostepny element to: " << lista.begin()->id << " " << lista.begin()->nazwa;
    // cout << "\nPierwszy dostepny element to: " << lista.front().id << " " << lista.front().nazwa;
    stack<element> stos;
    cout << "\nCzy pusty? " << boolalpha << stos.empty();
    for (int i = 1; i <= 5; i++)
    {
        stos.push({i, "s" + to_string(i)});
        cout << "\nDodano element...";
        cout << "\nTop: " << stos.top().id << " " << stos.top().nazwa << ", ilosc elementow: " << stos.size();
    }
    for (int i = 1; i <= 3; i++)
    {
        stos.pop();
        cout << "\nUsunieto element";
    }
    cout << "\nTop: " << stos.top().id << " " << stos.top().nazwa << ", ilosc elementow: " << stos.size();
}