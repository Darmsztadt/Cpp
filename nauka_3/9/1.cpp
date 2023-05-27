#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    // pusty konstruktor
    unordered_map<string, int> slownik1;
    // wstawianie operatorem []
    slownik1["klucz1"] = 10;
    slownik1["klucz2"] = 20;
    // wybieranie operatorem []
    cout << "Element o kluczu klucz1 ma wartosc: "
         << slownik1.at("klucz1") << endl;
    unordered_map<string, int> zlote_medale =
        {
            {"Australia", 1},
            {"Kanada", 4}};
    zlote_medale["Austria"] = 7;
    zlote_medale["Lotwa"] = 0;
    zlote_medale["USA"] = 8;
    zlote_medale.insert(make_pair("Nowa Zelandia", 2));
    string klucz = "Sri Jayavardanapura-kotte";
    if (zlote_medale.find(klucz) == zlote_medale.end())
        cout << "Nie znaleziono elementu o kluczu: " << klucz << endl;
    else
        cout << "Znaleziono element o kluczu: " << klucz << endl;
    unordered_map<string, int>::iterator it = zlote_medale.find(klucz);
    if (it == zlote_medale.end())
        cout << "Nie znaleziono elementu o kluczu: " << klucz << endl;
    else
        cout << "Zlote medale zdobyte przez " << it->first << ": " << it->second << endl;
    cout << "Wszystkie panstwa i medale:\n";
    for (auto iter = zlote_medale.begin(); iter != zlote_medale.end(); iter++)
    {
        cout << iter->first << ": " << iter->second << endl;
    }
}