#include "TweetSet.h"
#include "Utilities.h"

TweetSet::TweetSet(vector<string> tweets)
{
	m_tweets = tweets;
}
TweetSet::TweetSet()
{
	m_tweets = {};
}

// https://www.geeksforgeeks.org/operator-overloading-cpp/
TweetSet& TweetSet::operator+(TweetSet& other)
{
	// Loop over tweets in other and add them to this TweetSet
	for (const auto& tweet : other.getTweets()) {
		addTweet(tweet);
	}

	return *this;
}

void TweetSet::addTweet(string tweet)
{
	m_tweets.push_back(tweet);
}

void TweetSet::addTweet(vector<string> tweets)
{
	for (const auto& tweet : tweets) {
		addTweet(tweet);
	}
}

vector<string> TweetSet::getTweets()
{
	return m_tweets;
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

int TweetSet::countBannedWords(vector<string> bannedWords)
{
	// reset count
	m_numBannedWords = 0;

	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");

		for (int wordIdx = 0; wordIdx < words.size(); wordIdx++)
		{
			if (isWordBanned(words[wordIdx], bannedWords)) {
				m_numBannedWords++;
			}
		}
	}

	return m_numBannedWords;
}

// Define a comparison function to compare two key-value pairs based on their values
bool comparePairs(const pair<string, int>& pair1, const pair<string, int>& pair2) {
	return pair1.second > pair2.second;
}

vector<string> TweetSet::countFrequentWords(int n)
{
	// reset count
	m_frequentWords = {};

	unordered_map<string, int> wordCounts;

	// count words
	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");

		// count the words
		for (const auto& word : words) {
			wordCounts[word]++;
		}
	}

	vector<pair<string, int>> sortedCounts(wordCounts.begin(), wordCounts.end());
	sort(sortedCounts.begin(), sortedCounts.end(), comparePairs);

	cout << "Top " << n << " most common words: " << endl;

	if (n > sortedCounts.size()) {
		n = sortedCounts.size();
	}
	else if (n < 0) {
		n = 0;
	}

	// print all words
	for (int i = 0; i < n; i++) {
		cout << sortedCounts[i].first << ": " << sortedCounts[i].second << endl;
	}

	return m_frequentWords;
}

