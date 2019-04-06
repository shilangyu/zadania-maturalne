#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// funkcja sprawdzajaca czy dwa slowa sa anagramami
bool isAnagram(string first, string second)
{
    vector<char> secondWord;

    if (first.size() == second.size())
    {

        for (int i = 0; i < first.size(); i++)
            secondWord.push_back(second[i]);

        bool checker;

        for (int i = 0; i < first.size(); i++)
        {
            for (int j = 0; j < secondWord.size(); j++)
            {
                if (first[i] == secondWord[j])
                {
                    secondWord[j] = '-';
                    checker = true;
                    break;
                }
                else if (first[i] != secondWord[j])
                    checker = false;
            }

            if (checker == false)
                return false;
        }
    }
    else
        return false;

    for (int i = 0; i < secondWord.size(); i++)
    {
        if (secondWord[i] != '-')
            return false;
    }

    return true;
}

// funkcja zwracająca vector z odseparowanymi słowami
vector<string> split1(string words)
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
}