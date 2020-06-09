#pragma once
#include "AbstractFileFactory.h"
// Studio 18 - simplefilefactory class declaration goes here

class SimpleFileFactory : public AbstractFileFactory {
public:
	//see AbstractFileFactory header file for info on functions
	AbstractFile* createFile(string);
};