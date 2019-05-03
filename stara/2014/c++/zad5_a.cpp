#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy dana liczba jest liczba pierwsza
bool isPrime(int number)
{
    int counter = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            counter++;
    }

    if (counter == 1)
        return true;
    else
        return false;
}

string zad5_a()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/NAPIS.TXT");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int howMany = 0;

    // przechodzenie po vectorze z zawartoscia pliku
    for (int i = 0; i < content.size(); i++)
    {
        int lineNumber = 0;

        for (int j = 0; j < content[i].size(); j++)
        {
            // dodawanie do zmiennej wartosci ASCII danego znaku
            lineNumber += int(content[i][j]);
        }

        // wywolywanie funkcji sprawdzajacej czy liczba jest liczba pierwsza
        if (isPrime(lineNumber))
            howMany++;
    }

    return "5 a) Liczba napisow, ktorych suma wartosci ASCII jest liczba pierwsza: " + to_string(howMany);
}
