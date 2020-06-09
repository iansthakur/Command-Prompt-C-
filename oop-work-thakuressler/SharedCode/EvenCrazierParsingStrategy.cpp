#include "EvenCrazierParsingStrategy.h"
#include "AbstractFile.h"
#include <sstream>
#include <istream>

std::vector<string> EvenCrazierParsingStrategy::parse(std::string input)
{
	//this command calls touch, cat, and ds
	//the input for each of these is just the file name, so
	//put (alternativel could have pushbacked) the fileName into the vector of strings returned by method
	//so that commands are called on fileName
	vector<string> parsedStrings = { input, input, input };
	return parsedStrings;
}
