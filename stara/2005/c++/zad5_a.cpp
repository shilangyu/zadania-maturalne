#include <iostream>
#include <vector>
using namespace std;

string zad5_a()
{
    vector<int> data = {1, -2, 6, -5, 7, -3};
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

    return "5 a) Najlepsza suma podanego ciagu: " + to_string(max);
}
