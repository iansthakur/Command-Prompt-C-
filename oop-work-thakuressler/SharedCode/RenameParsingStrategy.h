#pragma once
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	//see AbstractParsingStrategy header file for info on functions
	std::vector<string> parse(std::string);

};