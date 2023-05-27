#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,int> slownik;
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        slownik[i]=i*i;
    }
    for (auto i = slownik.begin(); i !=slownik.end(); i++)
    {
        cout<<"Klucz: "<<i->first<<", kwadrat klucza: "<<i->second<<endl;
    }
    
}