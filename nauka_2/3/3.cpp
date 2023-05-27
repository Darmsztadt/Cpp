#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
random_device rd;

int **tab2w(int lw, int *temp, int min, int max)
{
    uniform_int_distribution<> ud(min, max);
    int **t = new int *[lw];
    for (int i = 0; i < lw; i++)
    {
        *(t + i) = new int[*(temp + i)];
        for (int j = 0; j < *(temp + i); j++)
            *(*(t + i) + j) = ud(rd);
    }
    return t;
}

void wyswietl(int **t, int lw, int *temp)
{
    for (int i = 0; i < lw; i++)
    {
        cout << endl;
        for (int j = 0; j < *(temp + i); j++)
            cout << setw(3) << *(*(t + i) + j);
    }
}

int main()
{
    const int min = 1, max = 10;
    int lw;
    cout << "Podaj ilosc wierszy: ";
    cin >> lw;
    int *temp = new int[lw];
    for (int i = 0; i < lw; i++)
    {
        cout << "\nPodaj liczbe el w wierszu " << i << ": ";
        cin >> *(temp + i);
    }
    int **t2 = tab2w(lw, temp, min, max);
    wyswietl(t2, lw, temp);
}