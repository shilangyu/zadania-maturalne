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

// funkcja sprawdzajaca czy dany int wystepuje w kazdym vectorze
bool isInAll(vector<vector<int>> collection, int number)
{
    for (int i = 0; i < collection.size(); i++)
    {
        bool inOne = false;

        for (int j = 0; j < collection[i].size(); j++)
        {
            if (collection[i][j] == number)
            {
                inOne = true;
                break;
            }
        }

        if (inOne == false)
            return false;
    }

    return true;
}

string zad4_3()
{
    string line;
    vector<int> numbers;

    // wczytywanie danych z pliku
    fstream file("../dane/przyklad.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            numbers.push_back(atoi(line.c_str()));
    }
    file.close();

    vector<int> previousDivisors;
    vector<int> currentSeries;
    vector<vector<int>> allDivisors;
    bool startAgain = false;
    int maxLength = 0;
    int parameters[3];
    int biggestDivisor = 0;

    // przechodzenie po kazdym elemencie
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i == 0 or startAgain)
        {
            // zmniejszam "i" o 1, poniewaz pierwszy element wlasciwego ciagu moze byc ostatnim elementem poprzedniego
            if (startAgain)
                i -= 1;

            previousDivisors = divisors(numbers[i]);
            currentSeries.push_back(numbers[i]);
            allDivisors.push_back(previousDivisors);
            startAgain = false;
        }
        else
        {
            vector<int> currentDivisors = divisors(numbers[i]);

            if (currentSeries.size() == 1)
            {
                biggestDivisor = biggestCommonDivisor(previousDivisors, currentDivisors);
            }

            if (biggestDivisor != 0 and biggestDivisor != 1 and numbers[i] % biggestDivisor == 0)
            {
                currentSeries.push_back(numbers[i]);
                allDivisors.push_back(currentDivisors);
            }
            else if (biggestDivisor != 0 and biggestDivisor != 1 and biggestCommonDivisor(previousDivisors, currentDivisors) != 1 and isInAll(allDivisors, biggestDivisor))
            {
                biggestDivisor = biggestCommonDivisor(previousDivisors, currentDivisors);
                currentSeries.push_back(numbers[i]);
            }
            else
            {
                if (currentSeries.size() > maxLength and currentSeries.size() > 1)
                {
                    parameters[0] = currentSeries[0];
                    parameters[1] = currentSeries.size();
                    parameters[2] = biggestCommonDivisor(divisors(currentSeries[0]), divisors(currentSeries[1]));
                    maxLength = currentSeries.size();
                }

                currentSeries.clear();
                startAgain = true;
            }
        }
    }

    return to_string(parameters[0]) + "\n" + to_string(parameters[1]) + "\n" + to_string(parameters[2]);
}
