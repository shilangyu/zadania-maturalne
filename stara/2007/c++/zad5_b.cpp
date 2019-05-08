#include <iostream>
#include <string>
using namespace std;

// funkcja sprawdzajaca czy dana liczba jest liczba pierwsza
bool isPrime1(int number)
{
    if (number <= 1)
    {
        return false;
    }
    
    if (number <= 3)
    {
        return true;
    }

    if (number % 2 == 0 or number % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i < number + 6; i += 6)
    {
        if (i * i > number)
        {
            break;
        }

        if (number % i == 0 or number % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

// funkcja zmieniajaca liczbe w zapisie dziesietnym na zapis dwojkowy
string decimalToBinary1(int number)
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
bool isSuperBPrime1(int number)
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

string zad5_b()
{
    int howMany = 0;

    // odpowiedz na pierwsza czesc pytania
    for (int i = 100; i < 10000; i++)
    {
        int sum = 0;

        for (int j = 0; j < to_string(i).size(); j++)
        {
            sum += to_string(i)[j] - '0';
        }

        if (isPrime1(sum))
        {
            howMany++;
        }
    }

    int bPrimeSum = 0;

    //odpowiedz na druga czesc pytania
    for (int i = 100; i < 10000; i++)
    {
        if (isSuperBPrime1(i))
        {
            bPrimeSum += i;
        }
    }

    string answer = "";

    if (isSuperBPrime1(bPrimeSum))
    {
        answer += "jest";
    }
    else
    {
        answer += "nie jest";
    }

    return "5 b) Liczba liczb w przedziale <100;10000>: " + to_string(howMany) + "; Suma wszystkich liczb B z tego samego przedzialu " + 
    answer + " liczba B pierwsza";
}
