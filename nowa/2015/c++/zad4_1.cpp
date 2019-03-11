#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad4_1()
{
    string line;
    vector<string> content;

    fstream file("../dane/liczby.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    //liczenie linii, które mają więcej zer niż jedynek
    int howManyLines = 0, zeros = 0, ones = 0;

    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            if (content[i][j] == '0')
                zeros++;
            else
                ones++;
        }

        if (zeros > ones)
            howManyLines++;

        zeros = 0;
        ones = 0;
    }

    return "4.1. Liczba linii, w ktorych jest wiecej zer niz jedynek: " + to_string(howManyLines);
}