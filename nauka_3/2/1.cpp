#include <iostream>
using namespace std;

struct element
{
    int id;
    string nazwa;
    element *nastepny;
    static int ilosc;
};
int element::ilosc = 0;

void dodaj(element *&wl)
{
    element *wn = new element;
    cout << "\nPodaj id: ";
    cin >> wn->id;
    cout << "Podaj nazwe: ";
    cin >> wn->nazwa;
    wn->ilosc++;
    wn->nastepny = wl;
    wl = wn;
    cout << "Adres do listy: " << wl << endl;
}

void usun(element *&wl)
{
    element *wn = new element;
    element *wt = new element;
    element *poprzedni = new element;
    int id;
    cout << "\nPodaj id do usuniecia: ";
    cin >> id;
    wn = wl;
    if (wl->id != id)
    {
        while (wl->id != id)
        {
            poprzedni = wl;
            wl = wl->nastepny;
        }
    }
    if (wl == nullptr)
    {
        delete wl;
        wl = wn;
        wl->ilosc--;
        while (wl != nullptr)
        {
            wl = wl->nastepny;
        }
        wl = nullptr;
    }
    else if (wl->ilosc==1)
    {
        wl->ilosc--;
        delete wl;
    }
    else
    {
        wt = wl->nastepny;
        delete wl;
        wl = wn;
        wl->ilosc--;
        while (wl != poprzedni)
        {
            wl = wl->nastepny;
        }
        wl->nastepny = wt;
    }
    wl = wn;
}

void wyswietl(element *wl)
{
    if (wl == nullptr)
        cout << endl
             << "lista pusta\n";
    else
    {
        cout << "\nilosc elementow: " << wl->ilosc << endl;
        while (wl != nullptr)
        {
            cout << "id: " << wl->id << " nazwa:  " << wl->nazwa << " nastepny: " << wl->nastepny << endl;
            wl = wl->nastepny;
        };
        cout << endl;
    };
}
int main()
{
    element *lista = nullptr;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nPodaj dane do elementu: ";
        dodaj(lista);
    }
    wyswietl(lista);
    while (lista->ilosc > 0)
    {
        usun(lista);
        wyswietl(lista);
    }
}