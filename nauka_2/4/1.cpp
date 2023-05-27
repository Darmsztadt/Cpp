#include <iostream>
#include <memory>
using namespace std;

typedef unique_ptr<unique_ptr<int[]>[]> up2w;

void td(int w, int k, up2w &t2w)
{ // jest & bo nie może być kopia
    for (int i = 0; i < w; i++)
    {
        t2w[i] = make_unique<int[]>(k);
        for (int j = 0; j < k; j++)
            t2w[i][j] = rand() % 10;
    }
}

void wyswietl(int w, int k, up2w &t2w)
{
    cout << " elementy tablicy 2-wym.: ";
    for (int i = 0; i < w; i++)
    {
        cout << "\n";
        for (int j = 0; j < k; j++)
            cout << t2w[i][j] << " ";
    }
}

int main()
{
    int w = 4, k = 5;
    auto t2up = make_unique<unique_ptr<int[]>[]>(w);
    td(w, k, t2up);
    wyswietl(w, k, t2up);
}