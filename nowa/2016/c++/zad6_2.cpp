#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string zad6_2()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/dane_6_2.txt");

    if (file.is_open())
    {
        while (getline(file, line))
        {
            content.push_back(line);
        }
        file.close();
    }

    // rozdzielanie vactora content na slowa i klucze
    vector<string> encrypted;
    vector<int> ks;

    for (int i = 0; i < content.size(); i++)
    {
        string tempWord = "", tempK = "";
        bool space = false;

        for (int j = 0; j < content[i].size(); j++)
        {
            if (space)
            {
                tempK += content[i][j];
            }
            else if (content[i][j] != ' ')
            {
                tempWord += content[i][j];
            }

            if (content[i][j] == ' ')
            {
                space = true;
            }
        }

        encrypted.push_back(tempWord);
        ks.push_back(atoi(tempK.c_str()));
    }

    string decrypted = "6.2. Odszyfrowane wyrazy: \n";

    // przechodzenie po kazdej literze kazdego slowa
    for (int i = 0; i < encrypted.size(); i++)
    {
        string temp = "";

        for (int j = 0; j < encrypted[i].size(); j++)
        {
            // numer ASCII znaku po cofnieciu go o "k"
            int differenceASCII = encrypted[i][j] - ks[i];

            // zapobieganie wychodzenia ponizej liczby 65
            while (differenceASCII < 65)
            {
                differenceASCII += 26;
            }

            temp += differenceASCII;
        }

        if (i != content.size() - 1)
        {
            decrypted += temp + "\n";
        }
        else
        {
            decrypted += temp;
        }

        temp = "";
    }

    return decrypted;
}
