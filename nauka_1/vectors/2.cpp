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

auto sortcenamalejaco(vector<rower> vr)
{
    sort(vr.begin(), vr.end(), [](rower r1, rower r2)
         { return r1.cena > r2.cena; });
    return vr;
}
void wyswietl(vector<rower> vr)
{
    for (auto e : vr)
        cout << "\n"
             << e.id << " " << e.nazwa << " " << e.cena;
}
auto cenamaxi(vector<rower> vr, float &cena)
{
    find_if(vr.begin(), vr.end(), [](rower r1, float cena)
            { return r1.cena < cena; });
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
    wyswietl(sortcenamalejaco(rowery));
    float cenamax;
    cout << endl
         << "Podaj cene maksymalna: ";
    cin >> cenamax;
    cout << endl;
    wyswietl(cenamaxi(rowery, cenamax));
}