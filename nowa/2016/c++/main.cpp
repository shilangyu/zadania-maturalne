#include "zad6_1.cpp"
#include "zad6_2.cpp"
#include "zad6_3.cpp"
#include <fstream>
using namespace std;

int main()
{
     cout << zad6_1() << endl
          << endl
          << zad6_2() << endl
          << endl
          << zad6_3();

     ofstream result("wyniki.txt");

     result << zad6_1() << endl
            << endl
            << zad6_2() << endl
            << endl
            << zad6_3();
}
