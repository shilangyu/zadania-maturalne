#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> extend(vector<string> original)
{
    vector<string> extended = original;

    for (int i = 0; i < extended.size(); i++)
        extended[i] += extended[i][0];

    extended.push_back(extended[0]);

    extended[extended.size() - 1][extended[extended.size() - 1].size() - 1] = extended[0][0];

    return extended;
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

    vector<string> boardExtended = extend(boardOriginal);

    ofstream test("test.txt");

    for (int i = 0; i < boardExtended.size(); i++)
        test << boardExtended[i] << endl;

    return "";
}