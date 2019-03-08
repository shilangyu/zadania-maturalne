#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//funkcja odwracająca stringi z vectora zwracająca vector
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
	vector<string> content;
	int howManyAsyncLines = 0;

	//odczytywanie z pliku przechodząc po poszczególnych elementach
	if (file.is_open())
	{
		while (getline(file, line))
			content.push_back(line);
	}
	file.close();

	vector<string> reversed = doReverse(content);

	//work in progress
	for (int i = 0; i < content.size(); i++)
	{
		if (content[i] != reversed[i])
			howManyAsyncLines++;
	}

	return "6.2 Najmniejsza liczba wierszy do usuniecia, zeby uzyskac symetryczny obraz: " + to_string(howManyAsyncLines);
}