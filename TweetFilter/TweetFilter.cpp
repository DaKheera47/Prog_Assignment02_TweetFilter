// TweetFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// read file to a vector of strings
vector<string> read_file(string filename) {
	vector<string> lines;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		lines.push_back(line);
	}

	return lines;
}

int main()
{
	// read file to a vector of strings
	vector<string> v;
	v = read_file("tweets1.txt");

	// print vector of strings
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
