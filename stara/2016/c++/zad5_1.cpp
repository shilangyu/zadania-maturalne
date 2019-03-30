#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> extend(vector<string> original)
{
    string top = original[0], bottom = original[original.size() - 1];

    top = top[top.size() - 1] + top + top[0];
    bottom = bottom[bottom.size() - 1] + bottom + bottom[0];

    vector<string> extended;

    for (int i = 0; i < original.size() + 2; i++)
    {
        if (i == 0)
            extended.push_back(bottom);
        else if (i == original.size() + 1)
            extended.push_back(top);
        else
            extended.push_back(original[i - 1][original.size() - 1] + original[i - 1] + original[i - 1][0]);
    }

    return extended;
}

bool isAlive(char cell, string neighbours)
{
    int counter = 0;

    for (int i = 0; i < neighbours.size(); i++)
    {
        if (neighbours[i] == 'X')
            counter++;
    }

    if (cell == 'X')
    {
        if (counter == 2 or counter == 3)
            return true;
        else
            return false;
    }
    else
    {
        if (counter == 3)
            return true;
        else
            return false;
    }
}

vector<string> nextGeneration(vector<string> boardOriginal, vector<string> boardExtended)
{
    vector<string> boardNew;

    for (int i = 1; i < boardExtended.size() - 1; i++)
    {
        string readyToPush = "";

        for (int j = 1; j < boardExtended[i].size() - 1; j++)
        {
            string neighbours = "";

            neighbours += boardExtended[i - 1][j - 1];
            neighbours += boardExtended[i - 1][j];
            neighbours += boardExtended[i - 1][j + 1];
            neighbours += boardExtended[i][j + 1];
            neighbours += boardExtended[i + 1][j + 1];
            neighbours += boardExtended[i + 1][j];
            neighbours += boardExtended[i + 1][j - 1];
            neighbours += boardExtended[i][j - 1];

            if (isAlive(boardExtended[i][j], neighbours))
                readyToPush += 'X';
            else
                readyToPush += '.';
        }

        boardNew.push_back(readyToPush);
    }

    return boardNew;
}

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

    cout << "before functions";

    vector<string> secondGen = nextGeneration(boardOriginal, extend(boardOriginal));

    cout << "after functions";

    ofstream test("test.txt");

    for (int i = 0; i < secondGen.size(); i++)
        test << secondGen[i] << endl;

    return "";
}