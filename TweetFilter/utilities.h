#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef UTILITIES

// Splits a string into substrings based on a delimiter, similar to .split in Python
vector<string> split(const string& str, const string& delimiter);

// string to lowercase
string toLower(string str);

// filter a word by comparing it against a vector of banned strings
string filterWord(string word, vector<string>& bannedWords);

// check if a word is banned
bool isWordBanned(string word, vector<string>& bannedWords);

#endif // !UTILITIES
