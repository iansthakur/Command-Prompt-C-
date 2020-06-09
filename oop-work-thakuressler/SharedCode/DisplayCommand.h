#pragma once
#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"

class DisplayCommand : public AbstractCommand {
public:
	//see AbstractCommand header file for info on functions
	DisplayCommand(AbstractFileSystem*, AbstractFileFactory*);
	DisplayCommand(AbstractFileSystem*);
	~DisplayCommand() = default;
	int execute(std::string);
	void displayInfo();

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};