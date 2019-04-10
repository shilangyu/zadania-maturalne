#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

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

string zad5_b()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/dane.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> wordsA;
    vector<string> wordsB;

    // rozdzielanie zawartości vectora na dwa oddzielne vectory
    for (int i = 0; i < content.size(); i++)
    {
        string readyToPush = "";
        bool afterGap = false, wasPushed = false;

        for (int j = 0; j < content[i].size(); j++)
        {
            if (content[i][j] == ' ')
            {
                afterGap = true;
            }
            else if (afterGap)
            {
                if (wasPushed == false)
                {
                    wordsA.push_back(readyToPush);
                    wasPushed = true;
                    readyToPush = "";
                }

                readyToPush += content[i][j];
            }
            else
            {
                readyToPush += content[i][j];
            }
        }

        wordsB.push_back(readyToPush);
    }

    int answer = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isIn(wordsA[i], wordsB[i]))
        {
            answer++;
        }
    }

    return "Liczba wierszy, w ktorych drugie slowo zawiera sie w pierwszym: " + to_string(answer);
}