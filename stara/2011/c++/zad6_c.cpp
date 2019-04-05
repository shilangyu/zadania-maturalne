#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// funkcja zamieniająca liczbę zapisaną w systemie binarnym na zapis dziesiętny
string binaryToDecimal1(string line)
{
    int output = 0;

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (line[line.size() - i - 1] == '1')
            output += pow(2, i);
    }

    return to_string(output);
}

string zad6_c()
{
    string line;
    vector<string> content;

    fstream file("../dane/liczby.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> nines;
    vector<string> ninesDecimal;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() == 9)
        {
            nines.push_back(content[i]);
            ninesDecimal.push_back(binaryToDecimal1(content[i]));
        }
    }

    int sum = 0;

    for (int i = 0; i < ninesDecimal.size(); i++)
        sum += atoi(ninesDecimal[i].c_str());

    return to_string(sum);
}