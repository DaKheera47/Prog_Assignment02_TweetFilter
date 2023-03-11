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
	~TweetSet() {};
	void addTweet(string tweet);
	void filterTweets(vector<string> bannedWords);
	void printFilteredTweets();
	void printTweets();

private:
	vector<string> m_tweets;
	vector<string> m_filteredTweets;
};

#endif // !TWEETSET
