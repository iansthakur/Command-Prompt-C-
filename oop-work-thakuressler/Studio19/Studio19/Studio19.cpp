// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../..//SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include <iostream>
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../..//SharedCode/TouchCommand.h"
#include "../..//SharedCode/CommandPrompt.h"
#include "../..//SharedCode/LSCommand.h"
#include "../..//SharedCode/RemoveCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../..//SharedCode/DisplayCommand.h"
#include "../..///SharedCode/CopyCommand.h"
#include "..//..//SharedCode/MacroCommand.h"
#include "..//..//SharedCode/RenameParsingStrategy.h"
#include "..//..//SharedCode/EvenCrazierParsingStrategy.h"

int main()
{
	
	
	
	
	
	//Studio 21 and Lab 5 Stuff:
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* aff = new SimpleFileFactory();
	//cout << &aff << endl;
	AbstractCommand* tc = new TouchCommand(sfs, aff);
	AbstractCommand* ls = new LSCommand(sfs, aff);
	AbstractCommand* rm = new RemoveCommand(sfs, aff);
	AbstractCommand* cat = new CatCommand(sfs, aff);
	AbstractCommand* ds = new DisplayCommand(sfs, aff);
	AbstractCommand* copy = new CopyCommand(sfs, aff);
	
	MacroCommand* mc = new MacroCommand();
	AbstractParsingStrategy* rename = new RenameParsingStrategy();
	mc->addCommand(copy);
	mc->addCommand(rm);
	mc->setParseStrategy(rename);
	AbstractCommand* rn = mc;


	//extra credit command 
	MacroCommand* ecMC = new MacroCommand();
	AbstractParsingStrategy* EvenCrazier = new EvenCrazierParsingStrategy();
	ecMC->addCommand(tc);
	ecMC->addCommand(cat);
	ecMC->addCommand(ds);
	ecMC->setParseStrategy(EvenCrazier);
	AbstractCommand* ec = ecMC;


	CommandPrompt* cp = new CommandPrompt();
	cp->setFileFactory(aff);
	cp->setFileSystem(sfs);
	cp->addCommand("touch", tc);
	cp->addCommand("ls", ls);
	cp->addCommand("rm", rm);
	cp->addCommand("cat", cat);
	cp->addCommand("ds", ds);
	cp->addCommand("cp", copy);
	cp->addCommand("rn", rn);
	cp->addCommand("ec", ecMC);

	AbstractFile* two = aff->createFile("thisFileIMG.img");
	vector<char> Vec2 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	sfs->addFile("thisFileIMG.img", two);
	sfs->openFile("thisFileIMG.img");
	two->write(Vec2);
	sfs->closeFile(two);

	cp->run();
	cout << endl;
	//sfs->closeFile()
	//AbstractFile* nf = sfs->openFile("new.txt");
	//vector<char> Vec2 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	//nf->write(Vec2);
	/*vector<char> toPrint = nf->read();
	for (auto c : toPrint){
		cout << c;
	}*/

	

	//Studio 20 Stuff
	//AbstractFile* one = new TextFile("thisFileTXT.txt");
	//AbstractFile* two = new ImageFile("thisFileIMG.img");
	//AbstractFileVisitor* mddv = new MetadataDisplayVisitor;


	//vector<char> charVec = { 'a', 'b', 'c' };
	//vector<char> Vec2 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	//
	//

	//PasswordProxy* pwp = new PasswordProxy(two, "a");

	//pwp->write(Vec2);
	//vector<char> toPrint = pwp->read();
	//for (auto c : toPrint) {
	//	cout << c;
	//}
	//cout << endl;
	//pwp->accept(mddv);

	/*//Studio 19 Stuff
	AbstractFileSystem* t = new SimpleFileSystem;
	AbstractFileFactory* aff = new SimpleFileFactory;

	AbstractFile* one = aff->createFile("thisFileTXT.txt");
	AbstractFile* two = aff->createFile("thisFileIMG.img");

	vector<char> charVec = { 'a', 'b', 'c' };
	vector<char> Vec2 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };

	t->addFile("thisFileTXT.txt", one);
	t->addFile("thisFileIMG.img", two);

	t->openFile("thisFileTXT.txt");
	t->openFile("thisFileIMG.img");

	one->write(charVec);
	two->write(Vec2);
	
	BasicDisplayVisitor bdv;

	AbstractFileVisitor* afv = &bdv;
	
	one->accept(afv);
	two->accept(afv);

	//bdv.visit_TextFile(one);
	//bdv.visit_TextFile(two);

	vector<char> copy;
	vector<char> copy2;
	copy = one->read();
	cout << endl;
	copy2 = two->read();
	*/
	/*for (char c : copy) {
		cout << c;
	}
	cout << endl;
	for (char c : copy2) {
		cout << c;
	}
	*/
	/*one->write(Vec2);
	two->write(charVec);

	copy = one->read();
	copy2 = two->read();

	for (char c : copy) {
		cout << c;
	}
	cout << endl;
	for (char c : copy2) {
		cout << c;
	}*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
