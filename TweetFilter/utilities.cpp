#include "Utilities.h"
#include "TweetSet.h"

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

// string to lowercase, returns a new string
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

string censorWord(string word, vector<string>& bannedWords)
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

int charToInt(char character)
{
	// char to int conversion
	// https://stackoverflow.com/a/5030086/11815481
	return character - '0';
}

// print strikethrough text using unicode characters
// https://stackoverflow.com/questions/38926669/strike-through-plain-text-with-unicode-characters
// caveat: all terminals may not support unicode character rendering
string strikeThroughText(string text)
{
	return "\033[9m" + text + "\033[0m";
}


// print out a line of characters
// takes number of characters to print and the character to print
void DrawLine(int length, char symbol)
{
	for (int i = 0; i < length; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

// clear console
void clear()
{
	system("cls");
}

// pause console and clear
void pauseAndClear()
{
	system("pause");
	system("cls");
}

// get user input as a float
// handles errors, returns the float
float floatInput(string prompt) {
	double input;
	bool isValid = false;
	string inputString;

	while (!isValid) {
		// display prompt message
		cout << prompt << ": ";

		cin >> inputString;

		bool isInpValid = true;

		// loop through every char
		for (int i = 0; i < inputString.length(); i++) {
			// if the char is not a number
			char c = inputString[i];

			if (c != '.' && !isdigit(c)) {
				cout << "Invalid input. Please enter a number. " << endl;
				isInpValid = false;
				break;
			}
		}

		// if the input is not valid
		if (!isInpValid) continue;

		// check if the input is a float
		try
		{
			// try to cast string to float
			input = stof(inputString);
			isValid = true;
		}
		catch (const exception&)
		{
			// if input is not a float, clear the error state
			cin.clear();
			// ignore remaining characters in the input stream
			cin.ignore(CONSOLE_WIDTH, '\n');
			cout << "Invalid input. Please enter a number. " << endl;

			continue;
		}
	}

	return (float)input;
}

// get user input as a int
// handles errors, returns the int
int intInput(string prompt) {
	int input;
	bool isValid = false;
	string inputString;

	while (!isValid) {
		// display prompt message
		cout << prompt << ": ";

		cin >> inputString;

		bool isInpValid = true;

		// loop through every char
		for (int i = 0; i < inputString.length(); i++) {
			// if the char is not a number
			if (!isdigit(inputString[i])) {
				cout << "Invalid input. Please enter a number. " << endl;
				isInpValid = false;
				break;
			}
		}

		// if the input is not valid
		if (!isInpValid) continue;

		// check if the input is a int
		try
		{
			// try to cast string to int
			input = stoi(inputString);
			isValid = true;
		}
		catch (const exception&)
		{
			// if input is not a float, clear the error state
			cin.clear();
			// ignore remaining characters in the input stream
			cin.ignore(CONSOLE_WIDTH, '\n');
			cout << "Invalid input. Please enter a number. " << endl;

			continue;
		}
	}

	return (int)input;
}

// get user input as an int
// handles errors, and verifies that input is within a given range
// adds a prompt to the end of the range prompt, if provided
// returns the int of the user input
// adds an exit option to the range prompt
int selectorPanelInput(vector<string> availableOptions, string prompt, string defaultOption)
{
	float output;
	bool isValid = false;
	int min = 0;
	int max = availableOptions.size();

	// print the available options with their corresponding numbers
	for (int i = 0; i < availableOptions.size(); i++) {
		cout << i + 1 << ". " << availableOptions[i] << endl;
	}

	// print the exit option
	cout << "0. " << defaultOption << endl;

	string option = prompt + " [" + to_string(min) + "-" + to_string(max) + "]";

	do
	{
		output = intInput(option);

		// check if output is a decimal by typecasting and comparing
		if (output != (int)output)
		{
			cout << "Invalid input. Please enter a whole number. " << endl;
			continue;
		}

		// check if input is within the specified range
		if (output >= min && output <= max)
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid input, please enter a number between " << min << " and " << max << endl;
		}
	} while (!isValid);

	return output;
}

// get user input to a y/n question, handles errors, returns true or false
// example prompt: "Do you want to continue?"
bool boolInput(string prompt)
{
	string options = " [y/n]: ";
	string input;
	cout << prompt << options;

	cin >> input;
	input = toLower(input);

	while (cin.fail() || input != "y" && input != "n")
	{
		// clear the error state
		cin.clear();
		// ignore the rest of the line
		cin.ignore(CONSOLE_WIDTH, '\n');

		// user doesn't enter a valid input, so retry
		cout << "Please enter a valid input. " << prompt << options;

		cin >> input;
		input = toLower(input);
	}

	// returns true if input was positive, else false
	return input == "y";
}

// get user input as a string
// handles errors, and returns the string in lowercase
string stringInput(string prompt)
{
	string options = ": ";
	string input;
	bool isValid = false;

	do
	{
		cout << prompt << options;
		cin >> input;

		if (input.empty())
		{
			cout << "Invalid input, please enter a valid string" << endl;
		}
		else
		{
			input = toLower(input);
			isValid = true;
		}
	} while (!isValid);

	return input;
}

// read file to a vector of strings
vector<string> read_file(string filename) {
	vector<string> lines;
	ifstream openedFile(filename);
	string line;

	if (!openedFile.is_open()) {
		cerr << "Unable to open file: " << filename << endl;
		return lines;
	}

	while (getline(openedFile, line)) {
		lines.push_back(line);
	}

	// close the file
	openedFile.close();
	return lines;
}

void write_file(string filename, vector<string> lines)
{
	ofstream openedFile(filename);

	if (!openedFile.is_open()) {
		cerr << "Unable to open file: " << filename << endl;
		return;
	}

	openedFile.clear();

	for (int i = 0; i < lines.size(); i++) {
		openedFile << lines[i] << endl;
	}

	// close the file
	openedFile.close();
}

void handleTweetMenu(TweetSet tweets, vector<string> menuOptions, SConstants constants)
{
	bool nestedShouldContinue = true;
	int nestedMenuSelection;

	while (nestedShouldContinue)
	{
		clear();

		cout << "Actions for " << toLower(tweets.getDisplayName()) << endl << endl;

		nestedMenuSelection = selectorPanelInput(menuOptions, "Select an option", "Back");

		switch (nestedMenuSelection)
		{
		case 0:
			nestedShouldContinue = false;
			clear();
			return;
		case 1:
			tweets.printTweets();
			pauseAndClear();
			break;
		case 2:
			tweets.filterTweets(constants.bannedWords);
			tweets.printFilteredTweets();
			pauseAndClear();
			break;
		case 3:
			cout << "Number of banned words: " << tweets.countBannedWords(constants.bannedWords) << endl;
			pauseAndClear();
			break;
		case 4:
			tweets.SentimentAnalysis(constants.positiveWords, constants.negativeWords);
			pauseAndClear();
			break;
		case 5:
			tweets.countFrequentWords(intInput("Enter the number of most frequent words you want to see"));
			pauseAndClear();
			break;		
		case 6:
			tweets.writeFilteredTweets("tweets1Filtered.txt");
			pauseAndClear();
			break;
		default:
			nestedShouldContinue = false;
			clear();
			return;
		}
	}
}
