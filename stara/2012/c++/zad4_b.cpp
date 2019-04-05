#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// funkcja deszyfrująca stringa
string decode(string word, string key)
{
    string output = "";

    if (key.size() < word.size())
    {
        int extend = (word.size()) / (key.size());

        for (int i = 0; i < extend; i++)
            key += key;
    }

    for (int i = 0; i < word.size(); i++)
    {
        int currentKey = int(key[i]) - 64, currentWord = int(word[i]), value = currentWord - currentKey;

        if (value < 65)
            value += 26;

        output += char(value);
    }

    return output;
}

string zad4_b()
{
    string line;
    vector<string> words;
    vector<string> keys;

    // wczytywanie danych z plików
    fstream wordsRead("../dane/sz.txt");
    fstream keysRead("../dane/klucze2.txt");

    if (wordsRead.is_open())
    {
        while (getline(wordsRead, line))
            words.push_back(line);
    }
    wordsRead.close();

    if (keysRead.is_open())
    {
        while (getline(keysRead, line))
            keys.push_back(line);
    }
    keysRead.close();

    string result = "\n";

    for (int i = 0; i < words.size(); i++)
        result += decode(words[i], keys[i]) + '\n';

    return "4 b) Odszyfrowane slowa: " + result;
}