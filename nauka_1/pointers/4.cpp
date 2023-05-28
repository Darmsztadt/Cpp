#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
random_device rd;

int *tab1w(int le, int min, int max)
{
    uniform_int_distribution<> ud(min, max);
    int *t = new int[le];
    int l=1;
    *t=ud(rd);
    for (int i = 0; i < le; i++)
    {
        int los = ud(rd), temp = 0;
        for (int j = 0; j < l; j++)
        {
            if (*(t + i) != los)
            {
                temp++;
            }
        }
        if (temp == l)
        {
            *(t + l) = los;
            l++;
        }
    }
    return t;
}

void wyswietl(int *t, int le)
{
    for (int i = 0; i < le; i++)
        cout << *(t + i) << " ";
}

int main()
{
    int n, min, max;
    cout<<"\nPodaj ilosc el, min i max: ";
    cin>>n>>min>>max;
    int *t1=tab1w(n,min,max);
    wyswietl(t1,n);
}