//  Define the TextFile class here
#include "TextFile.h"

using namespace std;

TextFile::TextFile(string s) { //constructor
	name = s;
}

//changed func from studio
/*void TextFile::read() {
	for (char i: contents) {
		cout << i;
	}

}*/

vector<char> TextFile::read() {
	return contents;//return the contents of the file
}

int TextFile::write(vector<char> wVec) {
	contents = wVec;//make the files contents into the vector of chars passed into the func and return success
	return success;
}

int TextFile::append(vector<char> aVec) {
	for (int i = 0; i < aVec.size(); ++i) {//add the contents of the vector passed into the function to the end of the files contents
		contents.push_back(aVec[i]);
	}
	return success;
}

unsigned int TextFile::getSize() {
	size_t x = contents.size();
	return (int)x;
}

string TextFile::getName() {
	return name;
}

void TextFile::accept(AbstractFileVisitor* afv)
{
	//call visit_TextFile() to print out filees contents
	afv->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string copy)
{
	copy += ".txt";//add .txt suffix to new files name
	AbstractFile* copyFile = new TextFile(copy);//create new file with name passed into function
	copyFile->write(this->read());//copy original files contents into new file
	
	return copyFile;//return pointer to new file
}
