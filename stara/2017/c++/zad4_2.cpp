#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//funkcja zwracajaca wartosc w systemie dziesietnym danego zapisu binarnego
int toDecimal1(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);
    }

    return output;
}

//funkcja sprawdzajaca czy string jest poprawnie zapisany
bool isCorrect(string line)
{
    //sprawdzanie czy napis sklada sie z cztero-znakowych elementow
    if (line.size() % 4 == 0)
    {
        string readyToCheck = "";

        //przechodzenie po napisie
        for (int i = 0; i < line.size(); i++)
        {
            if ((i + 1) % 4 == 0)
            {
                readyToCheck += line[i];

                //sprawdzanie czy wartosc nie przekracza 9
                if (toDecimal1(readyToCheck) > 9)
                    return false;

                readyToCheck = "";
            }
            else
                readyToCheck += line[i];
        }

        return true;
    }
    else
        return false;
}

string zad4_2()
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

    //sprawdzanie ile jest niepoprawnie zapisanych napisow oraz wczytywanie do osobnego vectora
    int howManyFalse = 0;
    vector<string> falseNumbers;

    for (int i = 0; i < content.size(); i++)
    {
        if (isCorrect(content[i]) == false)
        {
            howManyFalse++;
            falseNumbers.push_back(content[i]);
        }
    }

    //sprawdzanie ile wynosi najkrotszy napis sposrod niepoprawnych
    int minLength = 10000;

    for (int i = 0; i < falseNumbers.size(); i++)
    {
        if (falseNumbers[i].size() < minLength)
            minLength = falseNumbers[i].size();
    }

    return "4.2. Liczba slow niepoprawnych: " + to_string(howManyFalse) + "; Dlugosc najkrotszego niepoprawnie zapisanego napisu: " + to_string(minLength);
}
