#include "BasicDisplayVisitor.h"
#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

// definitions of basic display visitor here

void BasicDisplayVisitor::visit_TextFile(TextFile* tf)
{
	for (char i : tf->read()) {//prints out contents of vector<char> returned by read()
		cout << i;
	}
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* tf)
{
	int x = (int)sqrt(tf->getSize()); //image size is equal  to area so take sqrt to get side length (x)
	for (int i = x; i >= 0; --i) { //row of image print out

		for (int j = 0; j < x; ++j) { //col of image print out

			if ((i * x + j) < (x * x)) { //checks to make sure index for spot is within image contents bounds
				int index = i * x + j; //index to get char in image file contents for given x,y coordinate
				cout << tf->read()[index]; //prints out content at index
			}
		}
		if (i != x) { //ends the line so that next line can be printed
			cout << endl;
		}
	}
}

