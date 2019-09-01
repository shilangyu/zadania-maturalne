#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// funkcja zwracajaca najwieksza sume
int biggestSum1(vector<int> data)
{
    int max = -9999;

    for (int i = 0; i < data.size() - 1; i++)
    {
        int sum = 0;

        for (int j = i; j < data.size() - 1; j++)
        {
            sum += data[j];

            if (sum > max)
                max = sum;
        }
    }

    return max;
}

// funkcja wczytujaca dane z pliku
vector<int> loadData(string path)
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

string zad5_b()
{
    // liczenie najwiekszych sum dla trzech plikow
    int sumOne = biggestSum1(loadData("../dane/dane5-1.txt"));
    int sumTwo = biggestSum1(loadData("../dane/dane5-2.txt"));
    int sumThree = biggestSum1(loadData("../dane/dane5-3.txt"));

    return "5 b) Najwieksza suma z pliku dane5-1.txt: " + to_string(sumOne) +
           "; 5 b) Najwieksza suma z pliku dane5-2.txt: " + to_string(sumTwo) +
           "; 5 b) Najwieksza suma z pliku dane5-3.txt: " + to_string(sumThree);
}
