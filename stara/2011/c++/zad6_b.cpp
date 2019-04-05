#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// funkcja zamieniająca liczbę zapisaną w systemie binarnym na zapis dziesiętny
string binaryToDecimal(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);
    }

    return to_string(output);
}

string zad6_b()
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

    vector<string> decimalNumbers;

    for (int i = 0; i < content.size(); i++)
        decimalNumbers.push_back(binaryToDecimal(content[i]));

    int max = 0;

    for (int i = 0; i < decimalNumbers.size(); i++)
    {
        if (atoi(decimalNumbers[i].c_str()) > max)
            max = atoi(decimalNumbers[i].c_str());
    }

    string maxDecimal, maxBinary;

    for (int i = 0; i < decimalNumbers.size(); i++)
    {
        if (atoi(decimalNumbers[i].c_str()) == max)
        {
            maxDecimal = decimalNumbers[i];
            maxBinary = content[i];
        }
    }

    return "6 b) Najwieksza liczba w zapisie binarnym: " + maxDecimal + "; Najwieksza liczba w zapisie dziesietnym: " + maxBinary;
}