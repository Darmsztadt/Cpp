#include <iostream>
#include <string>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    const int r = 8;
    int bin[r];
    int liczba10;
    cout << "Wprowadz liczbe10" << endl;
    cin >> liczba10;
    while (liczba10 > powf(2, r) - 1 || liczba10 < 0)
    {
        cout<<"Liczba niepoprawna, wprowadz ponownie\n";
        cin >> liczba10;
    };
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