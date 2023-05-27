#include <iostream>
using namespace std;

class urzadzenie 
{
public:
    int zapis(int id, string dane);  //obiekt nie moze byc czysto wirtualny
    string odczyt(int id);
    ~urzadzenie() {}
};

class dysk : public urzadzenie
{
private:
    int id_;
    string dane_;
public:
    dysk(int id);
    int zapis(int id, string dane);
    string odczyt(int id);
};

dysk::dysk(int id)
{
    cout << "Tworzenie obiektu klasy dysk " << endl;
    if(id>0)id_ = id;
}

int dysk::zapis(int id, string dane)
{
    dane_ = dane;
    cout << "zapis danych: " << dane << endl;
    if(id>0)return 1;
    else return -1;
}

string dysk::odczyt(int id)
{
    cout << "odczyt danych: " << dane_ << endl;
    return dane_;
}

int main()
{
    urzadzenie u;
    dysk d1(7);
    d1.zapis(7, "test 11");
    d1.odczyt(7);
}