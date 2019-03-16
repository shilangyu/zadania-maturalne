#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad4_2()
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

    //szukanie słowa zawierającego najwięcej różnych znaków
    int globalMax = 0;
    int max = 0;
    int no = 0;
    string chosenOne;
    vector<char> word;
    vector<char> banned;

    //przechodzenie po zawartości pliku
    for (int i = 0; i < content.size(); i++)
    {
        //przechodzenie po danej linii
        for (int j = 0; j < content[i].size(); j++)
        {
            word.push_back(content[i][j]);
        }

        //sprawdzanie czy dana litera się nie powtórzyła
        for (int j = 0; j < content[i].size(); j++)
        {
            for (int k = 0; k < banned.size(); k++)
            {
                if (content[i][j] == banned[k])
                    no++;
            }

            //dodawanie 1 do max, jeżeli litera wcześniej się nie powtórzyła i dodawanie tej litery do vectora banned
            if (no == 0)
            {
                max++;
                banned.push_back(content[i][j]);
            }
            no = 0;
        }

        //sprawdzanie czy aktualne słowo ma więcej różnych znaków niż dotychczasowe rekordowe słowo
        if (max > globalMax)
        {
            globalMax = max;
            chosenOne = content[i];
        }

        //czyszczenie tymczasowych danych do ponownego użycia w następnym powtórzeniu pętli
        max = 0;
        word.clear();
        banned.clear();
    }

    return "4.2. Slowo, w ktorym wystepuje najwiecej roznych znakow: " + chosenOne + "; Liczba roznych znakow: " + to_string(globalMax);
}
