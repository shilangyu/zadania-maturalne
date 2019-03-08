#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

//funckja sprawdzająca czy piksele kontrastują ze sobą zwracająca bool
bool isContrasting(int first, int second)
{
	bool output = false;

	if (first > second)
	{
		if (first - second > 128)
			output = true;
	}
	else if (second - first > 128)
		output = true;

	return output;
}

string zad6_3()
{
	fstream file("../dane/dane.txt");

	string board[200][320], element;
	int width = 0, height = 0;

	if (file.is_open())
	{
		while (getline(file, element))
		{
			stringstream ss(element);
			while (getline(ss, element, ' '))
			{
				board[height][width] = element;
				width++;
			}

			height++;
			width = 0;
		}
	}
	file.close();

	//3.
	int howManyContrastingPixels = 0, checker = 0;

	for (int h = 0; h < 200; h++)
	{
		for (int w = 0; w < 320; w++)
		{
			int primeValue = atoi(board[h][w].c_str());

			//sprawdzanie czy istnieje piksel po lewej stronie
			if (w != 0)
			{
				if (isContrasting(primeValue, atoi(board[h][w - 1].c_str())))
					checker++;
			}

			//sprawdzanie czy istnieje piksel po prawej stronie
			if (w != 319)
			{
				if (isContrasting(primeValue, atoi(board[h][w + 1].c_str())))
					checker++;
			}

			//sprawdzanie czy istnieje piksel na górze
			if (h != 0)
			{
				if (isContrasting(primeValue, atoi(board[h - 1][w].c_str())))
					checker++;
			}

			//sprawdzanie czy istnieje piksel na dole
			if (h != 199)
			{
				if (isContrasting(primeValue, atoi(board[h + 1][w].c_str())))
					checker++;
			}

			//zwiększenie o jeden liczby kontrastującyh pikseli jeżeli piksel, który sprawdzamy kontrastuje z conajmniej jednym pikselem obok
			if (checker > 0)
				howManyContrastingPixels++;

			checker = 0;
		}
	}

	return "6.3 Liczba kontrastujacych pikseli: " + to_string(howManyContrastingPixels);
}
