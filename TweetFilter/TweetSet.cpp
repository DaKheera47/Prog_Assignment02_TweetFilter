#include "TweetSet.h"
#include "Utilities.h"

// constructor for TweetSet
TweetSet::TweetSet(vector<string> tweets, string name)
{
	m_tweets = tweets;
	m_displayName = name;
}

// default constructor
TweetSet::TweetSet()
{
	m_tweets = {};
}

// https://www.geeksforgeeks.org/operator-overloading-cpp/
TweetSet& TweetSet::operator+(TweetSet& other)
{
	// Loop over tweets in other and add them to this TweetSet
	addTweet(other.getTweets());
	// return a copy
	return *this;
}

// overload for adding one tweet, or adding multiple tweets
void TweetSet::addTweet(string tweet)
{
	m_tweets.push_back(tweet);
}

// overload for adding one tweet, or adding multiple tweets
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

// filter each word in each tweet by comparing to banned words
void TweetSet::filterTweets(vector<string> bannedWords)
{
	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");
		string filteredTweet;

		for (int wordIdx = 0; wordIdx < words.size(); wordIdx++)
		{
			filteredTweet += censorWord(words[wordIdx], bannedWords) + " ";
		}

		m_filteredTweets.push_back(filteredTweet);
	}
}

// print the tweets initially loaded from the file
void TweetSet::printTweets()
{
	cout << endl << "Tweets Loaded Initially:" << endl;
	for (int i = 0; i < m_tweets.size(); i++) {
		cout << i + 1 << ". " << m_tweets[i] << endl;
	}
	cout << endl;
}

// print filtered tweets
void TweetSet::printFilteredTweets()
{
	cout << endl << "Filtered Tweets:" << endl;
	for (int i = 0; i < m_filteredTweets.size(); i++) {
		cout << m_filteredTweets[i] << endl;
	}
	cout << endl;
}

// count the number of banned words in the tweets
// return the number of banned words
int TweetSet::countBannedWords(vector<string> bannedWords)
{
	// reset count
	m_numBannedWords = 0;

	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");

		for (int wordIdx = 0; wordIdx < words.size(); wordIdx++)
		{
			if (isWordInVector(words[wordIdx], bannedWords)) {
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

// count occurances of each word, and then sort by most frequent
// returns n most frequent words
vector<string> TweetSet::countFrequentWords(int n)
{
	// reset count
	m_frequentWords = {};

	// acts as a pair
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

	// TODO write a custom sorting algorithm here
	vector<pair<string, int>> sortedCounts(wordCounts.begin(), wordCounts.end());
	sort(sortedCounts.begin(), sortedCounts.end(), comparePairs);

	if (n > sortedCounts.size()) {
		n = sortedCounts.size();
	}
	else if (n < 0) {
		n = 0;
	}

	cout << endl;
	cout << "Top " << n << " most common words: " << endl;

	// print all words
	for (int i = 0; i < n; i++) {
		cout << sortedCounts[i].first << ": " << sortedCounts[i].second << endl;
	}

	return m_frequentWords;
}

void TweetSet::setDisplayName(string name)
{
	m_displayName = name;
}

string TweetSet::getDisplayName()
{
	return m_displayName;
}

// counts the number of positive and negative words
// prints the results to the console
void TweetSet::SentimentAnalysis(vector<string>& positiveWords, vector<string>& negativeWords)
{

	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		m_numPositiveWords = 0;
		m_numNegativeWords = 0;

		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");

		// count the words
		for (const auto& word : words) {
			if (isWordInVector(word, positiveWords)) {
				m_numPositiveWords++;
			}
			else if (isWordInVector(word, negativeWords)) {
				m_numNegativeWords++;
			}
		}

		cout << tweetIdx + 1 << ". " << m_tweets[tweetIdx] << endl;

		cout << "Positive Words: " << m_numPositiveWords << endl;
		cout << "Negative Words: " << m_numNegativeWords << endl;

		// calculate sentiment
		if (m_numPositiveWords > m_numNegativeWords) {
			cout << "Overall Sentiment: Positive" << endl;
		}
		else if (m_numPositiveWords < m_numNegativeWords) {
			cout << "Overall Sentiment: Negative" << endl;
		}
		else {
			cout << "Overall Sentiment: Neutral" << endl;
		}

		cout << endl;
	}
}
