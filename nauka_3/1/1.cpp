#include <iostream>
using namespace std;
int silnia;
int fun_silnia(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fun_silnia(n - 1);
}
int main()
{
    int liczba;
    cin >> liczba;
    cout << fun_silnia(liczba);
}
