#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string zad6_3()
{
    string line;
    vector<string> content;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

    fstream file("../dane/dane_6_3.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }

    return "";
}