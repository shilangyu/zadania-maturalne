#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// funkcja odwracajaca string
string reverse(string word)
{
    string reversed = "";

    for (int i = word.size() - 1; i >= 0; i--)
    {
        reversed += word[i];
    }

    return reversed;
}

string zad5_a()
{
    string line;
    fstream file("../dane/slowa.txt");
    vector<string> content, reversed;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            content.push_back(line);   
        }
    }
    file.close();

    for (int i = 0; i < content.size(); i++)
    {
        reversed.push_back(reverse(content[i]));
    }

    int max = 0, min = 100;

    // sprawdzanie minimalnej i maksymalnej dlugosci
    for (int i = 0; i < reversed.size(); i++)
    {
        if (reversed[i].size() > max)
        {
            max = reversed[i].size();
        }

        if (reversed[i].size() < min)
        {
            min = reversed[i].size();
        }
    }

    vector<string> maxs, mins;

    // dodawanie do osobnych vectorow slow o minimalnej mozliwej dlugosci oraz
    // maksymalnej mozliwej dlugosci
    for (int i = 0; i < reversed.size(); i++)
    {
        if (reversed[i].size() == min)
        {
            mins.push_back(reversed[i]);
        }

        if (reversed[i].size() == max)
        {
            maxs.push_back(reversed[i]);
        }
    }

    // wypisywanie najkrotszych hasel
    string answer = "5 a) Najkrotsze hasla (ich dlugosc - " + to_string(min) + "):" + "\n";

    for (int i = 0; i < mins.size(); i++)
    {
        answer += mins[i] + "\n";
    }

    // wypisywanie najdluzszych hasel
    answer += "Najdluzsze hasla (ich dlugosc - " + to_string(max) + "):" + "\n";

    for (int i = 0; i < maxs.size(); i++)
    {
        answer += maxs[i] + "\n";
    }

    // wypisywanie wszystkich hasel
    answer += "Wszystkie hasla:";
    answer += "\n";

    for (int i = 0; i < reversed.size(); i++)
    {
        answer += reversed[i] + "\n";
    } 

    return answer;
}
