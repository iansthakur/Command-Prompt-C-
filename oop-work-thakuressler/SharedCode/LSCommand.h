#pragma once
#include "AbstractCommand.h"


class LSCommand : public AbstractCommand {
public:
	//see AbstractCommand header file for info on functions
	LSCommand(AbstractFileSystem*, AbstractFileFactory*);
	LSCommand(AbstractFileSystem*);
	~LSCommand() = default;
	int execute(std::string);
	void displayInfo();

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};