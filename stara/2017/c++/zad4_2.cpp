#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad4_2()
{
    string line;
    vector<string> content;

    //wczytywanie danych z pliku
    fstream file("../dane/binarne.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();
}
