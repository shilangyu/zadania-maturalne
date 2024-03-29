#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

// funkcja zwracajaca wartosc odpowiadajaca dlugosci najdluzszego bloku skladajacego sie z samych zer
int biggestZeroBlock(string line)
{
    int currentZeros, maxZeros = 0;

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '0')
        {
            int zeros = 0;

            for (int j = i; j < line.size(); j++)
            {
                if (line[j] == '0')
                    zeros++;
                else
                    break;
            }

            currentZeros = zeros;

            if (currentZeros > maxZeros)
                maxZeros = currentZeros;
        }
    }

    return maxZeros;
}

string zad4_3()
{
    string line;
    vector<string> content;

    fstream file("../dane/slowa.txt");

    // wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> biggest;
    int max = 0;

    // przechodzenie po vectorze z zawartoscia i sprawdzanie jaki jest max wystepowania zer z rzedu
    for (int i = 0; i < content.size(); i++)
    {
        if (biggestZeroBlock(content[i]) > max)
            max = biggestZeroBlock(content[i]);
    }

    // dodawanie elementow do oddzielnego vectora, ktore zawieraja blok o maksymalnej dlugości
    for (int i = 0; i < content.size(); i++)
    {
        if (biggestZeroBlock(content[i]) == max)
            biggest.push_back(content[i]);
    }

    string answer = "\n";

    for (int i = 0; i < biggest.size(); i++)
        answer += biggest[i] + "\n";

    return "4.3. Dlugosc najdluzszego bloku skladajacego sie z samych zer: " + to_string(max) + "\nNapisy, ktore zawieraja takie bloki: " + answer;
}
