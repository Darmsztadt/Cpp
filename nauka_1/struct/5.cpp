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

figura nowafigura(int &n)
{
    figura temp;
    n++;
    temp.numer=n;
    cout<<"\nPodaj nazwe figury\n";
    cin>>temp.nazwa;
    return temp;
}

int main()
{
    int n = 5;
    cout<<endl<<n<<endl;
    figura f1=nowafigura(n),f2=nowafigura(n);
    cout<<n<<endl<<f1.numer<<" "<<f1.nazwa<<endl<<f2.numer<<" "<<f2.nazwa<<endl;
}