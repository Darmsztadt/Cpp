#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size=10;
    vector<int> v(size);
    cout<<v.size()<<endl;
    for (size_t i=0; i<size; ++i)
    {
        v[i] = i;
        cout << v[i] << endl;
    }
    v.erase(2,6);
    for (size_t i=0; i<size; ++i)
    {
        cout << v[i] << endl;
    }
    v.erase(5);
    for (size_t i=0; i<size; ++i)
    {
        cout << v[i] << endl;
    }
    v.insert(v.begin(),102);
    for (size_t i=0; i<size; ++i)
    {
        cout << v[i] << endl;
    }
    v.push_back(110011);
    for (size_t i=0; i<size; ++i)
    {
        cout << v[i] << endl;
    }
}