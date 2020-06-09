#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* copyAFS, AbstractFileFactory* copyAFF) //constructor
{
	afs = copyAFS;
	aff = copyAFF;
}

LSCommand::LSCommand(AbstractFileSystem* copyAFS)//additional constructor
{
	afs = copyAFS;
	aff = nullptr;
}

int LSCommand::execute(std::string s)
{
	set<string> names = afs->getFileNames();//call getFileNames() which returns a set of the names of the created files, store this in names
	if (s != "-m" && s!="") {//if there is anything oterh than just -m or whitespace at the the all to ls it should fail
		return invalidLSInput;
	}
	else if (s == "-m") {//if JUST -m is at the end of ls display metadata
		AbstractFileVisitor* mddv = new MetadataDisplayVisitor; //create a metadatdisplay visitor 
		for (auto fileName : names) {//iterate thru set of file names
			AbstractFile* af = afs->openFile(fileName);//open the file and store a pointer to it in af
			af->accept(mddv);//display the metadata of file using pointer to it
			afs->closeFile(af);//cloes the file so that it can be used elsewhere
		}
		cout << endl;//just formating
		return success;
	}
	else {//just regular ls (nothing at end)
		bool endLine = true;//since two files are printed per line a bool that flips to determine if endline should be used
		for (auto fileName : names) {//iterate thru file names
			int fileLength = (int)fileName.length();//get the length of the file
			int padding = maxChars - fileLength;//determine how much padding is needed between the file (20 spaces between beginning of line and start of second filename)
			cout << fileName;//print out the file name
			for (int i = 0; i < padding; ++i) {//add as many spaces are needed as determined by padding
				cout << ' ';
			}
			if (endLine) {//flip bool so that a new line will not be started 
				endLine = false;
			}
			else if (endLine == false) {//flip bool so a new line will be started 
				endLine = true;
			}
			if (endLine) {//start new line bc two files have been printed on this line

				cout << endl;
			}
			
		}
		cout << endl;//formating
		return success;
	}
	//if it didnt work say it failed
	return LSExecuteFailed;
}

void LSCommand::displayInfo()
{
	cout << "List all files in the current directory" << endl;
}
