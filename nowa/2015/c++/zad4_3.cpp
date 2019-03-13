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

    //znajdowanie maksymalnej długości liczby
    int maxLength = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() > maxLength)
            maxLength = content[i].size();
    }

    //wyodrębnienie wszystkich najdłuższych liczb
    vector<string> theLongests;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() == maxLength)
            theLongests.push_back(content[i]);
    }

    //znajdowanie najdłuższej serii jedynek z przodu
    int maxOnesInRow = 0, currentMaxOnesInRow = 0;

    for (int i = 0; i < theLongests.size(); i++)
    {
        for (int j = 0; j < theLongests[i].size(); j++)
        {
            if (theLongests[i][j] == '1')
                currentMaxOnesInRow++;
            else
                break;
        }

        if (currentMaxOnesInRow > maxOnesInRow)
            maxOnesInRow = currentMaxOnesInRow;

        currentMaxOnesInRow = 0;
    }

    //znajdowanie tych liczb, które spełniają warunek największej długości i najdłuższej serii jedynek z przodu
    vector<string> theLongestOnes;

    for (int i = 0; i < theLongests.size(); i++)
    {
        for (int j = 0; j < theLongests[i].size(); j++)
        {
            if (theLongests[i][j] == '1')
                currentMaxOnesInRow++;
            else
                break;
        }

        if (currentMaxOnesInRow == maxOnesInRow)
            theLongestOnes.push_back(theLongests[i]);

        currentMaxOnesInRow = 0;
    }

    //okazało się, że istnieje tylko jedna taka liczba
    string theLongestOne = theLongestOnes[0];

    //znajdowanie numeru wiersza zawierającego największa liczbę
    int biggestNumber;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i] == theLongestOne)
        {
            biggestNumber = i + 1;
            break;
        }
    }

    return "4.3. Numer wiersza zawierajacy najwieksza liczbe: " + to_string(biggestNumber);
}