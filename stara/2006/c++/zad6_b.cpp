#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// funkcja zamieniajaca liczbe w zapisie szesnastkowym,
// na liczbe w zapisie dziesietnym (dotyczy tylko zapisu ze znakami w zakresie <A;F>)
int thisHexToDec(string hex)
{
    int sum = 0;

    for (int i = 0; i < hex.size(); i++)
    {
        if (hex[i] == 'A')
        {
            sum += 10;
        }

        else if (hex[i] == 'B')
        {
            sum += 11;
        }

        else if (hex[i] == 'C')
        {
            sum += 12;
        }

        else if (hex[i] == 'D')
        {
            sum += 13;
        }

        else if (hex[i] == 'E')
        {
            sum += 14;
        }

        else if (hex[i] == 'F')
        {
            sum += 15;
        }
    }

    return sum;
}

string zad6_b()
{
    string line;
    fstream file("../dane/dane.txt");
    vector<string> content;

    // wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
        {
            content.push_back(line);
        }
    }
    file.close();

    // sprawdzanie ile jest liczb parzystych
    int evens = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (thisHexToDec(content[i]) % 2 == 0)
        {
            evens++;
        }
    }

    return "6 b) Liczba liczb parzystych: " + to_string(evens);
}
