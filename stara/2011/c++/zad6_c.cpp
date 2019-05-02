#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// funkcja zamieniajaca liczbe zapisana w systemie binarnym na zapis dziesietny
string binaryToDecimal1(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);
    }

    return to_string(output);
}

// funkcja zmieniajaca liczbe w zapisie dziesietnym na zapis dwojkowy
string decimalToBinary(int number)
{
    string binaryReverse = "", output = "";

    while (number != 0)
    {
        binaryReverse += to_string(number % 2);

        number = number / 2;
    }

    // odwracanie zapisu binarnego
    for (int i = binaryReverse.size() - 1; i >= 0; i--)
        output += binaryReverse[i];

    return output;
}

string zad6_c()
{
    string line;
    vector<string> content;

    fstream file("../dane/liczby.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> nines;
    vector<string> ninesDecimal;

    // przechodzenie po vectorze content i dodawanie do vectorow te elementy, ktore maja dlugosc rowna 9
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() == 9)
        {
            nines.push_back(content[i]);
            ninesDecimal.push_back(binaryToDecimal1(content[i]));
        }
    }

    int sum = 0;

    // dodawanie kolejnych elementow do sumy
    for (int i = 0; i < ninesDecimal.size(); i++)
        sum += atoi(ninesDecimal[i].c_str());

    // wywolywanie funkcji, ktora zamieni wynik w systemie dziesietnym na zapis w binarnym
    string sumBinary = decimalToBinary(sum);

    return "6 c) Liczba dziewieciocyfrowych: " + to_string(nines.size()) + "; Suma liczb (w systemie dwojkowym) skladajacych sie tylko z 9 liczb: " + sumBinary;
}
