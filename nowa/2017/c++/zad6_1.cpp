#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

string zad6_1()
{
    string line;
    int min = 255, max = 0;
    vector<string> content;

    fstream file("../dane/dane.txt");

    if (file.is_open())
    {
        while (getline(file, line, ' '))
            content.push_back(line);
    }
    file.close();

    for (int i = 0; i < content.size(); i++)
    {
        int temporary = atoi(content[i].c_str());

        if (temporary < min)
            min = temporary;
        if (temporary > max)
            max = temporary;
    }

    return "6.1) Wartosc najciemniejszego piksela: " + to_string(min) + "; " + "wartosc najjasniejszego piksela: " + to_string(max);
}