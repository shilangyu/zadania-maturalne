#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string encode(string word, string key)
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
        int currentKey = int(key[i]) - 64, currentWord = int(word[i]), value = currentKey + currentWord;

        if (value > 90)
            value -= 26;

        output += char(value);
    }

    return output;
}

string zad4_a()
{
    string line;
    vector<string> words;
    vector<string> keys;

    // wczytywanie danych z plików
    fstream wordsRead("../dane/tj.txt");
    fstream keysRead("../dane/klucze1.txt");

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

    ofstream test("test.txt");

    for (int i = 0; i < words.size(); i++)
        test << encode(words[i], keys[i]) << endl;
}