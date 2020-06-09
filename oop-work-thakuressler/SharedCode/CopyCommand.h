#pragma once
#include "AbstractCommand.h"

class CopyCommand : public AbstractCommand {
public:
	//see AbstractCommand header file for info on functions
	CopyCommand(AbstractFileSystem*, AbstractFileFactory*);
	CopyCommand(AbstractFileSystem*);
	~CopyCommand() = default;
	int execute(std::string);
	void displayInfo();

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};