#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string zad4_3()
{
    string line;
    vector<string> content;

    fstream file("../dane/liczby.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int maxInRow = 0, currentMaxInRow = 0;

    //szukanie maksymalnego ciągu jedynek znajdującego się z przodu liczby
    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            if (content[i][j] == '1')
                currentMaxInRow++;
            else
                break;
        }

        if (currentMaxInRow > maxInRow)
            maxInRow = currentMaxInRow;

        currentMaxInRow = 0;
    }

    //znajdowanie liczby odpowiadającej za rozmiar najdłuższej liczby/liczb
    int maxLength = 0;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() > maxLength)
            maxLength = content[i].size();
    }

    //wyodrębnianie najdłuższych liczb
    vector<string> firstSort;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i].size() == maxLength)
            firstSort.push_back(content[i]);
    }

    //wyodrębnianie tych liczb, które mają maksymalnej długości ciąg składający się z jedynek z przodu liczby
    vector<string> secondSort;

    for (int i = 0; i < firstSort.size(); i++)
    {
        for (int j = 0; j < firstSort[i].size(); j++)
        {
            if (firstSort[i][j] == '1')
                currentMaxInRow++;
            else
                break;
        }

        if (currentMaxInRow == maxInRow)
            secondSort.push_back(firstSort[i]);

        currentMaxInRow = 0;
    }

    for (int i = 0; i < firstSort.size(); i++)
    {
    }

    return "";
}