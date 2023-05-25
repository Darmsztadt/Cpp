#include <iostream>
#include <random>
#include <exception>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void wyswietl(T *t, int r)
{
    cout << "\n funkcja wywołana dla typu: " << typeid(T).name() << endl;
    for (int i = 0; i < r; i++)
        if (typeid(T).name() == typeid(double).name() || typeid(T).name() == typeid(float).name())
            cout << fixed << setprecision(2) << *(t + i) << " ";
        else
            cout << *(t + i) << " ";
}

template <class T>
T srednia(unique_ptr<T> &t, int r)
{
    double suma;
    for (int i = 0; i < r; i++)
    {
        suma += *(t.get() + i);
    }
    return suma / r;
}

void koniec()
{
    cout << "\n działa funkcja set_terminate()...";
    cout << "\n wystąpił nieobsłużony wyjątek!!!";
    cout << "\n przed zamknięciem programu wykonywana funkcja koniec()..." << endl;
    using chrono::system_clock; //wymagana biblioteka <chrono>
    time_t err_time = system_clock::to_time_t(system_clock::now());
    //chrono obsługuje tylko czas, nie ma obsługi daty, konwersja do time_t 
    tm t;                                               //tm-> struktura przechowująca składniki daty i czasu
    localtime_s(&t, &err_time);                         //konwersja time_t do typu tm z uwzględnieniem lokalnej strefy czasowej
    auto currentDT = put_time(&t, "%d-%m-%Y %H:%M:%S"); //konwersja na napis, wymaga <iomanip>
    cout << currentDT << endl;
    ofstream plik{"lab6/exception.txt"};
    plik << "aplikacja zakończona z powodu błędu... " << endl;
    plik << currentDT;
    plik.close();
    exit(1); //zakończenie programu z kodem 1
}

int main()
{
    int n = 10;
    char *tc = new char[n];
    int *ti = new int[n];
    float *tf = new float[n];
    double *td = new double[n];
    random_device rd;
    uniform_int_distribution<int> udi(0, 9);
    uniform_real_distribution<double> udd(0, 9.99);
    uniform_real_distribution<float> udf(0, 9.99);
    uniform_int_distribution<int> udc(65, 90);
    for (int i = 0; i < n; i++)
    {
        *(tc + i) = udc(rd);
        *(ti + i) = udi(rd);
        *(td + i) = udd(rd);
        *(tf + i) = udf(rd);
    }
    wyswietl(tc, n);
    wyswietl(ti, n);
    wyswietl(td, n);
    wyswietl(tf, n);
    try
    {
        set_terminate(koniec);
        float suma = 0;
        float odwrotnosc;
        int los;
        int seed = 123;
        cout << "\nseed=" << seed << endl;
        srand(seed); //parameter generator liczb losowych
        for (int i = 1; i <= 10; i++)
        {
            los = rand() % 5 - 2; //-2..2
            cout << "\nlos=" << los;
            if (los == 0)
                throw 0;
            odwrotnosc = 1.0f / los;
            cout << " " << odwrotnosc;
            suma += odwrotnosc;
        }
        cout << "\n suma odwrotnosci wylosowanych=" << suma << endl;
    }
    // catch (int &ex)
    // {
    //     cout << "\n wyjatek! wylosowano=" << ex;
    // }
    catch (double &ex)
    {
        cout << "\n wyjatek! wyloswano" << ex;
    }
    cout << "\n wykonywanie dalszych instrukcji...";
    vector<float> v(10);
    uniform_real_distribution<float> udf2(1, 10);
    generate(v.begin(), v.end(), [&rd, &udf2]()
             { return udf2(rd); });
    cout << "\n elementy wektora v: ";
    for (auto e : v)
        cout << " " << e;
    try
    {
        for (int i = 1; i <= 2; i++)
        {
            cout << "\n wpisz numer elementu do wyświetlenia: ";
            int n;
            cin >> n;
            cout << v.at(n);
            //cout<< v[n];
        }
    }
    catch (exception &e)
    {
        cout << "\n wyjątek:" << e.what();
        cout << "\n " << typeid(e).name();
        cout << "\n nie mam takiego elementu!" << endl;
    }
    cout << "\n dalsze instrukcje...\n";
    uniform_int_distribution<int> udi2(0, 20);
    try
    {
        int r = 1 - 8;
        auto tab = make_unique<int[]>(r);
        srednia(&tab, r);
    }
    catch (exception &e)
    {
        cout << "\n wyjątek:" << e.what();
        cout << "\n " << typeid(e).name();
        cout << "\n nieprawidlowy rozmiar!" << endl;
    }
}