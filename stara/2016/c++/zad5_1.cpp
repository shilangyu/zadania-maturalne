#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<vector<string>> extend(char boardOriginal)
{
    char boardExtended[13][21]; // tablica rozszerzona o jeden wiersz i kolumnę, by pozbyć się problemu z zawijaniem

    int rowsExtended = sizeof boardExtended / sizeof boardExtended[0]; // ilość wierszy w rozszerzonej tablicy
    int colsExtended = sizeof boardExtended / rowsExtended;            // ilość kolumn w rozszerzonej tablicy

    for (int i = 0; i < rowsExtended; i++)
    {
        for (int j = 0; j < colsExtended; j++)
        {
            if (i != rowsExtended - 1)
            {
                if (j == colsExtended - 1)
                    boardExtended[i][j] = boardExtended[i][0];
                else
                    boardExtended[i][j] = boardOriginal[i][j];
            }
            else
            {
                if (j == colsExtended - 1)
                    boardExtended[i][j] = boardExtended[i][0];
                else
                    boardExtended[i][j] = boardOriginal[0][j];
            }
        }
    }

    return boardExtended;
}

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

    // char boardExtended[13][21]; // tablica rozszerzona o jeden wiersz i kolumnę, by pozbyć się problemu z zawijaniem

    // int rowsExtended = sizeof boardExtended / sizeof boardExtended[0]; // ilość wierszy w rozszerzonej tablicy
    // int colsExtended = sizeof boardExtended / rowsExtended;            // ilość kolumn w rozszerzonej tablicy

    // for (int i = 0; i < rowsExtended; i++)
    // {
    //     for (int j = 0; j < colsExtended; j++)
    //     {
    //         if (i != rowsExtended - 1)
    //         {
    //             if (j == colsExtended - 1)
    //                 boardExtended[i][j] = boardExtended[i][0];
    //             else
    //                 boardExtended[i][j] = boardOriginal[i][j];
    //         }
    //         else
    //         {
    //             if (j == colsExtended - 1)
    //                 boardExtended[i][j] = boardExtended[i][0];
    //             else
    //                 boardExtended[i][j] = boardOriginal[0][j];
    //         }
    //     }
    // }

    char boardExtended[13][21] = extend(boardOriginal);

    ofstream test("test.txt");

    for (int i = 0; i < rowsExtended; i++)
    {
        for (int j = 0; j < colsExtended; j++)
            test << boardExtended[i][j];

        test << endl;
    }

    return "";
}