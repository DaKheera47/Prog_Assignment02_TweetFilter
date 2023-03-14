#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;


#ifndef CONSTANTSDEF

struct SConstants {
	vector<string> bannedWords;
	vector<string> positiveWords;
	vector<string> negativeWords;
};

#endif // !CONSTANTSDEF
