#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string zad6_2()
{
    // uzywam odwroconego alfabetu, by uzyc tej samej metody do odszyfrowania, co do szyfrowania
    string line, alphabet = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    vector<string> content;

    fstream file("../dane/dane_6_2.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    // odszyfrowywanie wyrazow
    vector<string> decoded;

    for (int i = 0; i < content.size(); i++)
    {
        string currentElement = "", currentCode = "";
        bool switchToCode = false;

        for (int j = 0; j < content[i].size(); j++)
        {
            if (switchToCode)
            {
                currentCode += content[i][j];

                if (i == content[i].size() - 1)
                    switchToCode = false;
            }
            else
            {
                if (content[i][j] != ' ')
                    currentElement += content[i][j];
                else
                    switchToCode = true;
            }
        }

        int k = atoi(currentCode.c_str());
        string temporaryAlphabet = alphabet;

        // powiekszanie alfabetu, ktorego bedziemy uzywac o odpowiednia ilosc razy w zalezności od liczby "k"
        for (int j = 0; j < (k / alphabet.size() + 1); j++)
        {
            temporaryAlphabet += alphabet;
        }

        string readyToPush = "";

        for (int j = 0; j < currentElement.size(); j++)
        {
            int currentAlphabetPosition;

            for (int l = 0; l < alphabet.size(); l++)
            {
                if (alphabet[l] == content[i][j])
                    currentAlphabetPosition = l;
            }

            readyToPush += temporaryAlphabet[currentAlphabetPosition + k];
        }

        decoded.push_back(readyToPush);
        readyToPush = "";
    }

    // wypelnianie stringa, ktory ma cala zawartosc vectora decoded
    string decodedString = "\n";

    for (int i = 0; i < decoded.size(); i++)
    {
        if (i != decoded.size() - 1)
            decodedString += decoded[i] + "\n";
        else
            decodedString += decoded[i];
    }

    return "6.2. Odszyfrowane wyrazy: " + decodedString;
}
