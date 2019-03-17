#include "zad4_1.cpp"
#include "zad4_2.cpp"
#include "zad4_3.cpp"
#include <fstream>

int main()
{
    cout << zad4_1() << endl
         << endl
         << zad4_2() << endl
         << endl
         << zad4_3();

    ofstream result("wyniki.txt");

    result << zad4_1() << endl
           << endl
           << zad4_2() << endl
           << endl
           << zad4_3();
}