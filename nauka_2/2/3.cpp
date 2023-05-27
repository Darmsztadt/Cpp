#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct figura
{
    int numer;
    string nazwa;
};

void outtf(figura t[], int n)
{
    cout << "\nElementy tablicy: \n";
    for (int i = 0; i < n; i++)
    {
        cout << t[i].numer << " " << t[i].nazwa << endl;
    }
}

figura nowafigura()
{
    figura temp;
    cout << "\nPodaj numer i nazwe figury\n";
    cin >> temp.numer >> temp.nazwa;
    return temp;
}

int main()
{
    const int n = 5;
    figura f1{1, "trojkat"}, f2{2, "prostokat"}, f3{3, "kolo"};
    figura tf[n] = {f1, f2, f3};
    tf[3] = nowafigura();
    tf[4] = nowafigura();
    outtf(tf, n);
    ofstream zapis{"lab2/figury.txt", ios::app};
    zapis << tf[3].numer << " " << tf[3].nazwa << endl;
    zapis << tf[4].numer << " " << tf[4].nazwa << endl;
    zapis.close();
}