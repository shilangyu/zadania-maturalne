#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//funkcja zamieniająca zapis w systemie ósemkowym na zapis binarny
string octalToBinary(string line)
{
    string result = "";

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '0')
            result += "000";
        else if (line[i] == '1')
            result += "001";
        else if (line[i] == '2')
            result += "010";
        else if (line[i] == '3')
            result += "011";
        else if (line[i] == '4')
            result += "100";
        else if (line[i] == '5')
            result += "101";
        else if (line[i] == '6')
            result += "110";
        else if (line[i] == '7')
            result += "111";
    }

    return result;
}

//funkcja zamieniająca zapis binarny na zapis w systemie dziesiętnym
int binaryToDecimal(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);
    }

    return output;
}

string zad6_a()
{
    string line;
    vector<string> content;

    fstream file("../dane/dane.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int howMany = 0;

    for (int i = 0; i < content.size(); i++)
    {
    }

    return to_string(howMany);
}