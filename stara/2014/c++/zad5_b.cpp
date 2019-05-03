#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy napis jest rosnacy
bool isGrowing(string line)
{
    int previous = int(line[0]);

    for (int i = 1; i < line.size(); i++)
    {
        if (previous >= line[i])
            return false;

        previous = line[i];
    }

    return true;
}

string zad5_b()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/NAPIS.TXT");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    // dodawanie tych elementow do vectora growing, ktore sa rosnace
    vector<string> growing;

    for (int i = 0; i < content.size(); i++)
    {
        if (isGrowing(content[i]))
            growing.push_back(content[i]);
    }

    // dodawanie elementow z vectora growing do stringa answer
    string answer = "\n";

    for (int i = 0; i < growing.size(); i++)
    {
        answer += growing[i] + "\n";
    }

    return "5 b) Napisy rosnace:" + answer;
}
