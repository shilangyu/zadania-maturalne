#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string zad5_c()
{
    string line;
    vector<string> content;

    // wczytywanie danych z pliku
    fstream file("../dane/NAPIS.TXT");

    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    vector<string> goodOnes;

    // przechodzenie po contencie
    for (int i = 0; i < content.size(); i++)
    {
        int howMany = 0;

        // przechodzenie drugi raz po contencie, zeby sprawdzic czy powtarza sie drugi raz ten sam napis
        for (int j = 0; j < content.size(); j++)
        {
            bool go = true;

            // sprawdzanie czy aktualne slowo bylo juz wczesniej dodane do vectora z odpowiedziami
            for (int k = 0; k < goodOnes.size(); k++)
            {
                if (goodOnes[k] == content[i])
                    go = false;
            }

            // jezeli nie bylo, to dodajemy do vectora goodOnes
            if (go)
            {
                if (content[i] == content[j])
                    howMany++;
            }
        }

        if (howMany > 1)
            goodOnes.push_back(content[i]);
    }

    // zapisywanie odpowiedzi do stringa
    string answer = "\n";

    for (int i = 0; i < goodOnes.size(); i++)
        answer += goodOnes[i] + "\n";

    return "5 c) Napisy, ktore wystepuja wiecej niz jeden raz: " + answer;
}
