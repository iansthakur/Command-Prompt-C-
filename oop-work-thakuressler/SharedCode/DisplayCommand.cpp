#include "DisplayCommand.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* copyAFS, AbstractFileFactory* copyAFF)
{
	afs = copyAFS;
	aff = copyAFF;
}

DisplayCommand::DisplayCommand(AbstractFileSystem* copyAFS)
{
	afs = copyAFS;
	aff = nullptr;
}

int DisplayCommand::execute(std::string name)
{
	//finds the space in between parameter (name of file to be modified) and any other strings
	int spc = (int)name.find(' ');
	bool format = false;//boolean used to determine if -d suffix was added
	if (name.substr((size_t)spc + (size_t)nextWord) == "-d") {//checks to see if string after file name is -a
		format = true;//if -a is add real is true meaning that the files contents should be printed
		int space = (int)name.find(' ');//see spc note
		name = name.substr(0, space);//change file's name to just string before suffix
	}
	AbstractFile* af = afs->openFile(name);//open the file and store the pointer to the file
	if (af == nullptr) {// if open returns nullptr it didnt work because the file does not exist
		return displayFileDNE;
	}
	BasicDisplayVisitor bdv;//initialize basic display visitor for displaying file (2 lines)
	AbstractFileVisitor* afv = &bdv;

	if (format) {//not formated (-d was at end)
		vector<char> toPrint = af->read();//store the contents of the image file into toRead
		for (auto c : toPrint) {//print out contents of the image file 
			cout << c;
		}
	}
	else {//formated (no -d)
		af->accept(afv);//call void function accept to print out contents of file
	}
	cout << endl;//formating
	afs->closeFile(af);//close the file so that open() can be used later on(otherwise open() will return nullptr)
	return success;
}

void DisplayCommand::displayInfo()
{
	cout << "displays contents of an image file" << endl;
	cout << "-d displays the unformated version" << endl;
}
