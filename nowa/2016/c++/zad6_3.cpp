#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//funkcja rozdzielająca vector z całą zawartością na dwa oddzielne vectory z początkowymi wyrazami i zaszyfrowanymi
vector<vector<string>> splitVector(vector<string> input)
{
    vector<string> rawData;
    vector<string> encodedData;
    vector<vector<string>> output;
    bool switchVector = false;
    string readyToPush = "";

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (switchVector)
            {
                readyToPush += input[i][j];

                if (j == input[i].size() - 1)
                {
                    encodedData.push_back(readyToPush);
                    readyToPush = "";
                    switchVector = false;
                }
            }
            else
            {
                if (input[i][j] != ' ')
                    readyToPush += input[i][j];
                else
                {
                    rawData.push_back(readyToPush);
                    switchVector = true;
                    readyToPush = "";
                }
            }
        }
    }

    output.push_back(rawData);
    output.push_back(encodedData);

    return output;
}

string zad6_3()
{
    string line;
    vector<string> content;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

    fstream file("../dane/dane_6_3.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }

    //wywoływanie funkcji splitVector
    vector<string> raw = splitVector(content)[0];
    vector<string> encoded = splitVector(content)[1];

    return "";
}