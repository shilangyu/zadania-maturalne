#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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
}