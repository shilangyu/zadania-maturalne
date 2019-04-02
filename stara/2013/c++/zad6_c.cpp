#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//funkcja sprawdzająca czy dany string spełnia warunki podane w zadaniu
bool isNotShrinking(string number)
{
    for (int i = 1; i < number.size(); i++)
    {
        if (number[i - 1] > number[i])
            return false;
    }

    return true;
}

//funkcja zmieniająca zapis ósemkowy na binarny
string octalToBinary1(string line)
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

string zad6_c()
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

    vector<string> goodOnes;

    //dodawanie elementów, które spełniają warunki zadania do vectora goodOnes
    for (int i = 0; i < content.size(); i++)
    {
        if (isNotShrinking(content[i]))
            goodOnes.push_back(content[i]);
    }

    //sprawdzanie min i max i zapisywanie dwóch wersji tej samej liczby (w systemie ósemkowym i dziesiętnym)
    int max = 0, min = 10000;
    string minNumberDecimal, maxNumberDecimal, minNumberOctal, maxNumberOctal;

    for (int i = 0; i < goodOnes.size(); i++)
    {
        if (atoi(binaryToDecimal1(octalToBinary1(goodOnes[i])).c_str()) > max)
        {
            max = atoi(binaryToDecimal1(octalToBinary1(goodOnes[i])).c_str());
            maxNumberDecimal = binaryToDecimal1(octalToBinary1(goodOnes[i]));
            maxNumberOctal = goodOnes[i];
        }

        if (atoi(binaryToDecimal1(octalToBinary1(goodOnes[i])).c_str()) < min)
        {
            min = atoi(binaryToDecimal1(octalToBinary1(goodOnes[i])).c_str());
            minNumberDecimal = binaryToDecimal1(octalToBinary1(goodOnes[i]));
            minNumberOctal = goodOnes[i];
        }
    }

    return "6 c) Liczba liczb spelniajaca warunki zadania: " + to_string(goodOnes.size()) + "; " + "Najwieksza liczba w osemkowym: " + maxNumberOctal + "; " + "Najmniejsza liczba w osemkowym:" + minNumberOctal + "; " + "Najwieksza liczba w dziesietnym: " + maxNumberDecimal + "; " + "Najmniejsza liczba w dziesietnym: " + minNumberDecimal;
}