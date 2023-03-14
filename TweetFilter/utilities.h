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

// string to lowercase
string toLower(string str);

// filter a word by comparing it against a vector of banned strings
string censorWord(string word, vector<string>& bannedWords);

// check if a word is banned
bool isWordInVector(string word, vector<string>& bannedWords);

int charToInt(char character);

string strikeThroughText(string text);

void DrawLine(int length, char symbol);

void clear();
void pauseAndClear();

// input validation functions
float floatInput(string prompt);
int intInput(string prompt);
int selectorPanelInput(vector<string> availableOptions, string prompt, string defaultOption = "Exit");
bool boolInput(string prompt);
string stringInput(string prompt);

// file handling
vector<string> read_file(string filename);
void handleTweetMenu(TweetSet tweets, vector<string> menuOptions, SConstants word_constants);

#endif // !UTILITIES
