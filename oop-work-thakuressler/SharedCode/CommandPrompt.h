#pragma once
#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <iterator>
#include <iostream>
#include <istream>
#include <sstream>

using namespace std;

class CommandPrompt {
public:
	//constructor
	CommandPrompt();
	//destructor
	~CommandPrompt() = default;
	//sets abstractfilesystem pointer for this command (stored as local variable)
	void setFileSystem(AbstractFileSystem*);
	//sets abstractFileFactory pointer for this command (stored as local variable)
	void setFileFactory(AbstractFileFactory*);
	//returns 0 if command is successfully added
	int addCommand(std::string, AbstractCommand*);
	//repeatedly calls prompt and executes funcitons user inputs
	//returns 0 if it is ended using q
	int run();

protected:
	//prints out the list of commands
	void listCommands();
	//prompts the user for an input
	std::string prompt();


private:
	map<string, AbstractCommand*> m;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};