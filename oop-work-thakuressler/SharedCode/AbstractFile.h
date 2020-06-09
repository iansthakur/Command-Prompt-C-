#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <string>
#include <vector>
#include "AbstractFileVisitor.h"
using namespace std;

//enum for possible outcomes of functions
enum outcome {
	success = 0,
	invalidImgWrite = 1,
	invalidImgAppend = 2,
	PassProxyAppendFailed = 3,
	TriedToAddNullFile = 4,
	closeFileFailed = 5,
	cannotDeleteOpenFile = 6,
	PassProxyWriteFailed = 7,
	enteredDuplicateCommand = 8,
	nullCommand = 9,
	userEnteredQ = 10,
	fileNameAlreadyExists = 11,
	CannotCreateNewFile = 12,
	TCFailedToAddFile = 13,
	LSExecuteFailed = 14,
	cannotCopy = 15,
	displayFileDNE = 16,
	catFileDNE = 17,
	invalidLSInput = 18,
	invalidCatInput = 19,
	invalidDSInput = 20,
	invalidTouchInput = 21,
	invalidCopyInput = 22,
	invalidRenameInput = 23,
	fileToBeDeletedDNE = 24,
	issueWithClosingFileCopyCommand = 25,
	copyCommandNoSecondFile = 26
};

//enums for various magic numbers
enum misc{
	beginning = 0, 
	nextWord = 1,
	maxChars = 20,
	maxArguments = 2,
	ASCII_Conversion = 48,
	prev_spot = 1,
	maxNoneXorSpaceChars = 1
};

class AbstractFile {
public:
	//function that returns the contents of a file
	virtual vector<char> read() = 0;
	//returns 0 if vector of chars correctly replace the files contents
	virtual int write(vector<char> wVec) = 0;
	//returns 0 if vector of chars are correctly added to files contents
	virtual int append(vector<char> aVec) = 0;
	//returns the size of the file
	virtual unsigned int getSize() = 0;
	//returns file name
	virtual string getName() = 0;
	~AbstractFile() = default;
	//prints out contents of file
	virtual void accept(AbstractFileVisitor* afv) = 0;
	//makes a copy of the file
	virtual AbstractFile* clone(string copy) = 0;
};