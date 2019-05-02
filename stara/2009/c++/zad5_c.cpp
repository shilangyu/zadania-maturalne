#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//funkcja sprawdzajaca czy jeden string zawiera sie w drugim
bool isIn1(string container, string element)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == element[0])
        {
            for (int j = 0; j < element.size(); j++)
            {
                if (element[j] != container[i + j])
                    break;

                if (j == element.size() - 1)
                    return true;
            }
        }
    }

    return false;
}

bool areBordersSame(string a, string b)
{
    string checkA = "", checkB = "", checkBReversed = "";

    // sprawdzanie od lewej strony pierwszego napisu
    for (int i = b.size() - 1; i >= 0; i--)
    {
        checkBReversed += b[i];
    }

    for (int i = 0; i < a.size(); i++)
    {
        checkA += a[i], checkB = "";

        for (int j = 0; j < checkA.size(); j++)
        {
            checkB += checkBReversed[j];
        }

        string checkAReversed = "";

        for (int j = checkA.size() - 1; j >= 0; j--)
        {
            checkAReversed += checkA[j];
        }

        if (checkAReversed == checkB)
        {
            return true;
        }
    }

    checkA = "", checkB = "", checkBReversed = "";

    // sprawdzanie od prawej strony pierwszego napisu
    for (int i = a.size() - 1; i >= 0; i--)
    {
        checkA += a[i], checkB = "";

        for (int j = 0; j < checkA.size(); j++)
        {
            checkB += b[j];
        }

        string checkAReversed = "";

        for (int j = checkA.size() - 1; j >= 0; j--)
        {
            checkAReversed += checkA[j];
        }

        if (checkAReversed == checkB)
        {
            return true;
        }
    }

    return false;
}

string zad5_c()
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

    int answer = 0;

    // przechodzenie po wszystkich elementach z pliku
    for (int i = 0; i < content.size(); i++)
    {
        // jezeli slowo B nie zawiera sie w A, jak i sufiksy i prefiksy slow sa inne,
        // jedyna mozliwoscia utworzenia slowa C jest sklejenie A i B
        if (isIn1(wordsA[i], wordsB[i]) == false and areBordersSame(wordsA[i], wordsB[i]) == false)
        {
            answer++;
        }
    }

    return "5 c) Liczba par slow ktore maja te wlasciwosc, ze jedynym sposobem na utworzenie z nich slowa C jest ich sklejenie: " + to_string(answer);
}
