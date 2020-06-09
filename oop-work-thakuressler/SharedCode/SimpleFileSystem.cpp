#include "SimpleFileSystem.h"


// define methods of SimpleFileSystem class here

int SimpleFileSystem::addFile(string fileName, AbstractFile* af)
{
		map<string, AbstractFile*>::iterator it = files.begin();//iterator for map of files

		while (it != files.end())//iterat thru files map to determine if file already exists
		{
			string word = it->first;//set word equal to current string in map
			if(word == fileName) {//if the proposed file name already exists return failure enum indicating that file by that name already exists
				return fileNameAlreadyExists;
			}

			it++;//inc iterator
		}
	
	if (af == NULL) {//if filepoint er is null return failur enum for null file
		return TriedToAddNullFile;
	}
	else {//everything is correct so add the file to the file system (the map)
		files.insert(pair<string, AbstractFile*>(fileName, af));
	}

	return success;
}
//commented out function that was used in a studio
/*
int SimpleFileSystem::createFile(string fileName)
{
	map<string, AbstractFile*>::iterator it = files.begin();

	while (it != files.end())
	{
		string word = it->first;
		if (word == fileName) {
			return 3;
		}

		it++;
	}

	bool isSuffix = false;
	string suffix = "";
	for (char c : fileName) {
		if (c == '.') {
			isSuffix = true;
		}
		else if (isSuffix) {
			suffix += c;
		}
	}

	if (suffix == "txt") {
		TextFile *tf = new TextFile(fileName);
		addFile(fileName, tf);
		return 0;
	}

	if (suffix == "img") {
		ImageFile* imgf = new ImageFile(fileName);
		addFile(fileName, imgf);
		return 0;
	}

	return 5;

}
*/

AbstractFile* SimpleFileSystem::openFile(string fileName)
{
	map<string, AbstractFile*>::iterator it = files.begin();//iterator to iterate thru map of files

	while (it != files.end())//iterate thru file names
	{
		string word = it->first;//set word equal to string at iterator spot
		if (word == fileName) {//if the file exists (is in the map)
			for (AbstractFile* af : openFiles) {//iterate thru the open files to ee if file is already open
				if (af == it->second) {//if the file is already open return nullptr
					return nullptr;
				}
			}
			//files is not open so open the file, add it ot the set? of open files, and return a pointer to the file
			openFiles.insert(it->second);
			return it->second;
		}

		it++;//inc the iterator
	}
	//file dne so return nullptr
	return nullptr;
	
}

int SimpleFileSystem::closeFile(AbstractFile* af)
{
	for (AbstractFile* a : openFiles) {//iterate thru set of open files to see if file isopen
		if (a == af) {//if the files is open close it and return success
			openFiles.erase(a);
			return success;
		}
	}
	return closeFileFailed;//if file is not open (could also be file dne)
}

std::set<string> SimpleFileSystem::getFileNames()
{
	map<string, AbstractFile*>::iterator it = files.begin();//iterate thru map of files
	std::set<string> toReturn;//set of files that will eb returned by the funtion
	while (it != files.end())//iterate thru the map of files ot get the file names
	{
		string word = it->first;//set word equal to the string corresponding to ta file name at this iterator spot
		toReturn.insert(word);//add it to the set containing file names (see aboce)
		it++;//inc the iterator
	}
	return toReturn;//return the set containing the files in the file system
}

int SimpleFileSystem::deleteFile(string fileName)
{
	map<string, AbstractFile*>::iterator it = files.begin();//iterate thru map of files

	while (it != files.end())//iterate thru the map of files ot get the file names
	{
		string word = it->first;//set word equal to the string corresponding to ta file name at this iterator spot
		if (word == fileName) {//if the file to be deleted is in a file in the file system
			for (AbstractFile* af : openFiles) {//loop thru open files set to see if file is already open
				if (af == it->second) {//if the file is open return failure value(can not delete open file)
					return cannotDeleteOpenFile;
				}
			}
			//file is not open, so delete it and return success
			delete it->second;
			files.erase(it);
			return success;
		}

		it++;//inc iterator
	}
	//file is not in file system
	return fileToBeDeletedDNE;
}
