#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

string zad4_1()
{
    string line;
    vector<string> content;

    fstream file("../dane/slowa.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    //przechodzenie po zawartosci pliku, zliczanie zer i jedynek poszczegolnych elementow
    //i zliczanie ile jest elementow, ktore maja wiecej zer niz jedynek
    int howMany = 0;

    for (int i = 0; i < content.size(); i++)
    {
        int zeros = 0, ones = 0;

        for (int j = 0; j < content[i].size(); j++)
        {
            if (content[i][j] == '0')
                zeros++;
            else
                ones++;
        }

        if (zeros > ones)
            howMany++;

        zeros = 0;
        ones = 0;
    }

    return "4.1. Liczba slow, ktore maja wiecej zer niz jedynek: " + to_string(howMany);
}
