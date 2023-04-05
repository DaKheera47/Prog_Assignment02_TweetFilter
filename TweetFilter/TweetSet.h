#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#ifndef TWEETSET

class TweetSet
{
public:
	TweetSet(vector<string> tweets, string name, string filename);
	TweetSet();

	// Define operator+ to combine two TweetSet objects
	TweetSet& operator+(TweetSet& other);

	~TweetSet() {};
	void addTweet(string tweet);
	void addTweet(vector<string> tweets);
	vector<string> getTweets();
	void filterTweets(vector<string> bannedWords);
	void printFilteredTweets();
	void printTweets();
	void SentimentAnalysis(vector<string>& positiveWords, vector<string>& negativeWords);
	int countBannedWords(vector<string> bannedWords);
	vector<string> countFrequentWords(int n);
	void writeFilteredTweets(string filename);

	// set displayname
	void setDisplayName(string name);
	string getDisplayName();

	// set filename
	void setFileName(string name);
	string getFileName();

private:
	string m_displayName;
	string m_filename;
	vector<string> m_tweets;
	vector<string> m_filteredTweets;
	vector<string> m_frequentWords;
	int m_numBannedWords;
	int m_numPositiveWords;
	int m_numNegativeWords;
};

#endif // !TWEETSET
