#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
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

// funkcja odwracajaca string
string reverse1(string word)
{
    string reversed = "";

    for (int i = word.size() - 1; i >= 0; i--)
    {
        reversed += word[i];
    }

    return reversed;
}

// funkcja tworzaca haslo
string encrypt(string word)
{
    if (isPali(word))
    {
        return word; 
    }
    else
    {
        string current = "", w1; 

        for (int i = 0; i < word.size() - 1; i++)
        {
            current += word[i];

            if (current == reverse1(current))
            {
                w1 = current;
            }
        }

        string w2 = "";

        for (int i = w1.size(); i < word.size(); i++)
        {
            w2 += word[i];
        }

        return reverse1(w2) + w1 + w2;
    }
}

string zad5_b()
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

    vector<string> encrypted, twelves, maxs, mins;

    for (int i = 0; i < content.size(); i++)
    {
        encrypted.push_back(encrypt(content[i]));
    }

    string answer = "Hasla:\n";

    int max = 0, min = 1000;

    // wypisywanie wszystkich hasel
    for (int i = 0; i < encrypted.size(); i++)
    {
        answer += encrypted[i] + "\n";

        if (encrypted[i].size() > max)
        {
            max = encrypted[i].size();
        }

        if (encrypted[i].size() < min)
        {
            min = encrypted[i].size();
        }
    }

    int sum = 0;

    for (int i = 0; i < encrypted.size(); i++)
    {
        if (encrypted[i].size() == 12)
        {
            twelves.push_back(encrypted[i]);
        }

        if (encrypted[i].size() == max)
        {
            maxs.push_back(encrypted[i]);
        }

        if (encrypted[i].size() == min)
        {
            mins.push_back(encrypted[i]);
        }

        sum += encrypted[i].size();
    }

    answer += "1. Hasla o dlugosci 12:\n";

    for (int i = 0; i < twelves.size(); i++)
    {
        answer += twelves[i] + "\n";
    }

    answer += "2. Najdluzsze haslo:\n";

    for (int i = 0; i < maxs.size(); i++)
    {
        answer += maxs[i] + "\n";
    }

    answer += "Najkrotsze haslo:\n";

    for (int i = 0; i < mins.size(); i++)
    {
        answer += mins[i] + "\n";
    }

    answer += "3. Suma dlugosci wszystkich hasel: " + to_string(sum) + "\n";

    return answer;
} 
