#include <fstream>
#include "zad4_a.cpp"
#include "zad4_b.cpp"
using namespace std;

int main()
{
    cout << zad4_a() << endl << endl << zad4_b();

    ofstream result("wyniki.txt");

    result << zad4_a() << endl << endl << zad4_b();
}