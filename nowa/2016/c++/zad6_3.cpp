#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// funkcja rozdzielajaca vector z cala zawartoscia na dwa oddzielne vectory z poczatkowymi wyrazami i zaszyfrowanymi
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

// funkcja znajdujaca przesuniecie
int findKey(int decodedChar, int encodedChar)
{
    if (encodedChar >= decodedChar)
        return encodedChar - decodedChar;
    else
    {
        return (90 - decodedChar) + (encodedChar - 64);
    }
}

string zad6_3()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/dane_6_3.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    // wywolywanie funkcji splitView
    vector<string> decoded = splitVector(content)[0];
    vector<string> encoded = splitVector(content)[1];

    string answer = "6.3. Wyrazy blednie zaszyfrowane: \n";

    for (int i = 0; i < content.size(); i++)
    {
        // znajdowanie przesuniecia pierwszego znaku w slowie
        int k = findKey(decoded[i][0], encoded[i][0]);

        for (int j = 1; j < decoded[i].size(); j++)
        {
            // sprawdzanie czy klucz zgadza sie w dalszej czesci slowa
            if (findKey(decoded[i][j], encoded[i][j]) != k)
            {
                answer += decoded[i] + "\n";
                break;
            }
        }
    }

    return answer;
}
