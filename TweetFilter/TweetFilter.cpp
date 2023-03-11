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
	vector<string> bannedWords = read_file("banned.txt");

	TweetSet allTweets = tweets1 + tweets2 + tweets3 + tweets4;

	allTweets.printTweets();
	allTweets.filterTweets(bannedWords);
	allTweets.printFilteredTweets();
	cout << allTweets.countBannedWords(bannedWords);

	//// banned words sum
	//int bannedWordsSum = 0;

	//// filter tweets1
	//tweets1.printTweets();
	//tweets1.filterTweets(bannedWords);
	//tweets1.printFilteredTweets();
	//bannedWordsSum += tweets1.countBannedWords(bannedWords);

	//// filter tweets2
	//tweets2.printTweets();
	//tweets2.filterTweets(bannedWords);
	//tweets2.printFilteredTweets();
	//bannedWordsSum += tweets2.countBannedWords(bannedWords);

	//// filter tweets3
	//tweets3.printTweets();
	//tweets3.filterTweets(bannedWords);
	//tweets3.printFilteredTweets();
	//bannedWordsSum += tweets3.countBannedWords(bannedWords);

	//// filter tweets4
	//tweets4.printTweets();
	//tweets4.filterTweets(bannedWords);
	//tweets4.printFilteredTweets();
	//bannedWordsSum += tweets4.countBannedWords(bannedWords);

	//cout << "Total number of banned words: " << bannedWordsSum << endl;
}
