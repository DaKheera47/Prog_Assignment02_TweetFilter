// TweetFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TweetSet.h"
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
	// load tweets1
	TweetSet tweets1 = read_file("tweets1.txt");

	// load tweets2
	TweetSet tweets2 = read_file("tweets2.txt");

	// load tweets3
	TweetSet tweets3 = read_file("tweets3.txt");
	
	// load tweets4
	TweetSet tweets4 = read_file("tweets4.txt");

	// read file to a vector of strings
	vector<string> bannedWords;
	bannedWords = read_file("banned.txt");

	// filter tweets1
	tweets1.printTweets();
	tweets1.filterTweets(bannedWords);
	tweets1.printFilteredTweets();

	// filter tweets2
	tweets2.printTweets();
	tweets2.filterTweets(bannedWords);
	tweets2.printFilteredTweets();

	// filter tweets3
	tweets3.printTweets();
	tweets3.filterTweets(bannedWords);
	tweets3.printFilteredTweets();
	
	// filter tweets4
	tweets4.printTweets();
	tweets4.filterTweets(bannedWords);
	tweets4.printFilteredTweets();


	//// loop through tweets
	//for (int i = 0; i < tweets4.size(); i++) {
	//	// loop through banned words
	//	for (int j = 0; j < bannedWords.size(); j++) {
	//		// if tweet contains banned word
	//		if (tweets4[i].find(bannedWords[j]) != string::npos) {
	//			// replace only the centermost character of banned word with asterisks. eg, concatenation becomes contc*tenation if cat is banned, and if it's an even number of characters, the middle 2 characters are replaced with asterisks
	//		}
	//	}
	//}

	//// print tweets
	//for (int i = 0; i < tweets1.size(); i++) {
	//	cout << tweets1[i] << endl;
	//}
	//for (int i = 0; i < tweets4.size(); i++) {
	//	cout << tweets4[i] << endl;
	//}
}
