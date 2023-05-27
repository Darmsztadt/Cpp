#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <memory>
using namespace std;

struct rower
{
    int id;
    string nazwa;
    float cena;
    rower(int _id, string _nazwa, float _cena)
    {
        id = _id;
        nazwa = _nazwa;
        cena = _cena;
    }
    rower() {}
};
void wyswietl(vector<rower> vr)
{
    for (auto e : vr)
        cout << "\n"
             << e.id << " " << e.nazwa << " " << e.cena;
}
auto wybraneWgNazwy(vector<rower> vr)
{
    char lit;
    cout << "\nwpisz 1. lit nazwy: ";
    cin >> lit;
    auto itf = vr.begin();
    vector<rower> wybrane{};
    while (itf != vr.end()) //brak elementu lub koniec przeszukiwania -> zwracana pozycja end()
    {
        itf = find(itf, vr.end(), lit); //po pierwszym wyszukaniu
        if (itf != vr.end())
        {                            //jeżeli wyszukano element spełniający kryterium
            wybrane.push_back(*itf); //dodanie kolejnego wyszukanego do zbioru wyszukanych
            itf++;
        }
    }
    return wybrane;
}
auto sort_nazwa_rosnaco(vector<rower> vr)
{
    sort(vr.begin(), vr.end(), [](rower r1, rower r2)
         { return r1.nazwa < r2.nazwa; }); //zwraca true jeżeli elementy ułożone są poprawnie
    return vr;
}

int main()
{
    setlocale(LC_CTYPE, "polish");
    vector<rower> rowery{2};
    rowery[0] = {1, "kellys", 2900};
    rowery.at(1) = {2, "giant", 3400};
    rowery.push_back({3, "kellys", 1900});
    rower r1({4, "kross", 2300});
    rowery.push_back(r1);
    rower *r2 = new rower(5, "ktm", 2800);
    rowery.push_back(*r2);
    auto upr = make_unique<rower>(6, "ghost", 4600);
    rowery.push_back(*upr);
    wyswietl(rowery);
    cout << "\n wybrane rowery: ";
    wyswietl(wybraneWgNazwy(rowery));
    cout << "\n rowery posortowane wg nazwy rosnąco: ";
    vector<rower> rowery_sort{};
    rowery_sort = sort_nazwa_rosnaco(rowery);
    wyswietl(rowery_sort);
}