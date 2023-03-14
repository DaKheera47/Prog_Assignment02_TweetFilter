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
	TweetSet tweets1 = { read_file("tweets1.txt"), "Tweets from file 1" };
	// load tweets2
	TweetSet tweets2 = { read_file("tweets2.txt"), "Tweets from file 2" };
	// load tweets3
	TweetSet tweets3 = { read_file("tweets3.txt"), "Tweets from file 3" };
	// load tweets4
	TweetSet tweets4 = { read_file("tweets4.txt"), "Tweets from file 4" };

	// read file to a vector of strings
	vector<string> bannedWords = read_file("banned.txt");
	vector<string> positiveWords = read_file("positive.txt");
	vector<string> negativeWords = read_file("negative.txt");

	SConstants word_constants{};
	word_constants.bannedWords = bannedWords;
	word_constants.positiveWords = positiveWords;
	word_constants.negativeWords = negativeWords;

	TweetSet allTweets;
	allTweets = allTweets + tweets1;
	allTweets = allTweets + tweets2;
	allTweets = allTweets + tweets3;
	allTweets = allTweets + tweets4;
	allTweets.setDisplayName("All Tweets");

	// options
	vector<string> mainMenuOptions = {
		"View options for file 1 tweets",
		"View options for file 2 tweets",
		"View options for file 3 tweets",
		"View options for file 4 tweets",
		"View options for all tweets",
	};

	vector<string> nestedMenuOptions = {
		"Show tweets before filtering",
		"Show tweets after filtering",
		"Show number of banned words",
		"Sentiment Analysis",
		"Show most frequent words",
	};

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
		case 5:
			handleTweetMenu(allTweets, nestedMenuOptions, word_constants);
			break;
		default:
			break;
		}
	} while (mainMenuSelection != 0);

	//allTweets.printTweets();
	//allTweets.filterTweets(bannedWords);
	//allTweets.printFilteredTweets();
	//cout << allTweets.countBannedWords(bannedWords) << endl << endl;
	//allTweets.countFrequentWords(10);
	//allTweets.SentimentAnalysis(positiveWords, negativeWords);

	//cout << intInput("Please enter a number");

	//// filter tweets1
	//tweets1.printTweets();
	//tweets1.filterTweets(bannedWords);
	//tweets1.printFilteredTweets();
	//tweets1.countFrequentWords(5);
	//tweets1.SentimentAnalysis(positiveWords, negativeWords);

	//clear();

	//// filter tweets2
	//tweets2.printTweets();
	//tweets2.filterTweets(bannedWords);
	//tweets2.printFilteredTweets();
	//tweets2.countFrequentWords(5);
	//tweets2.SentimentAnalysis(positiveWords, negativeWords);
	//clear();

	//// filter tweets3
	//tweets3.printTweets();
	//tweets3.filterTweets(bannedWords);
	//tweets3.printFilteredTweets();
	//tweets3.countFrequentWords(5);
	//tweets3.SentimentAnalysis(positiveWords, negativeWords);
	//clear();

	//// filter tweets4
	//tweets4.printTweets();
	//tweets4.filterTweets(bannedWords);
	//tweets4.printFilteredTweets();
	//tweets4.countFrequentWords(5);
	//tweets4.SentimentAnalysis(positiveWords, negativeWords);
}
