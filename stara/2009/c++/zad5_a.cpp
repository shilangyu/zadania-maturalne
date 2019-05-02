#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool isPali(string word)
{
    string reversed = "";

    for (int i = word.size() - 1; i >= 0; i--)
    {
        reversed += word[i];
    }

    if (word == reversed)
    {
        return true;
    }

    return false;
}

string zad5_a()
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

    // rozdzielanie zawartosci vectora na dwa oddzielne vectory
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

    int howManyPali = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isPali(wordsA[i]))
        {
            howManyPali++;
        }

        if (isPali(wordsB[i]))
        {
            howManyPali++;
        }
    }

    return "5 a) Liczba palindromow w pliku: " + to_string(howManyPali);
}
