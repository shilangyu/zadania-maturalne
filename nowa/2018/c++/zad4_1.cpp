#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad4_1()
{
    string line;
    vector<string> content;
    fstream file("../dane/sygnaly.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    string answer = "";

    //przechodzenie po zawartości pliku
    for (int i = 0; i < content.size(); i++)
    {
        //sprawdzanie czy znajdujemy się w linii o numerze podzielnym przez 40
        if ((i + 1) % 40 == 0)
            answer += content[i][9];
    }

    return answer;
}
