#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Constants.h"
#include "TweetSet.h"
using namespace std;

#ifndef UTILITIES

const int CONSOLE_WIDTH = 123;

// Splits a string into substrings based on a delimiter, similar to .split in Python
vector<string> split(const string& str, const string& delimiter);

// Converts a string to lowercase
string toLower(string str);

// Filters a word by comparing it against a vector of banned strings
// Returns the original word if it is not banned, otherwise returns a censored version of the word
string censorWord(string word, vector<string>& bannedWords);

// Checks if a word is in a vector of banned words
// Returns true if the word is in the vector, false otherwise
bool isWordInVector(string word, vector<string>& bannedWords);

// Converts a character to an integer
int charToInt(char character);

// Returns a string with strike-through formatting
string strikeThroughText(string text);

// Draws a line of a specified length with a specified symbol
void DrawLine(int length, char symbol);

// Clears the console screen
void clear();

// waits for user input, then clears the console screen
void pauseAndClear();

// Input validation functions
// Prompts the user for a floating-point number and returns the input
float floatInput(string prompt);

// Prompts the user for an integer and returns the input
int intInput(string prompt);

// Displays a selector panel with a list of options and prompts the user to select an option
// adds the exit option automatically
// Returns the number chosen by the user
int selectorPanelInput(vector<string> availableOptions, string prompt, string defaultOption = "Exit");

// Prompts the user for a boolean value and returns the input
// can be used directly in a conditional statement `e.g. if (boolInput("Do you want to continue?"))`
bool boolInput(string prompt);

// Prompts the user for a string and returns the input
string stringInput(string prompt);

// File handling functions
// Reads the contents of a file and returns a vector of strings containing each line of the file
vector<string> read_file(string filename);

// Writes a vector of strings to a file, each string on a new line
void write_file(string filename, vector<string> lines);

// Displays a menu of options for interacting with a TweetSet object and handles user input accordingly
void handleTweetMenu(TweetSet tweets, vector<string> menuOptions, SConstants word_constants);

#endif // !UTILITIES
