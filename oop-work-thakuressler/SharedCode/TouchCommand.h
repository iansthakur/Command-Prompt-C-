#pragma once
#include "AbstractCommand.h"
#include "PasswordProxy.h"


class TouchCommand : public AbstractCommand {
public:
	//see AbstractCommand header file for info on functions
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	~TouchCommand() = default;
	int execute(std::string);
	void displayInfo();

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};