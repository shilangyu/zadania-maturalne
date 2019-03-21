#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

string zad4_2()
{
    string line;
    vector<string> content;

    fstream file("../dane/slowa.txt");

    //wczytywanie danych z pliku
    if (file.is_open())
    {
        while (getline(file, line))
            content.push_back(line);
    }
    file.close();

    int howMany = 0;

    //przechodzenie po vectorze z zawartością
    for (int i = 0; i < content.size(); i++)
    {
        //przechodzimy dalej tylko jeśli pierwszym elementen stringa jest 0
        if (content[i][0] == '0')
        {
            bool switchedChar = false;

            //przechodzenie po pojedynczym stringu
            for (int j = 0; j < content[i].size(); j++)
            {
                //jeżeli po raz pierwszy zmienia się znak, zmieniamy wartość switchedChar na true
                if (content[i][j] == '1' and switchedChar == false)
                    switchedChar = true;

                //jeżeli znak zmienił się po raz kolejny wychodzimy z pętli
                if (content[i][j] == '0' and switchedChar)
                    break;

                //jeżeli jesteśmy na ostatnim przejściu oraz sprawdzimy, że wszystkie wymogi zostały spełnione,
                //dodajemy jeden do intigera howMany
                if (j == content[i].size() - 1 and switchedChar and content[i][j] == '1')
                    howMany++;
            }
        }
    }

    return "4.2. Liczb slow skladajacych sie z dwoch niepustych blokow zaczynajacych sie od zera: " + to_string(howMany);
}