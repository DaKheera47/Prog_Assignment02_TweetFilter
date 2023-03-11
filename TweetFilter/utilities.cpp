#include "Utilities.h"

// Splits a string into substrings based on a delimiter
vector<string> split(const string& str, const string& delimiter) {
	vector<string> substrings;
	size_t start = 0;
	size_t end = str.find(delimiter);

	// Loop until delimiter is not found
	while (end != string::npos) {
		// Add substring before delimiter to vector
		substrings.push_back(str.substr(start, end - start));
		// Move start index to position after delimiter
		start = end + delimiter.length();
		// Find next delimiter from start position
		end = str.find(delimiter, start);
	}

	// Add remaining substring to vector
	substrings.push_back(str.substr(start));
	return substrings;
}

// string to lowercase
string toLower(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}

	return str;
}

bool isWordInVector(string word, vector<string>& searchVector)
{
	// make word lowercase
	word = toLower(word);

	for (int i = 0; i < searchVector.size(); i++)
	{
		// make banned word lowercase
		string bannedWord = toLower(searchVector[i]);
		bool isBanned = word.find(bannedWord) != string::npos;

		if (word.find(bannedWord) != string::npos)
		{
			return true;
		}
	}
	return false;
}

string filterWord(string word, vector<string>& bannedWords)
{
	// convert word to lowercase
	string wordInProcess = toLower(word);

	// loop through banned words
	for (int bannedIdx = 0; bannedIdx < bannedWords.size(); bannedIdx++) {
		// convert banned word to lowercase
		string bannedWord = toLower(bannedWords[bannedIdx]);

		// Find the index of the banned word within the tweet
		size_t bannedIndex = wordInProcess.find(bannedWord);

		if (wordInProcess.find(bannedWord) != string::npos) {
			// Calculate the length of the banned word
			size_t bannedLength = bannedWord.length();

			// Calculate the center index or indexes of the banned word to be replaced
			size_t centerIndex = bannedLength / 2;
			int centerLength = bannedLength % 2 == 0 ? 2 : 1;

			// Replace the center character(s) of the banned word with asterisks
			string filteredTweet = word;

			if (centerLength >= 2)
			{
				// making sure the correct place gets removed
				filteredTweet.replace(bannedIndex + centerIndex - 1, centerLength, centerLength, '*');
			}
			else {
				filteredTweet.replace(bannedIndex + centerIndex, centerLength, centerLength, '*');
			}

			return filteredTweet;
		}
	}

	// if word not found in banned words, return it unfiltered since it must not be banned
	return word;
}