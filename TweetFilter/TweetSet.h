#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef TWEETSET

class TweetSet
{
public:
	TweetSet(vector<string> tweets);
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
	int countBannedWords(vector<string> bannedWords);

private:
	vector<string> m_tweets;
	vector<string> m_filteredTweets;
	int m_numBannedWords;
};

#endif // !TWEETSET
