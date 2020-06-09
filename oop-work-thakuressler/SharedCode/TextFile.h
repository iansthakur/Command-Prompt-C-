#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
#include <iostream>
#include <vector>
using namespace std;

class TextFile: public AbstractFile {
public:
	//see AbstractFile header file for info on functions
	TextFile(string s);
	vector<char> read();
	int write(vector<char> wVec);
	int append(vector<char> aVec);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string copy);

private:
	vector<char> contents;
	string name;
};