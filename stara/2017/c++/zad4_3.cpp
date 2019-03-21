#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//funkcja zwracająca wartość w systemie dziesiętnym danego zapisu binarnego
int toDecimal2(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);
    }

    return output;
}

string zad4_3()
{
    string line;
    vector<string> content;

    fstream file("../dane/binarne.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    //"filtrowanie" vectora z zawartością, sprawdzanie czy dany element w zapisie dziesiętnym wynosi więcej niż 65 535
    //i zapisywanie poprawnych danych do kolejnego vectora
    vector<string> goodOnes;

    for (int i = 0; i < content.size(); i++)
    {
        if (toDecimal2(content[i]) <= 65535)
            goodOnes.push_back(content[i]);
    }

    //szukanie maksymalnej wartości spośród tych "przefiltrowanych" elementów oraz samego tego elementu
    int maxValue = 0;
    string chosenOne;

    for (int i = 0; i < goodOnes.size(); i++)
    {
        if (toDecimal2(goodOnes[i]) > maxValue)
        {
            maxValue = toDecimal2(goodOnes[i]);
            chosenOne = goodOnes[i];
        }
    }

    return "4.3. Najwieksza liczba w zapisie dziesietnym: " + to_string(maxValue) + "; Najwieksza liczba w zapisie binarnym: " + chosenOne;
}