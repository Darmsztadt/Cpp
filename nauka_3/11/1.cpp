#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int n = 6;
int optPoprz[n], d[n], c[n];

void WczytajGraf(string nazwaPliku, int **g, int r)
{
    fstream plik(nazwaPliku.c_str());
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            plik >> g[i][j];
}

void WczytajGraf(int **g, int r)
{
    int temp[r][r] = {{0, 1, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}};
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            g[i][j] = temp[i][j];
}

void WyswietlGraf(int **g, int r, int p)
{
    for (int i = 0; i < r; i++)
    {
        cout << "\n";
        for (int j = 0; j < r; j++)
        {
            cout << setw(p) << g[i][j];
        }
    }
}

int **Graf(int r)
{
    int **g = new int *[r];
    for (int i = 0; i < r; i++)
        g[i] = new int[r];
    return g;
}

void droga_RW(int **R)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            if (R[y][x] != 0)
                for (int z = 0; z < n; z++)
                    if (R[y][z] == 0 && R[x][z] != 0)
                    {
                        R[y][z] = R[y][x];
                    }
}

void floyd_warshall(int **g, int **r, int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (g[i][k] + g[k][j] < g[i][j]) // jeżeli nie ma poł.->g=10000 wiec nie spełni nierowności
                {
                    g[i][j] = g[i][k] + g[k][j]; // jeżeli nierow. prawdziwa nowy koszt poł. = sumie kosztów
                    r[i][j] = r[k][j];
                }
            }
}

int minR(int v[], int c[])
{
    int nMin = 0;
    int vMin = 10000;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < vMin && c[i] == 0)
        {
            nMin = i;
            vMin = v[i];
        }
    }
    return nMin;
}

void dijkstra(int **G, int n, int s)
{
    int v, u;
    for (v = 0; v < n; v++)
    {
        c[v] = 0;         // tab. spr. węzłów, 0=niespr, 1=sprawdzony
        d[v] = G[s][v];   // wektor kosztów najkrótszych ścieżek od s do v
        optPoprz[v] = -1; // wektor poprzedników węzłow v, potrzebny do odtworzenia drogi
    }
    for (int i = 0; i < n; i++)
    {
        u = minR(d, c);         // wybór wierzchołka o najmn. wadze krawędzi spośród niespr. (r[v]=1)
        c[u] = 1;               // wierzchołek wyłączony z dostępnych, nie będzie już spr.
        for (v = 0; v < n; v++) // dla każdego węzła
        {
            if (c[v] == 0) // jeżeli nie był jeszcze spr., nie ma opt. najkr. drogi
            {
                if (d[u] + G[u][v] < d[v]) // szukanie krótszej drogi
                {
                    d[v] = d[u] + G[u][v];
                    optPoprz[v] = u; // zapis poprzednika w najkrótszej ścieżce
                }
            }
        }
    }
}

int main()
{
    int **g = Graf(n);
    //-------------------------------------------------
    cout << "\n\n alg. zmodyfikowany R-W" << endl;
    WczytajGraf(g, n);
    cout << "\n\n macierz grafu G: " << endl;
    WyswietlGraf(g, n, 3);
    int **r = Graf(n);
    for (int x = 0; x < n; x++) // macierz ruchu
        for (int y = 0; y < n; y++)
            if (g[x][y] == 0)
                r[x][y] = 0;
            else
                r[x][y] = y + 1; // y+1-> num. w tab od 0, wez. A=1
    cout << "\n\n macierz ruchu R: " << endl;
    WyswietlGraf(r, n, 3);
    droga_RW(r); // szukanie połaczen miedzy wezłami
    cout << "\n\n po wyzn. drogi: " << endl;
    WyswietlGraf(r, n, 3);
    //---------------------------------------------------
    cout << "\n\n alg. Floyda-Warshalla - wyzn. drogi opt. pod wzgl. kosztow" << endl;
    int **k = Graf(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            k[i][j] = 10000;
    cout << "koszty krawedzi" << endl;
    int temp[n][n] = {{10000, 10000, 16, 12, 10000, 10000}, {8, 10000, 28, 10000, 35, 10000}, {10000, 10000, 10000, 10000, 5, 10000}, {10000, 22, 10000, 10000, 10000, 18}, {10000, 10000, 10000, 10000, 10000, 40}, {10000, 10, 10000, 10000, 10000, 10000}};
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
        {
            k[x][y] = temp[x][y];
        }
    WyswietlGraf(k, n, 6);
    cout << "\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (k[i][j] != 10000)
                r[i][j] = i;
            else
                r[i][j] = -1;

    floyd_warshall(k, r, n);
    cout << "\n tab kosztow po alg. F-W \n";
    WyswietlGraf(k, n, 6);
    cout << "\n\n macierz polaczen po alg. F-W \n";
    WyswietlGraf(r, n, 3);
    cout << "\ndroga bezposrednia zastapiona posrednia dla wezlow:";
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
        {
            if (k[x][y] != 10000 && k[x][y] != r[x][y])
                cout << endl
                     << x << " " << y;
        }
    cout << "\n\n";
    //-----------------------------------------
    cout << "\n\n alg. dijkstry \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            k[i][j] = 10000;
    // koszty połączen
    // k[x][y]=a;...
    int pocz = 0, kon = 0; // numery węzłów dla szukanej drogi, gdzie w. A=0, F=5
    cout << "\n alg. Dijkstry, droga: " << char(pocz + 65) << "->" << char(kon + 65);
    dijkstra(k, n, pocz);
    cout << endl;
    cout << "\nwektor d po alg.: ";
    for (int i = 0; i < n; i++)
        cout << " " << d[i];
    cout << "\n wekt optPoprz po alg., A=0...F=5: ";
    for (int i = 0; i < n; i++)
        cout << " " << optPoprz[i];
}