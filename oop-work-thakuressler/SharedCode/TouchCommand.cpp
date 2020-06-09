#include "TouchCommand.h"
#include <sstream>
#include <istream>
TouchCommand::TouchCommand(AbstractFileSystem* setAFS, AbstractFileFactory* setAFF)//constructor
{
	afs = setAFS;
	aff = setAFF;
}

int TouchCommand::execute(std::string name)
{
	istringstream iss(name);//crete istring stream of the string passed into execute
	string holding;//string that will hold indivual words in name
	int counter = 0;//counts how many argumens are passed into execute (number of words)
	while (iss >> holding) {//keep inc counter as long as you can keep pushing new word into holding
		++counter;
	}
	if (counter > maxArguments) {//if there are more than max (2) words in string name return fail enum
		return invalidTouchInput;
	}
	//proper number of arguments were passed into fucntion
	int spc = (int) name.find(' '); //find the space if there is one
	bool pass = false;//bool to determine if file should be pssword protected (-p is second word)
	if (name.substr((size_t)spc + (size_t)nextWord) == "-p") {//if the second word in the string is -p
		pass = true;//change pass to true indicaating that file should be passwrod protected
		int space = (int)name.find(' ');//see spc note
		name = name.substr(beginning,space);//change name to just the file name to be created
	}
	AbstractFile* af = 	aff->createFile(name);//create a file using name as the filename
	if (af == nullptr) {//if af is nullptr createfill was unsuccessful probably bc the file name is invalid (doesnt have a valid extension(suffix)) or a file by that name already exists
		return CannotCreateNewFile;//return failure value for this issue
	}
	int suc;//int storing value of addFile() call, will be 0 if success
	if (pass) {//file should be password protected
		//prompt user for password and store it in password
		string password = "";
		cout << "What is the password?" << endl;
		cin >> password;
		PasswordProxy* pwp = new PasswordProxy(af, password);//use password proxy constructor to create password protected file 
		suc = afs->addFile(name, pwp);//attempt to add passowrd protected file to directory, store reuslt in suc (willbe 0 if success)
	}
	else {//file not password protected
		suc = afs->addFile(name, af);//attempt to add file to directory, store result in suc
	}
	
	if (suc != success) {//if suc is not 0 (it failed to add to directory(file system))
		delete af;//delete teh pointer ot the file
		return TCFailedToAddFile;//return falure value
	}
	return success;//return success if suc was 0
}

void TouchCommand::displayInfo()//prints out what touchCommand does
{
	cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
	cout << "use -p to set a password for the text file" << endl;
}
