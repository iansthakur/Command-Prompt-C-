#pragma once
#include <vector>
#include <string>

using namespace std;

class AbstractParsingStrategy {
public:
	//returns a vector of strings containing the arguements for each function called by the MacroCommand
	virtual std::vector<string> parse(std::string) = 0;
};