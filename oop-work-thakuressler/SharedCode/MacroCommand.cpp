#include "MacroCommand.h"
#include <sstream>
#include <istream>

using namespace std;

MacroCommand::MacroCommand()
{
	commands = {};
	aps = nullptr;
}

MacroCommand::MacroCommand(AbstractFileSystem*)
{
	commands = {};
	aps = nullptr;

}

int MacroCommand::execute(std::string input)
{
	vector<string> words = aps->parse(input); //takes out strings to be used by each command and stores them order in a vector
	int i = 0;//index for selecting which string should be used
	for (auto comm : commands) {//iterate thru commands called by macrocommand(commands are in vector so they are order)
		int result = comm->execute(words[i]);//attempt to execute command on coordesponding string
		if (result == 0) {//if the execute call was successful move on to next command (inc i so that next string spot can be used)
			++i;
		}
		else {//if it failed return the enum for the execute that failed
			return result;
		}
	}
	//all executes were successful so return success
	return success;
}

void MacroCommand::addCommand(AbstractCommand* toAdd)
{
	//add command to back of vector (must add commands in order that they should be called)
	commands.push_back(toAdd);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* copyAPS)
{
	//set parsing strategy for th particular macro command
	aps = copyAPS;
}

void MacroCommand::displayInfo()
{
	cout << "calls previously defined commands in a specific order to complete new command" << endl;
}
