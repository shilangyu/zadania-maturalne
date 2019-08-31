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

// funkcja zwracajaca najwiekszy wspolny dzielnik, pozwala ustalic wartosc limitu, najwiekszy wspolny dzielnik musi byc mniejszy niz limit
int biggestCommonDivisor(vector<int> divisors1, vector<int> divisors2, int limit, bool isLimit)
{
    for (int i = divisors1.size() - 1; i >= 0; i--)
    {
        for (int j = divisors2.size() - 1; j >= 0; j--)
        {
            if (isLimit)
            {
                if (divisors1[i] == divisors2[j] and divisors1[i] < limit)
                    return divisors1[i];
            }
            else
            {
                if (divisors1[i] == divisors2[j])
                    return divisors1[i];
            }
        }
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
    fstream file("../dane/liczby.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            numbers.push_back(atoi(line.c_str()));
    }
    file.close();

    vector<int> legacyDivisors;
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

            legacyDivisors = divisors(numbers[i]);
            currentSeries.push_back(numbers[i]);
            allDivisors.push_back(legacyDivisors);
            startAgain = false;
        }
        else
        {
            vector<int> currentDivisors = divisors(numbers[i]);

            // przypisywanie nowej wartosci najwiekszego dzielnika, jezeli dany ciag dopiero zyskuje drugi element
            if (currentSeries.size() == 1)
                biggestDivisor = biggestCommonDivisor(legacyDivisors, currentDivisors, 0, false);

            // dodawanie kolejnego elementu do ciagu, jezeli najwiekszy dzielnik nie ulega zmianie
            if (biggestDivisor != 0 and
                biggestDivisor != 1 and
                numbers[i] % biggestDivisor == 0)
            {
                currentSeries.push_back(numbers[i]);
                allDivisors.push_back(currentDivisors);
            }
            // dodawanie kolejnego elementu ciagu, jezeli najwiekszy dzielnik ulega zmianie
            else if (biggestDivisor != 0 and
                     biggestDivisor != 1 and
                     biggestCommonDivisor(legacyDivisors, currentDivisors, biggestDivisor, true) != 1 and
                     isInAll(allDivisors, biggestCommonDivisor(legacyDivisors, currentDivisors, biggestDivisor, true)))
            {
                biggestDivisor = biggestCommonDivisor(legacyDivisors, currentDivisors, biggestDivisor, true);
                currentSeries.push_back(numbers[i]);
                allDivisors.push_back(currentDivisors);
            }
            else
            {
                // jezeli ciag, ktory wlasnie sie skonczyl jest najdluzszym do tej pory,
                // zapisujemy jego dane w tablicy "parameters"
                if (currentSeries.size() > maxLength and currentSeries.size() > 1)
                {
                    parameters[0] = currentSeries[0];
                    parameters[1] = currentSeries.size();
                    parameters[2] = biggestDivisor;
                    maxLength = currentSeries.size();
                }

                // zapobieganie nieskonczonej petli, sprawdzam czy ma sens sprawdzac czy pierwszy element nowego ciagu moze byc
                // ostatnim elementem poprzedniego
                if (biggestCommonDivisor(currentDivisors, divisors(numbers[i - 1]), 0, false) > 1)
                    i -= 1;

                // czyszczenie aktualnego ciagu oraz wszystkich dzielnikow tego ciagu
                currentSeries.clear();
                allDivisors.clear();

                startAgain = true;
            }
        }
    }

    return "4.3. Pierwszy element ciagu: " + to_string(parameters[0]) + "; Dlugosc ciagu: " + to_string(parameters[1]) + "; Najwiekszy dzielnik wszystkich elementow: " + to_string(parameters[2]);
}
