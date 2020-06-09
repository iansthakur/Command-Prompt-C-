// definition of ImageFile class here
#include "ImageFile.h"
using namespace std;

ImageFile::ImageFile(string s) { //constructor
	name = s;
	size = 0;
}

unsigned int ImageFile::getSize() //returns size of image file contents
{
	return (unsigned int)contents.size();
}

string ImageFile::getName() //returns name
{
	return name;
}

int ImageFile::write(vector<char> wVec)
{
	int count = 0;//var used to count how many times an invalid char non 'X' or ' ' (or the side length at the end) char are vect to be added
	if (wVec.size() == 0) {
		return 100;
	}
	char x = wVec[wVec.size()- prev_spot];//grab the last char in the vec (an int indidcating side length)
	int intSize = x - ASCII_Conversion;//convert from char to int see ASCII table
	for (char c : wVec) {//iterate thru proposed image file's contents
		if (c == 'X' || c == ' ') {//if the char is a proper image char (X or space) push back the char into contents
			contents.push_back(c);
			++size;//inc the size of the file
		}
		else {
			++count;//inc the count of the non x or space chars in vector contents
		}
	}
	if (intSize != sqrt(size)) {//if the int is not the same as the the sqrt of the isze, it is not the right int (it does not properly indicate side length of the image)
		++count;//so increase the count
	}
	if (count > maxNoneXorSpaceChars) {//if theres more than the max number of non x space chars (1)
		size = 0;//zero out size
		contents = {};//clear contents vector empty
		return invalidImgWrite;//image write is a failure so return failure value
	}
	//size is correct and chars are correct so return success
	return success;
}

int ImageFile::append(vector<char> aVec)
{
	//image files can NOT be appended to, alwasy return fail
	//Cat and any command that uses cat will NOT work for image files
	return invalidImgAppend;
}

vector<char> ImageFile::read()
{
	//this comment is left in because it was a requirement for one of the studios (read used to print out the files contents)
	/*
	int x = (int)sqrt(size);
	for (int i = x; i >= 0; --i) {
		
		for (int j = 0; j < x; ++j) {
			
			if ((i * x + j) < (x * x)) {
				int index = i * x + j;
				cout << contents[index];
			}
		}
		if (i != x) {
			cout << endl;
		}
	}
	*/ 
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* afv)
{
	//calls visit_ImageFile to print out files contents
	afv->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string copy)
{
	
	copy += ".img";//adds the .img suffix to the copy's file name bc its an image file
	AbstractFile* copyFile = new ImageFile(copy);//create an image file of copy file's name using constructor
	int outcome = copyFile->write(this->read());//write the original files contents to the copy file
	/*if (outcome != 0) {//check if write worked properly. To write to an image file, file must be formatted correctly.
		return nullptr;
	}*/
	return copyFile;//return a pointer to the copied file
}

