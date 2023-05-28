#include <iostream>
#include <string>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    char cont;
    do
    {
        random_device rd;
        uniform_int_distribution<> ud(0, 1);
        const int r = 8;
        int los, liczba10 = 0;
        for (int i = 0; i < r; i++)
        {
            los = ud(rd);
            cout << los;
            liczba10 = liczba10 + los * powf(2, r - 1 - i);
        }
        cout << "\nLiczba10=" << liczba10 << endl
             << "Czy wygenerowac ponownie? t/n\n";
        cin >> cont;
        while (cont != 't' && cont != 'n')
        {
            cout << "Bledny znak, wprowadz ponownie\n";
            cin >> cont;
        }

    } while (cont == 't');
}