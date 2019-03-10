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

//funkcja znajdowanie przesunięcia
int findCode(char raw, char encoded)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int code, rawNumber;

    //sprawdzanie pozycji znaku w alfabecie
    for (int i = 0; i < alphabet.size(); i++)
    {
        if (alphabet[i] == raw)
        {
            rawNumber = i;
            break;
        }
    }

    //sprawdzanie odległości pierwszego znaku od drugiego
    for (int i = rawNumber + 1; i < alphabet.size(); i++)
    {
        if (alphabet[i] == encoded)
        {
            code = i - rawNumber;
            break;
        }
    }

    return code;
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
    vector<string> answer;

    string manuallyEncoded = "";

    for (int i = 0; i < raw.size(); i++)
    {
        int code = findCode(raw[i][0], encoded[i][0]);

        for (int j = 0; j < raw[i].size(); j++)
        {
            int currentAlphabetPosition;

            for (int k = 0; k < alphabet.size(); k++)
            {
                if (alphabet[k] == raw[i][j])
                    currentAlphabetPosition = k;
            }

            manuallyEncoded += alphabet[currentAlphabetPosition + code];
        }

        if (manuallyEncoded != encoded[i])
            answer.push_back(raw[i]);

        manuallyEncoded = "";
    }

    string answerString = "";

    for (int i = 0; i < answer.size(); i++)
    {
        if (i != answer.size() - 1)
            answerString += answer[i] + ", ";
        else
            answerString += answer[i];
    }

    return "6.3) Wyrazy zaszyfrowane blednie: " + answerString;
}