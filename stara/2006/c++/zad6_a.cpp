#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy w danym vectorze dane slowo wystepuje wiecej niz jeden raz
bool isMoreThanOne(string word, vector<string> vec, vector<string> banned)
{
    for (int i = 0; i < banned.size(); i++)
    {
        if (word == banned[i])
        {
            return false;
        }
    }

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
    vector<string> banned;

    for (int i = 0; i < content.size(); i++)
    {
        if (isMoreThanOne(content[i], content, banned))
        {
            howManyMoreThanOne++;
            banned.push_back(content[i]);
        }
    }

    // sprawdzanie, ktore slowo wystepuje najwiecej razy w pliku
    int max = 0;
    string currentMax = "h";

    for (int i = 0; i < content.size(); i++)
    {
        int temp = 0;
        
        for (int j = 0; j < content.size(); j++)
        {

            if (content[i] == content[j])
            {
                temp++;
            }
        }

        if (temp > max)
        {
            max = temp;
            currentMax = content[i];
        }
    }

    // cout << currentMax;

    string answer = "6 a) Liczba slow wystepujacych w pliku wiecej niz jeden raz: " + to_string(howManyMoreThanOne);

    return answer;
}
