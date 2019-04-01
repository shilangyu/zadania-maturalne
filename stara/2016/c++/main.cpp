#include "zad5_1.cpp"
#include "zad5_2.cpp"
#include "zad5_3.cpp"
#include <fstream>
using namespace std;

int main()
{
    cout << zad5_1() << endl
         << endl
         << zad5_2() << endl
         << endl
         << zad5_3();

    ofstream result("wyniki.txt");

    result << zad5_1() << endl
           << endl
           << zad5_2() << endl
           << endl
           << zad5_3();
}