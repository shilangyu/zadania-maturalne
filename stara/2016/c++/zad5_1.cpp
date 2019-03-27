#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> extend(vector<string> original)
{
    string top = original[0], bottom = original[original.size() - 1];

    return original;
}

// vector<string> nextGeneration(vector<string> board)
// {
//     for (int i = 0; i < board.size(); i++)
//     {
//     }

//     return board;
// }

string zad5_1()
{
    string line;

    vector<string> boardOriginal;

    fstream file("../dane/gra.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            boardOriginal.push_back(line);
    }
    file.close();

    vector<string> boardExtended = extend(boardOriginal);

    ofstream test("test.txt");

    for (int i = 0; i < boardExtended.size(); i++)
        test << boardExtended[i] << endl;

    return "";
}