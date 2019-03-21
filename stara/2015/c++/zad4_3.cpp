#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int biggestZeroBlock(string line)
{
    int currentZeros, maxZeros = 0;

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '0')
        {
            int zeros = 0;

            for (int j = i; j < line.size() - i; j++)
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

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> biggest;
    int max = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (biggestZeroBlock(content[i]) > max)
            max = biggestZeroBlock(content[i]);
    }

    for (int i = 0; i < content.size(); i++)
    {
        if (biggestZeroBlock(content[i]) == max)
            biggest.push_back(content[i]);
    }

    string answer = "\n";

    for (int i = 0; i < biggest.size(); i++)
        answer += biggest[i] + "\n";

    return "4.3. Dlugosc najdluzszego bloku skladajacego sie z samych zer: " + to_string(max) + "\n Napisy, ktore zawieraja takie bloki: " + answer;
}