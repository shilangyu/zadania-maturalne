#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

// funkcja poszerzajaca oryginalna tablice, potocznie mowiac "dokleja ramki" dookola tablicy
vector<string> extend2(vector<string> original)
{
    string top = "", bottom = "";

    // tworzenie calych wierszy (gornego i dolnego), gotowych do uzycia w rozszerzonej tablicy
    top += original[0][original[0].size() - 1] + original[0] + original[0][0];
    bottom += original[original.size() - 1][original[original.size() - 1].size() - 1] + original[original.size() - 1] + original[original.size() - 1][0];

    vector<string> extended;

    // dodaje na poczatek dolny wiersz do rozszerzonej tablicy
    extended.push_back(bottom);

    // teraz dodaje cala dalsza zawartosc, oprocz ostatniego wiersza
    for (int i = 0; i < original.size(); i++)
        extended.push_back(original[i][original[i].size() - 1] + original[i] + original[i][0]);

    // na koniec dodaje wiersz z gory na sam dol i zwracam gotowy vector
    extended.push_back(top);

    return extended;
}

// funkcja sprawdzajaca czy dana komorka bedzie zywa w nastepnej generacji
bool isAlive2(char cell, string neighbours)
{
    int counter = 0;

    for (int i = 0; i < neighbours.size(); i++)
    {
        if (neighbours[i] == 'X')
            counter++;
    }

    if (cell == 'X')
    {
        if (counter == 2 or counter == 3)
            return true;
        else
            return false;
    }
    else
    {
        if (counter == 3)
            return true;
        else
            return false;
    }
}

// funkcja generujaca vector z nastepna generacja komorek
vector<string> nextGeneration2(vector<string> boardOriginal, vector<string> boardExtended)
{
    vector<string> boardNew;

    // przechodzenie po rozszerzonym vectorze, ale biorac pod uwage tylko te czesc
    // ktora byla dostepna w oryginale
    for (int i = 1; i < boardExtended.size() - 1; i++)
    {
        string readyToPush = "";

        // sprawdzanie "sasiadow" poszczegolnej komorki w wierszu
        for (int j = 1; j < boardExtended[i].size() - 1; j++)
        {
            string neighbours = "";

            // sprawdzanie po boardExtended, by uniknac wyjscia poza indeks
            neighbours += boardExtended[i - 1][j - 1];
            neighbours += boardExtended[i - 1][j];
            neighbours += boardExtended[i - 1][j + 1];
            neighbours += boardExtended[i][j + 1];
            neighbours += boardExtended[i + 1][j + 1];
            neighbours += boardExtended[i + 1][j];
            neighbours += boardExtended[i + 1][j - 1];
            neighbours += boardExtended[i][j - 1];

            // sprawdzanie czy dana komorka bedzie zywa w nastepnej generacji
            if (isAlive2(boardExtended[i][j], neighbours))
                readyToPush += 'X';
            else
                readyToPush += '.';
        }

        // dodawanie do vectora wiersz dalszy o jedna generacje
        boardNew.push_back(readyToPush);
    }

    return boardNew;
}

string zad5_2()
{
    string line;

    vector<string> boardOriginal;

    fstream file("../dane/gra.txt");

    // wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            boardOriginal.push_back(line);
    }
    file.close();

    // wywolywanie funkcji jeden raz, przechodzac do drugiej generacji
    boardOriginal = nextGeneration2(boardOriginal, extend2(boardOriginal));

    // przechodzenie po planszy w drugiej generacji i zliczanie zywych komorek
    int howManyAlive = 0;

    for (int i = 0; i < boardOriginal.size(); i++)
    {
        for (int j = 0; j < boardOriginal[i].size(); j++)
        {
            if (boardOriginal[i][j] == 'X')
                howManyAlive++;
        }
    }

    return "5.2. Liczba zywych komorek w drugiej generacji: " + to_string(howManyAlive);
}
