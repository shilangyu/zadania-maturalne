#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isBicycle(string line)
{
    if (line.size() % 2 == 0)
    {
        string firstHalf = "", secondHalf = "";

        for (int i = 0; i < line.size(); i++)
        {
            if (i <= (line.size() / 2) - 1)
                firstHalf += line[i];
            else
                secondHalf += line[i];
        }

        if (firstHalf == secondHalf)
            return true;
        else
            return false;
    }
    else
        return false;
}

string zad4_1()
{
    string line;
    vector<string> content;

    fstream file("../dane/binarne.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> bicycles;

    for (int i = 0; i < content.size(); i++)
    {
        if (isBicycle(content[i]))
            bicycles.push_back(content[i]);
    }

    int maxLength = 0;

    for (int i = 0; i < bicycles.size(); i++)
    {
        if (bicycles[i].size() > maxLength)
            maxLength = bicycles[i].size();
    }

    string longest;

    for (int i = 0; i < bicycles.size(); i++)
    {
        if (bicycles[i].size() == maxLength)
            longest = bicycles[i];
    }

    return "4.1. Liczba slow dwucyklicznych: " + to_string(bicycles.size()) + "; Najdluzszy napis dwucykliczny: " + longest + "; Jego dlugosc: " + to_string(longest.size());
}