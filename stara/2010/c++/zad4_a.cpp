#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

string zad4_a()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/anagram.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    return "";
}