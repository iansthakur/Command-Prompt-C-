#pragma once
#include "AbstractCommand.h"

class CatCommand : public AbstractCommand {
public:
	//constructor for CatCommand
	CatCommand(AbstractFileSystem*, AbstractFileFactory*);
	CatCommand(AbstractFileSystem*);
	//destructor (default works)
	~CatCommand() = default;
	//see AbstractCommand for function descriptions
	int execute(std::string);
	void displayInfo();

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};