// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../..//SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include <iostream>

int main()
{
	AbstractFileSystem *t = new SimpleFileSystem;
	AbstractFileFactory *aff = new SimpleFileFactory;

	AbstractFile *one = aff->createFile("thisFileTXT.txt");
	AbstractFile* two = aff->createFile("thisFileIMG.img");

	vector<char> charVec = { 'a', 'b', 'c' };
	vector<char> Vec2 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };

	t->addFile("thisFileTXT.txt", one);
	t->addFile("thisFileIMG.img", two);

	t->openFile("thisFileTXT.txt");
	t->openFile("thisFileIMG.img");

	one->write(charVec);
	two->write(Vec2);

	one->read();
	cout << endl;
	two->read();

	

	


	

}

