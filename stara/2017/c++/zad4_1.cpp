#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//funkcja sprawdzająca czy dany string jest dwucykliczny
bool isBicycle(string line)
{
    //sprawdzanie czy długość stringa jest liczbą parzystą
    if (line.size() % 2 == 0)
    {
        string firstHalf = "", secondHalf = "";

        //rozdzielanie stringa na dwie połowy
        for (int i = 0; i < line.size(); i++)
        {
            if (i <= (line.size() / 2) - 1)
                firstHalf += line[i];
            else
                secondHalf += line[i];
        }

        //sprawdzanie czy dwie połowy są identyczne
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

    //wczytywanie danych z pliku
    fstream file("../dane/binarne.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    //wywoływanie funkcji isBicycle dla każdego stringa z wektora content
    vector<string> bicycles;

    for (int i = 0; i < content.size(); i++)
    {
        if (isBicycle(content[i]))
            bicycles.push_back(content[i]);
    }

    //sprawdzanie ile wynosi maksymalna długość stringa
    int maxLength = 0;

    for (int i = 0; i < bicycles.size(); i++)
    {
        if (bicycles[i].size() > maxLength)
            maxLength = bicycles[i].size();
    }

    string longest;

    //znajdowanie najdłuższego napisu
    for (int i = 0; i < bicycles.size(); i++)
    {
        if (bicycles[i].size() == maxLength)
            longest = bicycles[i];
    }

    return "4.1. Liczba slow dwucyklicznych: " + to_string(bicycles.size()) + "; Najdluzszy napis dwucykliczny: " + longest + "; Jego dlugosc: " + to_string(longest.size());
}