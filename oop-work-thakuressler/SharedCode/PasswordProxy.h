#pragma once
#include "AbstractFile.h"

using namespace std;

class PasswordProxy : public AbstractFile {
public:
	//see AbstractFile header file for info on functions
	PasswordProxy(AbstractFile*, string);
	~PasswordProxy();
	vector<char> read();
	int write(vector<char> wVec);
	int append(vector<char> aVec);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string copy);

protected:
	//prompts user for file passowrd
	string passwordPrompt();
	//compares string user inputs (via passwordPrompt() method) to passwords actual password
	//returns true if it matches
	bool checkPassword(string);

private:
	AbstractFile* af;
	string s;

};