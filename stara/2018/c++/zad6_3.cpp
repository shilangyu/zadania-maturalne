#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//funkcja rozdzielająca wektor
vector<vector<string>> splitVector2(vector<string> input)
{
    vector<string> first;
    vector<string> second;
    vector<vector<string>> output;
    bool switchVector = false;
    string readyToPush = "";

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (switchVector)
            {
                readyToPush += input[i][j];

                if (j == input[i].size() - 1)
                {
                    second.push_back(readyToPush);
                    readyToPush = "";
                    switchVector = false;
                }
            }
            else
            {
                if (input[i][j] != ' ')
                    readyToPush += input[i][j];
                else
                {
                    first.push_back(readyToPush);
                    switchVector = true;
                    readyToPush = "";
                }
            }
        }
    }

    output.push_back(first);
    output.push_back(second);

    return output;
}

//funkcja sprawdzająca czy dwa słowa są anagramami
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

string zad6_3()
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

    //tworzenie dwóch wektorów zawierających oddzielnie pierwsze i drugie słowa z linii
    vector<string> firstWords = splitVector2(content)[0];
    vector<string> secondWords = splitVector2(content)[1];

    vector<string> answerVector;

    for (int i = 0; i < content.size(); i++)
    {
        if (isAnagram(firstWords[i], secondWords[i]))
            answerVector.push_back(content[i]);
    }

    string answer = "\n";

    for (int i = 0; i < answerVector.size(); i++)
        answer += answerVector[i] + "\n";

    int answerInt = answerVector.size();

    return "6.3. Liczba par slow, ktore sa anagramami: " + to_string(answerInt) + "; " + "Pary slow, ktore sa anagramami: " + answer;
}