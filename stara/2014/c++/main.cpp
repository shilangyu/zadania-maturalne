#include <fstream>
#include "zad5_a.cpp"
#include "zad5_b.cpp"
#include "zad5_c.cpp"
using namespace std;

int main()
{
     cout << zad5_a() << endl
          << endl
          << zad5_b() << endl
          << zad5_c();

     ofstream result("wyniki.txt");

     result << zad5_a() << endl
            << endl
            << zad5_b() << endl
            << zad5_c();
}