#include "RemoveCommand.h"
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* copyAFS, AbstractFileFactory* copyAFF) //constructor
{
	afs = copyAFS;
	aff = copyAFF;
}

RemoveCommand::RemoveCommand(AbstractFileSystem* copyAFS) //additional constructor
{
	afs = copyAFS;
	aff = nullptr;
}



int RemoveCommand::execute(std::string s)
{
	return afs->deleteFile(s);//return the result of attempting to deltee teh file (0 if success)
}

void RemoveCommand::displayInfo()
{
	cout << "deletes file from directory" << endl;
}
