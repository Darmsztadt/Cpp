#include <iostream>
#include <string>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    const int r = 8;
    random_device rd;
    uniform_int_distribution<> ud(0, 255);
    int bin[r];
    int liczba10 = ud(rd);
    cout << "Liczba10=" << liczba10 << endl;
    for (int i = r - 1; i >= 0; i--)
    {
        bin[i] = liczba10 % 2;
        liczba10 = liczba10 / 2;
    }
    cout << "Liczba2=";
    for (int i = 0; i <= r - 1; i++)
    {
        cout << bin[i];
    }
    cout << endl;
}