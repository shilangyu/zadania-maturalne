#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string zad6_3()
{
    string line;
    vector<string> content;

    fstream file("../dane/dane_6_3.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }

    //rozdzielanie vectora z całą zawartością na dwa oddzielne vectory z początkowymi wyrazami i zaszyfrowanymi
    vector<string> rawData;
    vector<string> encodedData;
    bool switchVector = false;
    string readyToPush = "";

    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            if (switchVector)
            {
                readyToPush += content[i][j];

                if (j == content[i].size() - 1)
                {
                    encodedData.push_back(readyToPush);
                    readyToPush = "";
                    switchVector = false;
                }
            }
            else
            {
                if (content[i][j] != ' ')
                    readyToPush += content[i][j];
                else
                {
                    rawData.push_back(readyToPush);
                    switchVector = true;
                    readyToPush = "";
                }
            }
        }
    }

    return "";
}