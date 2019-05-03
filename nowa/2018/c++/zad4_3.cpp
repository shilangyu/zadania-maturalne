#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad4_3()
{
    string line;
    vector<string> content;

    fstream file("../dane/sygnaly.txt");

    // wczytywanie danych z pliku do vectora
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    // przypisanie zmiennym numerów odpowiadających za pierwszą literę alfabetu w tablicy ASCII (65)
    // oraz za ostatnią (90)
    int minAscii = 90;
    int maxAscii = 65;
    vector<char> word;
    vector<string> answerVector;

    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            word.push_back(content[i][j]);
        }

        for (int j = 0; j < word.size(); j++)
        {
            if (char(word[j]) < minAscii)
                minAscii = char(word[j]);
            if (char(word[j]) > maxAscii)
                maxAscii = char(word[j]);
        }

        if (maxAscii - minAscii <= 10)
            answerVector.push_back(content[i]);

        word.clear();
        minAscii = 90;
        maxAscii = 65;
    }

    string answer = "\n";

    for (int i = 0; i < answerVector.size(); i++)
        answer += answerVector[i] + "\n";

    return "4.3. Slowa, w ktorych litery sa maksymalnie oddalone od siebie o 10 znakow: " + answer;
}
