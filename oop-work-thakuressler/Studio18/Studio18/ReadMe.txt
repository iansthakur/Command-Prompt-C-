studio 18 answers here
1. Ian Thakur and Sydney Essker
2. It would be possible to modify our exisiting code to take in more file types, but we think their is likely a better way.
3. Pro - If you wanted to add a new type/subclass, you don't have to modify the abstract factory as long as subclass conforms to methods
the abstract class.  Con - It can be more complicated since you have to make a new class for each type that is supported by the interface.
You'd create a new concrete file class when we are supporting a new type of file. The new concrete class would have to inherit
the abstract one, and the abstract one must be able to support the file type. Yes and no for the last two questions.
4. test in main:
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



output is as expected:
abc
X X
 X
X X
5. Yes it only depends on abstract file type, but its not as if the file type is irrelevant as it is handled in the simple file factory instead.
6. Passes all test