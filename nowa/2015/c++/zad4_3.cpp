#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string zad4_3()
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

    int maxLength = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() > maxLength)
            maxLength = content[i].size();
    }

    return to_string(maxLength);
}