#include <iostream>
using namespace std;

struct wezel
{
    int klucz;
    wezel *lewe;
    wezel *prawe;
};
wezel *drzewo = NULL;

void insertBST(int x, wezel *&w)
{
    if (w == NULL)
    {
        w = new wezel;
        w->klucz = x;
        w->lewe = NULL;
        w->prawe = NULL;
    }
    else if (x < w->klucz)
    {
        insertBST(x, w->lewe);
    }
    else
        insertBST(x, w->prawe);
}

void buildBST(int n, wezel *&w)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nWpisz wartosc: ";
        int x;
        cin >> x;
        insertBST(x, w);
    }
}

void wyswietlBST(wezel *w, int h = 0)
{
    if (w != NULL)
    {
        wyswietlBST(w->prawe, h + 1);
        for (int i = 0; i < h; i++)
        {
            cout << "  ";
        }
        cout << w->klucz << endl;
        wyswietlBST(w->lewe, h + 1);
    }
}

void sprawdz(int x, wezel *w)
{
    wezel *temp = w;
    do
    {
        if (x < temp->klucz)
        {
            temp = temp->lewe;
        }
        else if (x > temp->klucz)
        {
            temp = temp->prawe;
        }
        else if (temp != NULL && temp->klucz == x)
        {
            cout << "\nZnaleziono element. Adres: " << temp;
            break;
        }
        if (temp == NULL)
        {
            cout << "\nNie znaleziono elementu. Adres: " << temp;
        }
    } while (temp != NULL);
}

int najwiekszy(wezel *w)
{
    int naj = 0;
    while (w != NULL)
    {
        naj = w->klucz;
        najwiekszy(w->prawe);
    };
    return naj;
}

int main()
{
    cout << "\nPodaj ilosc wprowadzanych wezlow: ";
    int n;
    cin >> n;
    buildBST(n, drzewo);
    wyswietlBST(drzewo);
    // char cont;
    // do
    // {
    //     cont = 'n';
    //     cout << "\nWprowadz klucz szukany: ";
    //     cin >> n;
    //     sprawdz(n, drzewo);
    //     cout << "\nKontynuowac? ";
    //     cin >> cont;
    // } while (cont == 't');
    cout << "\nNajwiekszy klucz to: " << najwiekszy(drzewo);
}