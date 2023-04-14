#include "TweetSet.h"
#include "Utilities.h"
#include <map>

void outputTweets(vector<string> tweets)
{
	for (int i = 0; i < tweets.size(); i++)
	{
		cout << i + 1 << ". " << tweets[i] << endl;
	}
}

// constructor for TweetSet
TweetSet::TweetSet(vector<string> tweets, string name, string sourceFilename, string destinationFilename)
{
	m_tweets = tweets;
	m_displayName = name;
	m_sourceFilename = sourceFilename;
	m_destinationFilename = destinationFilename;
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
	outputTweets(m_tweets);
	cout << endl;
}

// print filtered tweets
void TweetSet::printFilteredTweets()
{
	cout << endl << "Filtered Tweets:" << endl;
	outputTweets(m_filteredTweets);
	cout << endl;
}

// count the number of banned words in the tweets
// return the number of banned words
int TweetSet::countBannedWords(vector<string> bannedWords)
{
	// reset count
	m_numBannedWords = 0;

	map<string, int> bannedWordsCount;

	// Initialize the count of each banned word to 0
	for (const auto& word : bannedWords) {
		bannedWordsCount[word] = 0;
	}

	// make a list of all bannedWords in the tweets
	for (int tweetIdx = 0; tweetIdx < m_tweets.size(); tweetIdx++) {
		// split tweet into words
		vector<string> words = split(m_tweets[tweetIdx], " ");

		for (int wordIdx = 0; wordIdx < words.size(); wordIdx++)
		{
			if (isWordInVector(words[wordIdx], bannedWords)) {
				bannedWordsCount[words[wordIdx]]++;
				m_numBannedWords++;
			}
		}
	}

	cout << endl;
	cout << "Here's how often each banned word occurred: " << endl;

	// print all words
	for (const auto& wordCountPair : bannedWordsCount) {
		string word = wordCountPair.first;

		// make lowercase
		word = toLower(word);

		// remove punctuation
		word = removePunctuation(word);

		cout << word << ": " << wordCountPair.second << endl;
	}

	cout << endl;
	cout << "Total number of banned words: " << m_numBannedWords << endl;

	return m_numBannedWords;
}

// count occurances of each word, and then sort by most frequent
// returns n most frequent words
vector<string> TweetSet::countFrequentWords(int n)
{
	// reset count
	m_frequentWords = {};

	// count occurances of each word
	vector<pair<string, int>> sortedCounts = countUniqueWords(m_tweets);

	// make sure n is within bounds
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

void TweetSet::writeFilteredTweets()
{
	write_file(m_destinationFilename, m_filteredTweets);

	// print the tweets
	cout << endl << "Filtered Tweets Being Saved:" << endl;
	outputTweets(m_filteredTweets);
	cout << endl;

	cout << "Filtered tweets written to " << m_destinationFilename << endl;
}

void TweetSet::setDisplayName(string name)
{
	m_displayName = name;
}

string TweetSet::getDisplayName()
{
	return m_displayName;
}

void TweetSet::setFileName(string name)
{
	m_sourceFilename = name;
}

string TweetSet::getFileName()
{
	return m_sourceFilename;
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
