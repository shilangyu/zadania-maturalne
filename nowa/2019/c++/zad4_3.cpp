#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// funkcja zwracajace vector z wszystkimi dzielnikami danej liczby
vector<int> divisors(int number)
{
    vector<int> divisors;

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            divisors.push_back(i);
    }

    return divisors;
}

// funkcja zwracajaca najwiekszy wspolny dzielnik
int biggestCommonDivisor(vector<int> divisors1, vector<int> divisors2)
{
    for (int i = divisors1.size() - 1; i >= 0; i--)
    {
        for (int j = divisors2.size() - 1; j >= 0; j--)
            if (divisors1[i] == divisors2[j])
                return divisors1[i];
    }

    return 1;
}

string zad4_3()
{
    string line;
    vector<int> numbers;

    // wczytywanie danych z pliku
    fstream file("../dane/liczby.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            numbers.push_back(atoi(line.c_str()));
    }
    file.close();

    vector<int> previousDivisors;
    vector<int> currentSeries;
    bool startAgain = false;
    int maxLength = 0;
    int parameters[3];

    // przechodzenie po kazdym elemencie
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i == 0 or startAgain)
        {
            previousDivisors = divisors(numbers[i]);
            currentSeries.push_back(numbers[i]);
            startAgain = false;
        }
        else
        {
            vector<int> currentDivisors = divisors(numbers[i]);

            if (biggestCommonDivisor(previousDivisors, currentDivisors) != 1)
                currentSeries.push_back(numbers[i]);
            else
            {
                if (currentSeries.size() > maxLength)
                {
                    parameters[0] = currentSeries[0];
                    parameters[1] = currentSeries.size();
                    parameters[2] = biggestCommonDivisor(divisors(currentSeries[0]), divisors(currentSeries[1]));
                }

                currentSeries.clear();
                startAgain = true;
            }
        }
    }

    return to_string(parameters[0]) + "\n" + to_string(parameters[1]) + "\n" + to_string(parameters[2]);
}
