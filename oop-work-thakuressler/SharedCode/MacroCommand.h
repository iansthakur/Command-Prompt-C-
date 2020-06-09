#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"//might be an issue bc of string/ vector includes

class MacroCommand : public AbstractCommand {
public:
	MacroCommand();
	MacroCommand(AbstractFileSystem*);
	//see AbstractCommand header file for info on functions
	int execute(std::string);
	//adds teh previously defined commands to the macrocommand in the order they need to be called in
	void addCommand(AbstractCommand*);
	//specifies which parsing strategy should be called for the macrocommand
	void setParseStrategy(AbstractParsingStrategy*);
	void displayInfo();

private:
	vector<AbstractCommand*> commands;
	AbstractParsingStrategy* aps;
};