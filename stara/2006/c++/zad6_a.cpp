#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy w danym vectorze dane slowo wystepuje wiecej niz jeden raz
bool isMoreThanOne(string word, vector<string> vec)
{
    int counter = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (word == vec[i])
        {
            counter++;
        }
    }

    if (counter > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string zad6_a()
{
    string line;
    fstream file("../dane/dane.txt");
    vector<string> content;

    // wczytywanie elementow z pliku
    if (file.is_open())
    {
        while (getline(file, line))
        {
            content.push_back(line);
        }
    }
    file.close();

    int howManyMoreThanOne = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (isMoreThanOne(content[i], content))
        {
            howManyMoreThanOne++;
        }
    }

    string answer = "6 a) Liczba slow wystepujacych w pliku wiecej niz jeden raz: " + to_string(howManyMoreThanOne);
}
