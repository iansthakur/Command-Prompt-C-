#pragma once
// declaration of SimpleFileSystem class goes here
#include <map>
//#include <set>
#include "AbstractFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iterator>
using namespace std;



class SimpleFileSystem : public AbstractFileSystem {
public:
	//see AbstractFileSystem header file for info on functions
	int addFile(string fileName, AbstractFile* af);
	//int createFile(string fileName);
	int deleteFile(string fileName);
	AbstractFile* openFile(string fileName);
	int closeFile(AbstractFile* af);
	std::set<string> getFileNames();
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;

};