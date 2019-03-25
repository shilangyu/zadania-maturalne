#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool isNotShrinking(string number)
{
    for (int i = 1; i < number.size(); i++)
    {
        if (number[i - 1] > number[i])
            return false;
    }

    return true;
}

string zad6_c()
{
    string line;
    vector<string> content;

    fstream file("../dane/dane.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int howMany = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isNotShrinking(content[i]))
            howMany++;
    }

    return to_string(howMany);
}