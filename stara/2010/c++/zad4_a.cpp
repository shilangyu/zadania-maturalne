#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// funkcja zwracająca vector z odseparowanymi słowami
vector<string> split(string words)
{
    vector<string> output;
    string readyToPush = "";

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] != ' ')
            readyToPush += words[i];
        else
        {
            output.push_back(readyToPush);
            readyToPush = "";
        }
    }

    output.push_back(readyToPush);

    return output;
}

// funkcja sprawdzająca czy wszystkie stringi w vectorze mają taką samą długość
bool areEqual(vector<string> words)
{
    int size;

    for (int i = 0; i < words.size(); i++)
    {
        if (i == 0)
            size = words[i].size();
        else
        {
            if (words[i].size() != size)
                return false;
        }
    }

    return true;
}

string zad4_a()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/anagram.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    string answer = "\n";

    // przechodzenie po zawartości pliku i sprawdzanie które wiersze spełniają wymaganie zadania
    for (int i = 0; i < content.size(); i++)
    {
        if (areEqual(split(content[i])))
            answer += content[i] + '\n';
    }

    return "4 a) Wiersze, w ktorych kazde slowo ma te sama dlugosc: " + answer;
}