#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy dany string jest palindromem
bool isPali(string word)
{
    string reversed = "";

    for (int i = word.size() - 1; i >= 0; i--)
    {
        reversed += word[i];
    }

    if (word == reversed)
    {
        return true;
    }

    return false;
}

string zad6_c()
{
    string line;
    fstream file("../dane/dane.txt");
    vector<string> content;

    // wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
        {
            content.push_back(line);
        }
    }
    file.close();

    // sprawdzanie ile jest palindromow
    int palis = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isPali(content[i]))
        {
            palis++;
        }
    }

    return "6 c) Liczba palindromow: " + to_string(palis);
}
