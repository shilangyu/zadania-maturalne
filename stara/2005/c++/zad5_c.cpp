#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// funkcja wczytujaca dane z pliku
vector<int> loadData1(string path)
{
    string line;
    vector<int> data;

    fstream stream(path);

    if (stream.is_open())
    {
        while (getline(stream, line))
            data.push_back(atoi(line.c_str()));
    }
    stream.close();

    return data;
}

// funkcja sprawdzajaca jaki element wystepuje najczesciej w danym vectorze
int mostCommon(vector<int> data)
{
    int mostCommon;
    int max = 0;

    for (int i = 0; i < data.size() - 1; i++)
    {
        int currentOccurrene = 0;

        for (int j = 0; j < data.size() - 1; j++)
        {
            if (data[i] == data[j])
                currentOccurrene++;
        }

        if (currentOccurrene > max)
        {
            max = currentOccurrene;
            mostCommon = data[i];
        }
    }

    return mostCommon;
}

string zad5_c()
{
    // sprawdzanie jaki element wystepuje najczesciej w poszczegolnych plikach
    int mostCommonOne = mostCommon(loadData1("../dane/dane5-1.txt"));
    int mostCommonTwo = mostCommon(loadData1("../dane/dane5-2.txt"));
    int mostCommonThree = mostCommon(loadData1("../dane/dane5-3.txt"));

    return "5 c) Najczesciej wystepujacy element w pliku dane5-1.txt: " + to_string(mostCommonOne) +
           "; Najczesciej wystepujacy element w pliku dane5-2.txt: " + to_string(mostCommonTwo) +
           "; Najczesciej wystepujacy element w pliku dane5-3.txt: " + to_string(mostCommonThree);
}
