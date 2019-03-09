#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    string line, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<string> content;
    int k = 107;

    fstream file("dane_6_1.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    for (int i = 0; i < content.size(); i++)
    {
        cout << alphabet.size() % k;
    }
}