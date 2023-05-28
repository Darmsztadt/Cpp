#include <iostream>
using namespace std;

struct wezelAVL
{
    int klucz;
    int h;
    wezelAVL *lewe;
    wezelAVL *prawe;
    wezelAVL *rodzic;
}; // pojedynczy węzeł
// Procedura obliczania wysokości drzewa
int h = 0;
int wysokosc(wezelAVL *w)
{
    if (w != NULL)
    {
        int x = wysokosc(w->lewe);
        int y = wysokosc(w->prawe);
        if (x > y)
            h = x + 1;
        else
            h = y + 1;
    }
    else
        h = 0;
    return h;
}
// Procedura obrotu w lewo
wezelAVL *obrotLewo(wezelAVL *w)
{
    wezelAVL *wzr = w->prawe;
    wzr->rodzic = w->rodzic;
    w->rodzic = wzr;
    w->prawe = wzr->lewe;
    if (wzr->lewe != NULL)
        wzr->lewe->rodzic = wzr;
    wzr->lewe = w;
    w->h = max(wysokosc(w->lewe), wysokosc(w->prawe)) + 1;
    wzr->h = max(wysokosc(wzr->lewe), wysokosc(wzr->prawe)) + 1;
    return wzr;
}
// Procedura obrotu w prawo
wezelAVL *obrotPrawo(wezelAVL *w)
{
    wezelAVL *wzr = w->lewe;
    wzr->rodzic = w->rodzic;
    w->rodzic = wzr;
    w->lewe = wzr->prawe;
    if (wzr->prawe != NULL)
        wzr->prawe->rodzic = wzr;
    wzr->prawe = w;
    w->h = max(wysokosc(w->lewe), wysokosc(w->prawe)) + 1;
    wzr->h = max(wysokosc(wzr->lewe), wysokosc(wzr->prawe)) + 1;
    return wzr;
}
// Procedura równoważenia drzewa
void balans_AVL(wezelAVL *&w)
{
    int balans = wysokosc(w->lewe) - wysokosc(w->prawe);
    if (balans == 2) // lewe poddrzewo sprawdzanego węzła cięższe
    {
        int balansL = wysokosc(w->lewe->lewe) - wysokosc(w->lewe->prawe);
        if (balansL == -1)
        {
            w->lewe = obrotLewo(w->lewe);
            w = obrotPrawo(w);
        }
        else
            w = obrotPrawo(w); // bez dodatkowego obrotu
    }
    else if (balans == -2) // prawe poddrzewo sprawdzanego węzła cięższe
    {
        int balansP = wysokosc(w->prawe->lewe) - wysokosc(w->prawe->prawe);
        if (balansP == 1)
        {
            w->prawe = obrotPrawo(w->prawe);
            w = obrotLewo(w);
        }
        else
            w = obrotLewo(w); // bez dodatkowego obrotu
    }
    w->h = max(wysokosc(w->lewe), wysokosc(w->prawe)) + 1; // aktualizacja wysokości
}
// Procedura wstawiania węzłów
void insert_AVL(int x, wezelAVL *&w)
{
    if (w == NULL)
    {
        w = new wezelAVL;
        w->klucz = x;
        w->lewe = NULL;
        w->prawe = NULL;
        w->rodzic = NULL;
        w->h = 0;
    }
    else if (x < w->klucz)
    {
        insert_AVL(x, w->lewe);
        w->lewe->rodzic = w;
    }
    else
    {
        insert_AVL(x, w->prawe);
        w->prawe->rodzic = w;
    }
    balans_AVL(w);
    w->h = max(wysokosc(w->lewe), wysokosc(w->prawe)) + 1;
}
// Procedura wyświetlania drzewa AVL
// Procedura oparta jest na metodzie inorder, drzewo wyświetlane jest w układzie obróconym w lewo o 90 stopni,
// korzeń znajduje się po lewej stronie, każdy kolejny poziom wyświetlany jest ze zwiększonym wcięciem.
void wyswietl_drzewo(wezelAVL *w, int h = 0)
{
    if (w != NULL)
    {
        wyswietl_drzewo(w->prawe, h + 1);
        for (int i = 1; i <= h; i++)
            cout << "  "; // minimum 2 x spacja
        cout << w->klucz << "\n";
        wyswietl_drzewo(w->lewe, h + 1);
    }
}
// Procedura inicjowania wstawiania węzłów do drzewa
void built_AVL(wezelAVL *&w, int *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        insert_AVL(t[i], w);
        cout << "\n drzewo AVL, wstawiony elem.: " << t[i] << endl;
        wyswietl_drzewo(w);
    }
}

wezelAVL *wyszukaj(int x, wezelAVL *w)
{
    while (w != NULL && w->klucz != x)
    {
        cout << "\n wart wez:" << w->klucz;
        if (x < w->klucz)
            w = w->lewe;
        else
            w = w->prawe;
    }
    if (w != NULL && w->klucz == x)
    {
        cout << "\njest szukana wartosc! (" << x << ")";
        return w;
    }
    else
    {
        cout << "\n nie ma szukanej wartosci! (" << x << ")";
        return NULL;
    };
}

int main()
{
    int t[] = {8, 10, 5, 6, 1, 7, 3, 9, 4, 2}; // tablica elementów wstawianych do drzewa
    int n = 10;                                // liczba wstawianych elementów
    wezelAVL *drzewoAVL = nullptr;             // wskaźnik do drzewa
    built_AVL(drzewoAVL, t, n);                // budowa drzewa
    wyswietl_drzewo(drzewoAVL);                // wyświetlanie drzewa
    wezelAVL *drzewoSzukaj = wyszukaj(11, drzewoAVL);
    drzewoSzukaj = wyszukaj(4, drzewoAVL);
    drzewoSzukaj = wyszukaj(13, drzewoAVL);
    drzewoSzukaj = wyszukaj(22, drzewoAVL);
}