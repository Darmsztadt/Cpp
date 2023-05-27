#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
random_device rd;

int **tab2w(int lw, int lk, int min, int max)
{
    uniform_int_distribution<> ud(min, max);
    int **t = new int *[lw];
    for (int i = 0; i < lw; i++)
    {
        *(t + i) = new int[lk];
        for (int j = 0; j < lk; j++)
            *(*(t + i) + j) = ud(rd);
    }
    return t;
}

void wyswietl(int *t, int le)
{
    for (int i = 0; i < le; i++)
        cout << *(t + i) << " ";
}

void wyswietl(int **t, int lw, int lk)
{
    for (int i = 0; i < lw; i++)
    {
        cout << endl;
        for (int j = 0; j < lk; j++)
            cout << setw(3) << *(*(t + i) + j);
    }
}

void unikat(int **t, int lw, int lk)
{
    int *t1 = new int[lw * lk];
    int l = 1;
    *t1 = **t;
    for (int i = 0; i < lw; i++)
    {
        for (int j = 0; j < lk; j++)
        {
            int temp = 0;
            for (int k = 0; k < l; k++)
            {
                if (*(*(t + i) + j) != *(t1 + k))
                {
                    temp++;
                }
            }
            if (temp == l)
            {
                *(t1 + l) = *(*(t + i) + j);
                l++;
            }
        }
    }
    cout << "\nIlosc roznych el w tab 2w: " << l << endl
         << "Zbior el: ";
    wyswietl(t1, l);
}

int main()
{
    const int min = 1, max = 10;
    int lw = 3, lk = 4;
    int **t2 = tab2w(lw, lk, min, max);
    wyswietl(t2, lw, lk);
    unikat(t2, lw, lk);
}