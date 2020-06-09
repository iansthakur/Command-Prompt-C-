#include "PasswordProxy.h"
#include <iostream>

PasswordProxy::PasswordProxy(AbstractFile* af, string s): af(af), s(s) //constructor
{
}

PasswordProxy::~PasswordProxy() //deconstructor
{
	delete af;
}

vector<char> PasswordProxy::read()
{
	string toTest = passwordPrompt();//call password prompt and store result in toTest
	bool tested = checkPassword(toTest);//call checkPassword on user entered password (toTest) and store result in tested
	if (tested) {//if tested is true (password is correct) return the files contents as a vector of chars
		return af->read();
	}
	return vector<char>();//if password is incorrect return empty vector
}

int PasswordProxy::write(vector<char> wVec)
{
	string toTest = passwordPrompt();//call password prompt and store result in toTest
	bool tested = checkPassword(toTest);//call checkPassword on user entered password (toTest) and store result in tested
	if (tested) {//if tested is true (password is correct) attempt to write to the file and return the result of that call (will be 0 if success)
		return af->write(wVec);
	}
	return PassProxyWriteFailed;//password is incorrect
}

int PasswordProxy::append(vector<char> aVec)
{
	string toTest = passwordPrompt();//call password prompt and store result in toTest
	bool tested = checkPassword(toTest);//call checkPassword on user entered password (toTest) and store result in tested
	if (tested) {//if tested is true (password is correct) attempt to append to the file and return the result of that call (will be 0 if success)
		return af->append(aVec);
	}
	return PassProxyAppendFailed;//password is incorrect
}

unsigned int PasswordProxy::getSize()
{
	return af->getSize();
}

string PasswordProxy::getName()
{
	return af->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv)
{
	string toTest = passwordPrompt();//call password prompt and store result in toTest
	bool tested = checkPassword(toTest);//call checkPassword on user entered password (toTest) and store result in tested
	if (tested) {//if tested is true (password is correct) attempt to call accept on the file
		return af->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(string copy)
{
	AbstractFile* pwp = new PasswordProxy(af->clone(copy), s);//create a password proxy of the cloned file and return it
	return pwp;
}

string PasswordProxy::passwordPrompt()
{
	cout << "enter password for the file: " << endl;//prompt user for password
	string pw;
	cin >> pw;//store user input in pw and return that string
	return pw;
}

bool PasswordProxy::checkPassword(string testing)
{
	if (testing == s) {//compares string to file's password
		return true;//is the password so return true
	}
	return false;//is not the password so return false
}
