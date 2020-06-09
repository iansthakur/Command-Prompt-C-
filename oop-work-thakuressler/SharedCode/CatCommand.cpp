#include "CatCommand.h"

CatCommand::CatCommand(AbstractFileSystem* copyAFS, AbstractFileFactory* copyAFF)
{
	afs = copyAFS;
	aff = copyAFF;
}

CatCommand::CatCommand(AbstractFileSystem* copyAFS)
{
	afs = copyAFS;
	aff = nullptr;
}

int CatCommand::execute(std::string name)
{
	//finds the space in between parameter (name of file to be modified) and any other strings
	int spc = (int)name.find(' '); 
	bool read = false; //boolean used to determine if -a suffix was added
	if (name.substr((size_t)spc + (size_t)nextWord) == "-a") {//checks to see if string after file name is -a
		read = true;//if -a is add real is true meaning that the files contents should be printed
		int space = (int)name.find(' '); //see spc note
		name = name.substr(beginning, space);//change file's name to just string before suffix
	}
	AbstractFile* af = afs->openFile(name);//open the file and store the pointer to the file
	if (af == nullptr) {// if open returns nullptr it didnt work because the file does not exist
		return catFileDNE;
	}
	if (read) { //-a was at end of string, so print out contents and APPEND
		vector<char> toRead = af->read();//store the contents of the image file into toRead
		for (auto c : toRead) {//print out contents of the image file 
			cout << c;
		}
		cout << endl;//just spacing 
	}
	cout << "Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving." << endl;
	string input;
	string total;
	int counter = 0;
	do {//get the data to be added to the file
		getline(cin, input); //gets the entire line (including white space) and store it in input
		++counter;
		if (input != ":wq" && input != ":q") {//test to see if input is the stop writing "key"
			if (counter > 1) {
				total += '\n';//add endline char to total so that next input starts on next line
			}
			total += input;//if input is supposed to be added to the files contents add it to total
		}
		else {
			//total += '\n';
		}
	} while (input != ":wq" && input != ":q"); //keep calling getline and adding to total until ":wq" or ":q" is input
	if (input == ":wq") {//if input is ":wq" save what was typed to the file
		//total += '\n';//add endline char to total so that next input starts on next line
		vector<char> toAdd(total.begin(), total.end());//convert string of the users inputs into a vector of chars
		afs->closeFile(af);//close the file so that open() can be used later on(otherwise open() will return nullptr)
		if (read) {
			return af->append(toAdd);//attempts to add inputs to the files contents--returns 0 if success
		}
		else {
			return af->write(toAdd);
		}
	}
	//if ":q" is input do NOT save
	afs->closeFile(af);//close the file so that open() can be used later on(otherwise open() will return nullptr)
	return success;
}

void CatCommand::displayInfo()
{
	cout << "The cat command writes to a file" << endl;
	cout << "-a will show what is already in the file" << endl;
}
