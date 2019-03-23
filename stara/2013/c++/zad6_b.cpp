#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

//funkcja zmieniająca zapis ósemkowy na binarny
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

//funkcja zmieniajaca zapis binarny na dziesietny
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

    fstream file("../dane/dane.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int howMany = 0;

    //przechodzenie po zawartości pliku i sprawdzanie czy dany element w zapisie dziesiętny
    //spełnia warunki podane w poleceniu
    for (int i = 0; i < content.size(); i++)
    {
        string decimalElement = binaryToDecimal(octalToBinary(content[i]));

        if (decimalElement[0] == decimalElement[decimalElement.size() - 1])
            howMany++;
    }

    return "Liczba liczb, ktore w zapisie dziesietnym maja te sama cyfre na poczatku co na koncu: " + to_string(howMany);
}