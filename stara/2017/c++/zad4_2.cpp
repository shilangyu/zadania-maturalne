#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isCorrect(string line)
{
    if (line.size() % 4 == 0)
    {
        string readyToCheck = "";

        for (int i = 0; i < line.size(); i++)
        {
            if ((i + 1) % 4 == 0)
            {
            }
            else
                readyToCheck += line[i];
        }
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

    for (int i = 0; i < content.size(); i++)
    {
    }
}
