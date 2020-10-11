/*
Description: The program reads a series of movies and its info from a text file, and extracts
the movie titles to be put inside of a vector. Then, the vector of movie titles
is sorted alphabetically and printed out to the command console using a function.

Date: 4/19/2019

*/
 
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void printOnScreen(vector<string>);

int main() {
	
	string wholeLine, title, filename, director;
	
	vector<string> movieTitles;
	vector<string> movieDirectors;
	
	ifstream inputFile;
	inputFile.open("Movie_entries.txt");
	
	// if file doesn't open, ask user for filename
	while(inputFile.fail() == 1) {
		cout << "Enter the filename: ";
		cin >> filename;
		
		inputFile.open(filename);
	}
	
	// while loop to extract movie titles from each line and putting them inside the vector "movieTitles"
	while (inputFile) {
		getline(inputFile, wholeLine);
		stringstream lineStream(wholeLine);
		getline(lineStream, title, ',');
		getline(lineStream, director, ',');
		movieTitles.push_back(title);
		movieDirectors.push_back(director); 
		
	}
	
	inputFile.close();
	
	// sort function to sort the contents inside the vector "movieTitles" alphabetically
	sort (movieTitles.begin(), movieTitles.end());
	
	printOnScreen(movieTitles);
	
	
	return 0;
}

/*
This function receive the movie titles contents inside the vector "movieTitles" to be printed out to the command console
The function does not return anything
*/
void printOnScreen(vector<string> movieTitles) {
	
	for (string director : movieTitles)
		cout << director << endl;
		
}

/* OUTPUT
A Thousand Words
Avengers: Age of Ultron
Captain America: The Winter Soldier
Chungking Express
Earthlings
Ghost in the Shell
Gone Girl
Guardians of the Galaxy
Happy Feet
Inglourious Basterds
Interstellar
Kung Fu Hustle
Limitless
Mean Girls
Saving Private Ryan
Superbad
Surf's Up
The Great Escape
The Matrix
Under the Tuscan Sun
Whiplash
Zoolander
*/













