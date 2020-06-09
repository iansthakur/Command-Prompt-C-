#include "CopyCommand.h"
#include <sstream>
#include <istream>
using namespace std;
CopyCommand::CopyCommand(AbstractFileSystem* copyAFS, AbstractFileFactory* copyAFF)
{
	aff = copyAFF;
	afs = copyAFS;
}

CopyCommand::CopyCommand(AbstractFileSystem* copyAFS)
{
	afs = copyAFS;
	aff = nullptr;
}

int CopyCommand::execute(std::string oldAndNew)
{
	string old;
	string copy;
	string lengthTest;
	istringstream iss(oldAndNew); //store string passed into the function into i string
	iss >> old;//set old equal into the first word in the i stream
	iss >> copy;//set copy equal to next word in the iterator
	if (iss >> lengthTest) {//if there are more words in the i stream it is an invalid input(too many arguments)
		return invalidCopyInput;
	}
	if (copy == old) {//if the file that is to be created has the same name as the prev file add 2 to the name of the copy file
		old += '2';
	}
	if (copy == "") {
		return copyCommandNoSecondFile;
	}
	AbstractFile* af = afs->openFile(old);//open the file that is being copied, store its pointer in af
	if (af == nullptr) {//if openFile() returned nullptr there was an issue copying the file (likely bc it dne)
		return cannotCopy;
	}
	AbstractFile* newFile = af->clone(copy);//call clone function on old file, use the new files name as clones parameter
	int varOne = afs->closeFile(af);//the files so that they can be opened in other functinos
	int varTwo = afs->closeFile(newFile);
	/*if (varOne != 0 || varTwo != 0) {
		return issueWithClosingFileCopyCommand;
	}*/
	return afs->addFile(newFile->getName(), newFile);//add the new file to file system, return 0 if successful
}

void CopyCommand::displayInfo()
{
	cout << "makes a deep copy of the first argument titled the second argument" << endl;
}
