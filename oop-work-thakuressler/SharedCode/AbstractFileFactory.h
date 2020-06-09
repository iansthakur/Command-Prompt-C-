#pragma once
#include "AbstractFile.h"
// studio 18 - file factory interface declared here

class AbstractFileFactory {
public:
	//creates a file, string parameter is the file name, returns pointer to that file
	virtual AbstractFile* createFile(string) = 0;
};