#include "zad6_1.cpp"
#include "zad6_2.cpp"
#include "zad6_3.cpp"
#include "zad6_4.cpp"
#include <fstream>
using namespace std;

int main()
{
    cout << zad6_1() << endl
         << zad6_2() << endl
         << zad6_3() << endl
         << zad6_4() << endl;

    ofstream file("wyniki.txt");

    file << zad6_1() << endl
         << zad6_2() << endl
         << zad6_3() << endl
         << zad6_4() << endl;
}