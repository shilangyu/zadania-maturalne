#include <fstream>
#include "zad5_a.cpp"
#include "zad5_b.cpp"
using namespace std;

int main()
{
    cout << zad5_a() << endl << zad5_b();

    ofstream result("wyniki.txt");

    result << zad5_a() << endl << zad5_b();
}
