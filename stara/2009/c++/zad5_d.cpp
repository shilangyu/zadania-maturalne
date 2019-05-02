#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy jeden string zawiera sie w drugim
bool isIn2(string container, string element)
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

bool areBordersSame1(string a, string b)
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

string secondMethodConstructLeft(string a, string b)
{
    string checkA = "", checkB = "", checkBReversed = "", c = "";
    bool isPossible = false;

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
            isPossible = true;

            c = "";

            for (int j = 0; j < b.size() - checkB.size(); j++)
            {
                c += b[j];
            }

            c += a;
        }
    }

    if (isPossible)
    {
        return c;
    }
    else 
    {
        return "NONE";
    }
}

string secondMethodConstructRight(string a, string b)
{
    string checkA = "", checkB = "", checkBReversed = "", c = "";
    bool isPossible = false;

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
            isPossible = true;

            c = "";

            for (int j = 0; j < a.size() - checkB.size(); j++)
            {
                c += a[j];
            }

            c += b;
        }
    }

    if (isPossible)
    {
        return c;
    }
    else
    {
        return "NONE";
    }
}

// funkcja zwracajaca najbardziej optymalne slowo C
string createC(string a, string b)
{
    if (isIn2(a, b))
    {
        return a;
    }
    else if (areBordersSame1(a, b))
    {
        string leftC = secondMethodConstructLeft(a, b), rightC = secondMethodConstructRight(a, b);

        if (leftC == "NONE")
        {
            return rightC;
        }
        else if (rightC == "NONE")
        {
            return leftC;
        }
        else
        {
            if (leftC.size() <= rightC.size())
            {
                return leftC;
            }
            else
            {
                return rightC;
            }
        }
    }
    else
    {
        return a + b;
    }
}

string zad5_d()
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

    string answer = "\n";

    for (int i = 0; i < content.size(); i++)
    {
        answer += createC(wordsA[i], wordsB[i]) + "\n";
    }

    return "5 d) Najbardziej optymalne slowa C:" + answer;
}
