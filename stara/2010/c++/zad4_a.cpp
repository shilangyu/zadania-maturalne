#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<string> split(string words)
{
    vector<string> output;
    string readyToPush = "";

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] != ' ')
            readyToPush += words[i];
        else
        {
            output.push_back(readyToPush);
            readyToPush = "";
        }
    }

    output.push_back(readyToPush);

    return output;
}

bool areEqual(vector<string> words)
{
    int size;

    for (int i = 0; i < words.size(); i++)
    {
        if (i == 0)
            size = words[i].size();
        else
        {
            if (words[i].size() != size)
                return false;
        }
    }

    return true;
}

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