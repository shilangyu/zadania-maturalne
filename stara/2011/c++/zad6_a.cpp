#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad6_a()
{
    string line;
    vector<string> content;

    fstream file("../dane/liczby.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }

    int dividedByTwo;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][content[i].size() - 1] == '0')
            dividedByTwo++;
    }

    return "6 a) Liczba parzystych liczb: " + to_string(dividedByTwo);
}