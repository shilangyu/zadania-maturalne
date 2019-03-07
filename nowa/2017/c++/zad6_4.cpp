#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

string zad6_4()
{
	string element, board[200][320];
	int width = 0, height = 0;

	fstream file("../dane/dane.txt");

	if (file.is_open())
	{
		while (getline(file, element, ' '))
		{

			if (width < 320 and height < 200)
				board[height][width] = element;

			width++;

			if (width == 320)
			{
				width = 0;
				height++;
			}
		}
	}
	file.close();

	string verticalLines[320];

	//przechodzenie po dwuwymiarowej tablicy po kolumnach i dodawanie poszczególnych elementów do tablicy verticalLines
	for (int width = 0; width < 320; width++)
	{
		for (int height = 0; height < 200; height++)
		{
			verticalLines[width] += board[height][width];
		}
	}

	int maxLength = 0, currentLength = 0;

	//przechodzenie po tablicy verticalLines i zliczanie ile maksymalnie takich samych elementów następuje po sobie
	for (int i = 0; i < 320; i++)
	{
		string current = verticalLines[i];
		for (int j = 0; j < verticalLines[i].size(); j++)
		{
			if (j == 0)
				currentLength++;
			else if (current[j] == current[j - 1])
				currentLength++;
			else
				break;
		}

		maxLength = (currentLength > maxLength) ? currentLength : maxLength;

		currentLength = 0;
	}

	return "6.4 Liczba elementow najdluzszej kolumny pikseli swiecacej z ta sama jasnoscia: " + to_string(maxLength);
}