#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string zad4_2()
{
    string line;
    vector<string> content;

    fstream file("../dane/liczby.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    //sprawdzanie czy liczba zapisana w binarce jest podzielna przez dwa lub osiem
    //1. Liczba binarna jest podzielna przez dwa, jeśli na końcu znajduje się '0'
    //2. Liczba binarna jest podzielna przez osiem, jeśli trzy ostatnie znaki są zerami
    int dividedByTwo = 0, dividedByEight = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][content[i].size() - 1] == '0')
        {
            dividedByTwo++;

            if (content[i][content[i].size() - 2] == '0' and content[i][content[i].size() - 3] == '0')
                dividedByEight++;
        }
    }

    return "4.2. Liczb liczb podzielnych przez dwa: " + to_string(dividedByTwo) + "; Liczba liczb podzielnych przez osiem: " + to_string(dividedByEight);
}