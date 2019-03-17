#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//funkcja rozdzielająca wektor
vector<vector<string>> splitVector(vector<string> input)
{
    vector<string> first;
    vector<string> second;
    vector<vector<string>> output;
    bool switchVector = false;
    string readyToPush = "";

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (switchVector)
            {
                readyToPush += input[i][j];

                if (j == input[i].size() - 1)
                {
                    second.push_back(readyToPush);
                    readyToPush = "";
                    switchVector = false;
                }
            }
            else
            {
                if (input[i][j] != ' ')
                    readyToPush += input[i][j];
                else
                {
                    first.push_back(readyToPush);
                    switchVector = true;
                    readyToPush = "";
                }
            }
        }
    }

    output.push_back(first);
    output.push_back(second);

    return output;
}

//funkcja sprawdzająca czy jeden string zawiera się w drugim
bool isIn(string contener, string element)
{
    for (int i = 0; i < contener.size(); i++)
    {
        if (contener[i] == element[0])
        {
            for (int j = 0; j < element.size(); j++)
            {
                if (element[j] != contener[i + j])
                    break;

                if (j == element.size() - 1)
                    return true;
            }
        }
    }

    return false;
}

string zad6_2()
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

    //tworzenie dwóch wektorów zawierających oddzielnie pierwsze i drugie słowa z linii
    vector<string> firstWords = splitVector(content)[0];
    vector<string> secondWords = splitVector(content)[1];

    int counter = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isIn(secondWords[i], firstWords[i]))
            counter++;
    }

    return "6.2. Liczba par slow, w ktorych pierwsze slowo zawiera sie w drugim: " + to_string(counter);
}