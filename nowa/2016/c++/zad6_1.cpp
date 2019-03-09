#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string zad6_1()
{
    string line, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<string> content;
    int k = 107;

    fstream file("../dane/dane_6_1.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    string temporaryAlphabet = alphabet;

    //powiększanie alfabetu, którego będziemy używać o odpowiednią ilość razy w zależności od liczby "k"
    for (int i = 0; i < (k / alphabet.size() + 1); i++)
    {
        temporaryAlphabet += alphabet;
    }

    vector<string> encoded;
    string readyToPush = "";

    //szyfrowanie wyrazów
    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            int currentAlphabetPosition;

            for (int l = 0; l < alphabet.size(); l++)
            {
                if (alphabet[l] == content[i][j])
                    currentAlphabetPosition = l;
            }

            readyToPush += temporaryAlphabet[currentAlphabetPosition + k];
        }

        encoded.push_back(readyToPush);
        readyToPush = "";
    }

    //wypełnianie stringa, który ma całą zawartość vectora encoded
    string encodedString = "";

    for (int i = 0; i < encoded.size(); i++)
    {
        if (i != encoded.size() - 1)
            encodedString += encoded[i] + ", ";
        else
            encodedString += encoded[i];
    }

    return "6.1) Zaszyfrowane wyrazy: " + encodedString;
}