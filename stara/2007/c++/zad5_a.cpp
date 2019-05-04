#include <iostream>
#include <string>
#include <vector>
using namespace std;

// funkcja sprawdzajaca czy dana liczba jest liczba pierwsza
bool isPrime(int number)
{
    int counter = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            counter++;
    }

    if (counter == 1)
        return true;
    else
        return false;
}

// funkcja zmieniajaca liczbe w zapisie dziesietnym na zapis dwojkowy
string decimalToBinary(int number)
{
    string binaryReverse = "", output = "";

    while (number != 0)
    {
        binaryReverse += to_string(number % 2);

        number = number / 2;
    }

    // odwracanie zapisu binarnego
    for (int i = binaryReverse.size() - 1; i >= 0; i--)
        output += binaryReverse[i];

    return output;
}

// funkcja sprawdzajaca czy dana liczba jest liczba B pierwsza
bool isSuperBPrime(int number)
{
    // sprawdzanie czy jest liczba pierwsza
    if (isPrime(number))
    {
        string numberS = to_string(number);
        int sum = 0;

        for (int i = 0; i < numberS.size(); i++)
        {
            sum += numberS[i] - '0';
        }

        // sprawdzanie czy suma cyfr jest liczba pierwsza
        if (isPrime(sum))
        {
            string numberBinary = decimalToBinary(number);
            sum = 0;

            for (int i = 0; i < numberBinary.size(); i++)
            {
                sum += numberBinary[i] - '0';
            }

            // sprawdzanie czy suma liczb zapisu binarnego jest liczba pierwsza
            if (isPrime(sum))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

string zad5_a()
{
    vector<int> first, second, third;

    // sprawdzanie ilosci liczb super B pierwszych w przedziale <2;1000>
    for (int i = 2; i <= 1000; i++)
    {
        if (isSuperBPrime(i))
        {
            first.push_back(i);
        }
    }

    //sprawdzanie ilosci liczb super B pierwszych w przedziale <100;10000>
    for (int i = 100; i <= 10000; i++)
    {
        if (isSuperBPrime(i))
        {
            second.push_back(i);
        }
    }

    // sprawdzanie ilosci liczb super B pierwszych w przedziale <1000; 100000>
    for (int i = 1000; i <= 100000; i++)
    {
        if (isSuperBPrime(i))
        {
            third.push_back(i);
        }
    }

    string answer = "5 a) Liczba liczb super B pierwszych w przedziale <2;1000>: " + to_string(first.size()) + " Lista tych liczb:\n";

    for (int i = 0; i < first.size(); i++)
    {
        answer += to_string(first[i]) + "\n";
    }

    answer += "Liczba liczb super B pierwszych w przedziale <100;10000>: " + to_string(second.size()) + " Lista tych liczb:\n";

    for (int i = 0; i < second.size(); i++)
    {
        answer += to_string(second[i]) + "\n";
    }

    answer += "Liczba liczb super B pierwszych w przedziale <1000;100000>: " + to_string(third.size()) + " Lista tych liczb:\n";

    for (int i = 0; i < third.size(); i++)
    {
        answer += to_string(third[i]) + "\n";
    }

    return answer;
}
