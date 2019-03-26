#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

string zad5_1()
{
    string line;
    char board[12][20];

    fstream file("../dane/gra.txt");

    if (file.is_open())
    {
        int j = 0;

        while (getline(file, line))
        {
            for (int i = 0; i < line.size(); i++)
                board[j][i] = line[i];

            j++;
        }
    }
    file.close();

    int rows = sizeof board / sizeof board[0]; // ilość wierszy
    int cols = sizeof board / rows;            // ilość kolumn

    ofstream test("test.txt");

    return "";
}