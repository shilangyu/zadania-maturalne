#include "zad5_a.cpp"
#include "zad5_b.cpp"
#include "zad5_c.cpp"
#include "zad5_d.cpp"
#include <fstream>
using namespace std;

int main()
{
    cout << zad5_a() << endl
         << endl
         << zad5_b() << endl
         << endl
         << zad5_c() << endl
         << endl
         << zad5_d() << endl;

    ofstream result("wyniki.txt");

    result << zad5_a() << endl
         << endl
         << zad5_b() << endl
         << endl
         << zad5_c() << endl
         << endl
         << zad5_d() << endl;
}
