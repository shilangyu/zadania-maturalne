#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy dana liczba jest potega liczby 3
bool isPowerOfThree(int number)
{
    while (number % 3 == 0)
        number /= 3;

    if (number == 1)
        return true;
    else
        return false;
}

string zad4_1()
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

    int answer = 0;

    // przechodzenie po wszystkich danych nam liczbach i sprawedzanie czy sa potegami 3
    for (int i = 0; i < numbers.size(); i++)
    {
        if (isPowerOfThree(numbers[i]))
            answer++;
    }

    return "4.1. Liczba elementow, ktore sa potegami 3: " + to_string(answer);
}
