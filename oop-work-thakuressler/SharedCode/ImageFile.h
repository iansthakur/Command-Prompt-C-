#pragma once
// Image file class declaration here
#include "AbstractFile.h"
#include <iostream>
#include <vector>

class ImageFile :public AbstractFile {
public:
	//see AbstractFile header file for info on functions
	ImageFile(string s);
	unsigned int getSize();
	string getName();
	int write(vector<char> wVec);
	int append(vector<char> aVec);
	vector<char> read();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string copy);

private:
	string name;
	vector<char> contents;
	char size;
};