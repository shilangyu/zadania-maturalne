#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int toDecimal(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);

        counter++;
    }

    return output;
}

bool isCorrect(string line)
{
    if (line.size() % 4 == 0)
    {
        string readyToCheck = "";

        for (int i = 0; i < line.size(); i++)
        {
            if ((i + 1) % 4 == 0)
            {
                if (toDecimal(readyToCheck) < 0 or toDecimal(readyToCheck) > 9)
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

    int howManyFalse = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isCorrect(content[i]) == false)
            howManyFalse++;
    }

    return to_string(howManyFalse);
}
