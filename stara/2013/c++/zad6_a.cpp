#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string zad6_a()
{
    string line;
    vector<string> content;

    fstream file("../dane/dane.txt");

    // wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int howMany = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][0] == content[i][content[i].size() - 1])
            howMany++;
    }

    return "6 a) Liczba liczb, ktore maja te sama cyfre na poczatku co na koncu: " + to_string(howMany);
}