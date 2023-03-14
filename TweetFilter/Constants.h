#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#ifndef CONSTANTSDEF

// store all constants in one central struct variable
struct SConstants {
	vector<string> bannedWords;
	vector<string> positiveWords;
	vector<string> negativeWords;
};

#endif // !CONSTANTSDEF
