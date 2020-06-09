#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"

// studio 18 - simple file factory definitions

AbstractFile* SimpleFileFactory::createFile(string fileName)
{
	
	bool isSuffix = false;//bool detrmining if the file that is to be created has a suffix (ex: .txt)
	string suffix = "";//string that stores the suffix
	for (char c : fileName) {//iterate thru the file name
		if (c == '.') {//find the .
			isSuffix = true;//if it has a . then it has a suffix
		}
		else if (isSuffix) {//if it has a suffix start storing the extensino 
			suffix += c;
		}
	}

	if (suffix == "txt") {//if its a text file create a new textfile and return its pointer
		TextFile* tf = new TextFile(fileName);
		return tf;
	}

	if (suffix == "img") {//if its a img file create a new imagefile and return its pointer
		ImageFile* imgf = new ImageFile(fileName);
		return imgf;
	}

	return nullptr;//if its not a txt or img file return nullptr
}
