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

    fstream file("../dane/slowa.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int counter = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][content[i].size() - 1] == 'A')
            counter++;

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