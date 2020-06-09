#pragma once
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"
#include <set>


class AbstractFileSystem {
public:
	//returns 0 if file is successfully added to directory
	virtual int addFile(string fileName, AbstractFile* af) = 0;
	//virtual int createFile(string fileName) = 0;
	//returns 0 if file is deleted successflly
	virtual int deleteFile(string fileName)= 0;
	//returns a pointer to teh file, adds file to open files
	virtual AbstractFile* openFile(string fileName)= 0;
	//returns 0 if file is successuflly closed
	virtual int closeFile(AbstractFile* af)= 0;
	//returns a set containing the name of the files
	virtual std::set<string> getFileNames() = 0;
};