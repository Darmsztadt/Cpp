#include<iostream>
#include<unordered_map>
#include<sstream>
using namespace std;

int main()
{
    unordered_map<string,int> slownik;
    stringstream ss("struktura slownik algorytm struktura cplusplus algorytm program slownik biblioteka slownik");
    string slowo;
    while(ss>>slowo)
    {
        if(slownik.find(slowo)==slownik.end())slownik[slowo]=1;
        else slownik[slowo]++;
    }
    for(auto i=slownik.begin();i!=slownik.end();i++){
        cout<<"Slowo "<<i->first<<" wystapilo "<<i->second<<" razy"<<endl;
    }
}