#pragma once
#include "AbstractCommand.h"

class RemoveCommand : public AbstractCommand {
public:
	//see AbstractCommand header file for info on functions
	RemoveCommand(AbstractFileSystem*, AbstractFileFactory*);
	RemoveCommand(AbstractFileSystem* copyAFS);
	~RemoveCommand() = default;
	int execute(std::string);
	void displayInfo();

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};