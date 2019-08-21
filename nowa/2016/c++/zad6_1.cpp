#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string zad6_1()
{
    string line;
    vector<string> content;
    int k = 107;

    // wczytywanie danych z pliku
    fstream file("../dane/dane_6_1.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    string encrypted = "6.1. Zaszyfrowane wyrazy: \n";

    // przechodzenie po kazdej literze kazdego slowa
    for (int i = 0; i < content.size(); i++)
    {
        string temp = "";

        for (int j = 0; j < content[i].size(); j++)
        {
            // numer ASCII znaku po przesunieciu go o "k"
            int sumASCII = content[i][j] + k;

            // zapobieganie wychodzenia poza numer 90 w tablicy ASCII
            while (sumASCII > 90)
            {
                sumASCII -= 26;
            }

            temp += sumASCII;
        }

        if (i != content.size() - 1)
        {
            encrypted += temp + "\n";
        }
        else
        {
            encrypted += temp;
        }

        temp = "";
    }

    return encrypted;
}
