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
    const int n = 3;
    figura f1{1, "trojkat"}, f2{2, "prostokat"}, f3{3, "kolo"};
    figura tf[n] = {f1, f2, f3};
    outtf(tf, n);
    ofstream zapis{"lab2/figury.txt"};
    for (int i = 0; i < n; i++)
    {
        zapis << tf[i].numer << " " << tf[i].nazwa << endl;
    }
    zapis.close();
}