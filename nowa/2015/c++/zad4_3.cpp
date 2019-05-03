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

    // wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    // znajdowanie maksymalnej dlugosci liczby
    int maxLength = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() > maxLength)
            maxLength = content[i].size();
    }

    // wyodrebnianie wszystkich najdluzszych liczb
    vector<string> theLongests;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() == maxLength)
            theLongests.push_back(content[i]);
    }

    // znajdowanie najdluzszej serii jedynek z przodu
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

    // znajdowanie tych liczb, ktore spelniaja warunek najwiekszej dlugosci i najdluzszej serii jedynek z przodu
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

    // okazalo sie, ze istnieje tylko jedna taka liczba
    string theLongestOne = theLongestOnes[0];

    // znajdowanie numeru wiersza zawierajacego najwieksza liczbe
    int biggestNumber;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i] == theLongestOne)
        {
            biggestNumber = i + 1;
            break;
        }
    }

    //-------------------------------------------------------------------------------

    // znajdowanie minimalnej dlugosci liczby
    int minLength = 10000;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() < minLength)
            minLength = content[i].size();
    }

    // znajdowanie liczb o najmniejszej dlugosci
    vector<string> theSmallest;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() == minLength)
            theSmallest.push_back(content[i]);
    }

    // okazalo sie, ze zostalo 5 liczb, z ktorych mozemy wywnioskowac, ze liczba 100 jest najmniejsza
    // znajdowanie numeru wiersza zawierajacego najmniejsza liczbe
    int smallestNumber;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i] == "100")
            smallestNumber = i + 1;
    }

    return "4.3. Numer wiersza zawierajacy najwieksza liczbe: " + to_string(biggestNumber) + "; Numer wiersza zawierajacy najmniejsza liczbe: " + to_string(smallestNumber);
}
