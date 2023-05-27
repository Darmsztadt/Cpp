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
    ifstream odczyt{"lab2/figury.txt"};
    if (!odczyt)
        cout << "\nBlad odczytu\n";
    figura tf2[n];
    for (int i = 0; i < n; i++)
    {
        odczyt >> tf2[i].numer >> tf2[i].nazwa;
    }
    odczyt.close();
    outtf(tf2, n);
}