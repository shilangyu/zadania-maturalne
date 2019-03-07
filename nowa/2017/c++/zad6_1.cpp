#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    string line;
    int min = 255, max = 0;

    fstream file("dane.txt");

    if (file.is_open()) {
        while (getline(file, line, ' ')) {
            int temporary = atoi(line.c_str());

			min = (temporary < min) ? min = temporary : min = min;
			max = (temporary > max) ? max = temporary : max = max;
        }
    }
    file.close();

    cout << "6.1 Wartosc najciemniejszego piksela: " << min << ", " << "wartosc najjasniejszego piksela: " << max << endl;

    system("PAUSE");
}