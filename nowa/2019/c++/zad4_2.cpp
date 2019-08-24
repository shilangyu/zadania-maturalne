#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// funkcja liczaca sume silni cyfr danej liczby
int sumOfFactorials(string number)
{
    int sum = 0;

    for (int i = 0; i < number.size(); i++)
    {
        int currentDigit = 1;

        for (int j = 1; j <= number[i] - '0'; j++)
            currentDigit *= j;

        sum += currentDigit;
    }

    return sum;
}

string zad4_2()
{
    string line;
    vector<string> numbers;

    // wczytywanie danych z pliku
    fstream file("../dane/liczby.txt");

    if (file.is_open())
    {
        while (getline(file, line))
            numbers.push_back(line);
    }
    file.close();

    string answer = "";

    for (int i = 0; i < numbers.size(); i++)
    {
        // jezeli liczba jest rowna sumie silni swoich cyfr, dodajemy te liczbe do stringa z odpowiedzia
        if (atoi(numbers[i].c_str()) == sumOfFactorials(numbers[i]))
            answer += numbers[i] + "\n";
    }

    return "4.2. Liczby, ktore rowna sa sumie siln swoich cyfr: \n" + answer;
}
