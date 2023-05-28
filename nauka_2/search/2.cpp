#include <iostream>
using namespace std;

void printArray(int tablica[], int dlugosc)
{
    if (dlugosc > 0)
        cout << tablica[0];
    for (int i = 1; i < dlugosc; i++)
    {
        cout << ", " << tablica[i];
    }
    cout << endl;
}
int linearSearch(int tablica[], int dlugosc, int x)
{
    for (int i = 0; i < dlugosc; i++)
    {
        if (x == tablica[i])
            return i;
    }
    return -1;
}

int main()
{
    int size = 6;
    int tab[] = {5, 7, 9, 11, 14, 16};
    int find[] = {0, 5, 11, 16};
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << linearSearch(tab, 6, find[i]) << " ";
    }
    int tab2[]={1, 10, 13, 12, 9, 18};
    int find2[]={10,13,9};
    cout<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << linearSearch(tab2, 6, find2[i]) << " ";
    }
}