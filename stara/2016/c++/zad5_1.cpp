#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> extend(vector<string> original)
{
    string top = original[0], bottom = original[original.size() - 1], left = "", right = "";

    for (int i = 0; i < original.size(); i++)
    {
        left += original[i][0];
        right += original[i][original[i].size() - 1];
    }

    top = top[top.size() - 1] + top + top[0];
    bottom = bottom[bottom.size() - 1] + bottom + bottom[0];

    left = left[left.size() - 1] + left + left[0];
    right = right[right.size() - 1] + right + right[0];

    vector<string> extended;

    for (int i = 0; i < original.size() + 2; i++)
    {
        if (i == 0)
            extended.push_back(bottom);
        else if (i == original.size() + 1)
            extended.push_back(top);
        else
        {
            extended.push_back(original[i - 1][original.size() - 1] + original[i - 1] + original[i - 1][0]);
        }
    }

    return extended;
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