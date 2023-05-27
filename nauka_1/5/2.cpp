#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct pomiar
{
    int numer;
    string opis;
    float odczyt;
    void wyswietl() { cout << "\n " << numer << " " << opis << " " << odczyt; }
    pomiar(int _numer, string _opis, float _odczyt)
    {
        numer = _numer;
        opis = _opis;
        odczyt = _odczyt;
        cout << "\n powstał obiekt typu pomiar...";
    }
    pomiar() { cout << "\n utworzono pusty obiekt typu pomiar..."; }
    ~pomiar() { cout << "\n usuwanie obiektu typu pomiar o numerze " << numer << endl; }
};

int main()
{
    setlocale(LC_CTYPE, "polish");
    cout << "\n początek bloku ze zwykłymi wskaźnikami: ";
    {
        pomiar p1{};
        p1.numer = 1;
        p1.opis = "st";
        p1.odczyt = 23.45f;
        pomiar *wp1 = &p1;
        cout << "\n p1 wyświetlone przez wskaźnik: ";
        wp1->wyswietl();
        pomiar *p2 = new pomiar{12, "dn", 76.4f};
        p2->wyswietl();
        pomiar *p3 = new pomiar();
        p3->numer = 13;
        p3->opis = "dn";
        p3->odczyt = 0.89f;
        p3->wyswietl();
        cout << "\n usuniecie p2 i p3 za pomoca delete...";
        delete p2;
        delete p3;
    }
    cout << "\n koniec bloku ze zwykłymi wskaźnikami...";
    cout << "\n poczatek bloku z unique_ptr: ";
    {
        unique_ptr<pomiar> upp4(new pomiar);
        upp4->numer = 114;
        upp4->opis = "up";
        upp4->odczyt = 56.2f;
        upp4->wyswietl();
        auto upp5 = make_unique<pomiar>(115, "up", 39.87f);
        upp5->wyswietl();
    }
    cout << "\n koniec bloku z unique_ptr ";
    shared_ptr<pomiar> spp8;
    cout << "\n poczatek bloku z shared_ptr: ";
    {
        auto spp7 = make_shared<pomiar>(227, "sp", 2.1f);
        spp7->wyswietl();
        spp8 = spp7;
        cout << "\n spp7 wyswietlony za pomoca spp8: ";
        spp8->wyswietl();
        cout << "\n adresy spp7 oraz spp8: " << spp7.get() << " " << spp8.get();
        cout << "\n liczba wskaźników pokazujaca na obiekt: " << spp8.use_count();
    }
    cout << "\n pozostałe instrukcje w main()..." << endl;
    cout << "\n spp8.reset: ";
    spp8.reset();
    cout << "\n adresy spp8 po reset(): " << spp8.get();
    cout << "\n liczba wskaźników pokazująca na obiekt: " << spp8.use_count();
    cout << "\n pozostałe instrukcje w main()..." << endl;
    cout << "\n koniec programu..." << endl;
}