// TweetFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TweetSet.h"
#include "Utilities.h"
#include "Constants.h"
using namespace std;

int main()
{
	// load tweets1
	TweetSet tweets1 = { read_file("tweets1.txt"), "Tweets from file 1", "tweets1.txt", "tweets1Filtered.txt" };
	// load tweets2
	TweetSet tweets2 = { read_file("tweets2.txt"), "Tweets from file 2", "tweets2.txt", "tweets2Filtered.txt" };
	// load tweets3
	TweetSet tweets3 = { read_file("tweets3.txt"), "Tweets from file 3", "tweets3.txt", "tweets3Filtered.txt" };
	// load tweets4
	TweetSet tweets4 = { read_file("tweets4.txt"), "Tweets from file 4", "tweets4.txt", "tweets4Filtered.txt" };

	// read file to a vector of strings
	vector<string> bannedWords = read_file("banned.txt");
	vector<string> positiveWords = read_file("positive.txt");
	vector<string> negativeWords = read_file("negative.txt");

	SConstants word_constants{
		bannedWords,
		positiveWords,
		negativeWords
	};

	// options
	vector<string> mainMenuOptions = {
		"View options for tweets1.txt",
		"View options for tweets2.txt",
		"View options for tweets3.txt",
		"View options for tweets4.txt",
	};

	vector<string> nestedMenuOptions = {
		"Show tweets before filtering",
		"Show tweets after filtering",
		"Count banned words",
		"Sentiment Analysis",
		"Show most frequent words",
		"Output to file",
	};

	// this is the user selected option for the main menu options
	int mainMenuSelection;
	do {
		mainMenuSelection = selectorPanelInput(mainMenuOptions, "Select an option");

		switch (mainMenuSelection)
		{
		case 1:
			handleTweetMenu(tweets1, nestedMenuOptions, word_constants);
			break;
		case 2:
			handleTweetMenu(tweets2, nestedMenuOptions, word_constants);
			break;
		case 3:
			handleTweetMenu(tweets3, nestedMenuOptions, word_constants);
			break;
		case 4:
			handleTweetMenu(tweets4, nestedMenuOptions, word_constants);
			break;
		default:
			break;
		}
	} while (mainMenuSelection != 0);
}
