#include "zad6_a.cpp"
#include "zad6_b.cpp"
#include "zad6_c.cpp"
#include <fstream>
using namespace std;

int main()
{
    cout << zad6_a() << endl
         << endl
         << zad6_b() << endl
         << endl
         << zad6_c();

    ofstream result("wyniki.txt");

    result << zad6_a() << endl
           << endl
           << zad6_b() << endl
           << endl
           << zad6_c();
}