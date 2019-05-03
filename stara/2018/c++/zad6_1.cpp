#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string zad6_1()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/slowa.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    // sprawdzanie czy dane slowo konczy sie na litere 'A'
    int counter = 0;

    for (int i = 0; i < content.size(); i++)
    {
        // sprawdzanie czy pierwsze slowo z linii sie zalicza
        if (content[i][content[i].size() - 1] == 'A')
            counter++;

        // sprawdzanie czy drugie slowo z linii sie zalicza
        for (int j = 0; j < content[i].size(); j++)
        {
            if (content[i][j] == ' ')
            {
                if (content[i][j - 1] == 'A')
                    counter++;
            }
        }
    }

    return "6.1. Liczba slow, ktore koncza sie na litera 'A': " + to_string(counter);
}
