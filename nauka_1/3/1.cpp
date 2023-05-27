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

int main()
{
    figura f1{1, "trojkat"}, f2{2, "prostokat"}, f3{3, "kolo"};
    figura tf[3] = {f1, f2, f3};
    outtf(tf, 3);
    ofstream zapis{"lab2/figury.txt"};
    for (int i = 0; i < 3; i++)
    {
        zapis << tf[i].numer << " " << tf[i].nazwa << endl;
    }
    zapis.close();
}