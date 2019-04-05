#include <fstream>
#include "zad6_a.cpp"
#include "zad6_b.cpp"
using namespace std;

int main()
{
    cout << zad6_a() << endl << endl << zad6_b();

    ofstream result("wyniki.txt");

    result << zad6_a() << endl << endl << zad6_b();
}