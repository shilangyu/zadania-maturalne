#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string zad5_1()
{
    string line;
    char boardOriginal[12][20];

    fstream file("../dane/gra.txt");

    //wczytywanie danych z pliku do dwuwymiarowej tablicy
    if (file.is_open())
    {
        int j = 0;

        while (getline(file, line))
        {
            for (int i = 0; i < line.size(); i++)
                boardOriginal[j][i] = line[i];

            j++;
        }
    }
    file.close();

    int rowsOriginal = sizeof boardOriginal / sizeof boardOriginal[0]; // ilość wierszy w oryginalnej tablicy
    int colsOriginal = sizeof boardOriginal / rowsOriginal;            // ilość kolumn w oryginalnej tablicy

    char boardExtended[13][21];

    int rowsExtended = sizeof boardExtended / sizeof boardExtended[0]; // ilość wierszy w rozszerzonej tablicy
    int colsExtended = sizeof boardExtended / rowsExtended;            // ilość kolumn w rozszerzonej tablicy

    return "";
}