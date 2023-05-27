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
    int count = 0;
    for (auto iter = zlote_medale.begin(); iter != zlote_medale.end(); iter++)
    {
        cout << iter->first << ": " << iter->second << endl;
        count++;
    }
    int empty = 0;
    for (int i = 0; i < zlote_medale.bucket_count(); i++)
    {
        cout << "Ilosc elementow w pojemniku " << i << ": " << zlote_medale.bucket_size(i) << endl;
        if (zlote_medale.bucket_size(i) == 0)
            empty++;
    }
    cout << "Ilosc elementow: " << count << ", ilosc pojemnikow: " << zlote_medale.bucket_count() << ", ilosc pustych pojemikow: " << empty << endl;
    cout << "Wspolczynnik zapelnienia: " << (float)count / (float)zlote_medale.bucket_count() << ", metoda load factor: " << zlote_medale.load_factor() << endl;
    zlote_medale.erase("Austria");
    count = 0;
    for (auto iter = zlote_medale.begin(); iter != zlote_medale.end(); iter++)
    {
        cout << iter->first << ": " << iter->second << endl;
        count++;
    }
    empty = 0;
    for (int i = 0; i < zlote_medale.bucket_count(); i++)
    {
        cout << "Ilosc elementow w pojemniku " << i << ": " << zlote_medale.bucket_size(i) << endl;
        if (zlote_medale.bucket_size(i) == 0)
            empty++;
    }
    zlote_medale.insert(slownik1.begin(), slownik1.end());
    for (auto iter = zlote_medale.begin(); iter != zlote_medale.end(); iter++)
    {
        cout << iter->first << ": " << iter->second << endl;
        count++;
    }
}