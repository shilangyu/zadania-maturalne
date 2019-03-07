#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//funkcja odwracająca stringi z vectora zwracająca vector
vector<string> doReverse(vector<string> input) {
	vector<string> output;
	
	for (int i = 0; i < input.size(); i++)
		output.push_back(input[input.size() - (i + 1)]);
		
	return output;
}

int main() {
    fstream file("dane.txt");
    string element;
    vector<string> line;
    int howManyAsyncLines = 0;

    //odczytywanie z pliku przechodząc po poszczególnych elementach
	if (file.is_open()) {
		while (getline(file, element)) {
			stringstream ss(element);
			while (getline(ss, element, ' ')) line.push_back(element);
			
			if (line != doReverse(line)) howManyAsyncLines++;
			line.clear();
		}
	}
	file.close();

    cout << "6.2 Najmniejsza liczba wierszy do usuniecia, zeby uzyskac symetryczny obraz: " << howManyAsyncLines << endl;

    system("PAUSE");
}