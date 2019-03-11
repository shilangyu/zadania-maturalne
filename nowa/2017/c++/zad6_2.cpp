#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

vector<string> doReverse(vector<string> input)
{
	vector<string> output;

	for (int i = 0; i < input.size(); i++)
		output.push_back(input[input.size() - (i + 1)]);

	return output;
}

string zad6_2()
{
	fstream file("../dane/dane.txt");
	string line;
	vector<vector<string>> content;
	vector<string> currentLine;
	int howManyAsyncLines = 0;

	//odczytywanie z pliku przechodząc po poszczególnych elementach
	if (file.is_open())
	{
		while (getline(file, line))
		{
			stringstream ss(line);
			while (getline(ss, line, ' '))
				currentLine.push_back(line);

			content.push_back(currentLine);
			currentLine.clear();
		}
	}
	file.close();

	for (int i = 0; i < content.size(); i++)
	{
		if (content[i] != doReverse(content[i]))
			howManyAsyncLines++;
	}

	return "6.2) Najmniejsza liczba wierszy do usuniecia, zeby uzyskac symetryczny obraz: " + to_string(howManyAsyncLines);
}