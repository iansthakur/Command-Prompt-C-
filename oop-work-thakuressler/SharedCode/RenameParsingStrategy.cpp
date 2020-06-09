#include "RenameParsingStrategy.h"
#include "AbstractFile.h"
#include <sstream>
#include <istream>


using namespace std;
std::vector<string> RenameParsingStrategy::parse(std::string input)
{
	istringstream iss(input);//create istring stream of input
	string old;
	string copy;
	string lengthTest;
	iss >> old;//first word in input should be old  file name
	iss >> copy;//second word should be new file name (or name of file that is copied)
	while ((iss >> lengthTest)) {//if there are more words at the end add them to copy (new file name) bc it will cause copy to return invalidargument
		copy += ' ';
		copy += lengthTest;
	}
	string oldAndNew = old + ' ' + copy;//copy needs old name and new name with space between so format it properly then put in first spot of vector bc copy isc alled firsted
	vector<string> parsedStrings = {oldAndNew,old };//put the old file name in second spot of the vector because it needs to be removed from the directory
	return parsedStrings;//return the vector or strings whicha re the arguments for each command
}
