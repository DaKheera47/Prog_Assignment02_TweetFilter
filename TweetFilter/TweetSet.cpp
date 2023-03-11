#include "TweetSet.h"
#include "Utilities.h"

TweetSet::TweetSet(vector<string> tweets)
{
	m_tweets = tweets;
}

void TweetSet::addTweet(string tweet)
{
	m_tweets.push_back(tweet);
}

void TweetSet::filterTweets(vector<string> bannedWords)
{
	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");
		string filteredTweet;

		for (int wordIdx = 0; wordIdx < words.size(); wordIdx++)
		{
			filteredTweet += filterWord(words[wordIdx], bannedWords) + " ";
		}

		m_filteredTweets.push_back(filteredTweet);
	}
}

void TweetSet::printTweets()
{
	cout << endl << "Tweets Loaded Initially:" << endl;
	for (int i = 0; i < m_tweets.size(); i++) {
		cout << m_tweets[i] << endl;
	}
}

void TweetSet::printFilteredTweets()
{
	cout << endl << "Filtered Tweets:" << endl;
	for (int i = 0; i < m_filteredTweets.size(); i++) {
		cout << m_filteredTweets[i] << endl;
	}
}
