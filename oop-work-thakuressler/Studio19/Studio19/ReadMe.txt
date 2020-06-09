studio 19 answers here
1. Ian Thakur Sydney Essler
2. 

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

	vector<char> copy;
	vector<char> copy2;
	copy = one->read();
	copy2 = two->read();

	for (char c : copy) {
		cout << c;
	}
	cout << endl;
	for (char c : copy2) {
		cout << c;
	}

output: abc
X X X X X (as expected)

added this to the end:
one->write(Vec2);
	two->write(charVec);

	copy = one->read();
	copy2 = two->read();

	for (char c : copy) {
		cout << c;
	}
	cout << endl;
	for (char c : copy2) {
		cout << c;
	}

	output:
	X X X X X3 (as expected)

3. This visitor is able to get access to a specific concrete class by using the accept method. This method gives the visior a 
pointer to the specific concrete class object and allows it to specialize implementations of a given function for the specific 
concrete typr.

4. The visitor pattern passes a pointer from the sender of the function to the reciever which gives the reciever access to the 
sender's state. The reciever then executes a member function of an object using the state that was passed to it as a pointer to the 
sender.

5. It might be a bad idea to use this if you have a very large number of types of filed because you would have to make a new 
function for each contrete class in the metadisplay visitor. 

6. Code passes all unit tests.
END STUDIO 19

STUDIO 20:

2. If we dont delete the pointer then there could be a memory leak since it is dynamically allocated (using new).
3. complete. 
4.
We called write read and accept on the ImageFile we created using the password protected functions.
To call accept we had to create a MetadataDisplayVisitor which was used as the paramter for accept.
All functions returned as expected. (We also printed out the contents of the vector returned by read to
ensure that it was the expected result)
enter password
a
enter password
a
X X X X X
enter password
a
thisFileIMG.img 9 image

5.Passes all unit tests.
END STUDIO 20

STUDIO 21:

2. Base class deconstructors only destroy base class objects. Objects that inherit from the base class might
not destory the same things, so the base class needs this to prevent memory leaks.

3.Because CommandPrompt is not specific to the file/ filesystems it can be used for different files/ filesystems.
Thus, it is dependent on the file/ filesystem/ file factory objects. It can be easily configured to use 
different file system implementations and different file factory implementations required to create the file 
types instead of the simple file system and its associated factory object.

4.
Test 1:
Tested help, help TouchCommand, and q. All worked as expected
Output:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help
TouchCommand
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help TouchCommand
touch creates a file, touch can be invoked with the command : touch <filename>
no command exists
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  q

--End test 1--

Test 2:
tested touch. create new file called new.txt, then wrote to the file and read it.
worked as expected

code:
AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* aff = new SimpleFileFactory();
	//cout << &aff << endl;
	AbstractCommand* tc = new TouchCommand(sfs, aff);
	CommandPrompt* cp = new CommandPrompt();
	cp->setFileFactory(aff);
	cp->setFileSystem(sfs);
	cp->addCommand("touch", tc);
	cp->run();
	cout << endl;
	AbstractFile* nf = sfs->openFile("new.txt");
	vector<char> Vec2 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	nf->write(Vec2);
	vector<char> toPrint = nf->read();
	for (auto c : toPrint){
		cout << c;
	}

output:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch new.txt
new.txt
returned 0
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  q

X X X X X3

--end test 2--

5. code passes all unit tests

END Studio 21

______________________________________________________________________________________


BEGIN Lab 5:

Ian Thakur and Sydney Essler

Work Distribution:
On all of the studios (16-19) we worked together over zoom. Although only one person could code at a time, we screenshared and 
took turns on who was coding. For Lab 5, we continued to work on the coding using this method. The only parts that we split up
were writing comments through the code (Ian did this) and doing test cases (Sydney did this). 
 
Errors/Issues: 
 - We had some minor issues with casting ints/size_t objects to get rid of warnings. 
 - We accidently included a header file when it should have been a source file in the unit test file, so we had to fix it and make sure it
 only inlcuded source files.
 - Another issue we had was accidently having a circular include involving AbstractFileVisitor, so we forward declared the necessary
 classes to fix the circular include issue.
 - We had difficulty getting the metadatadisplay to work because we were trying to manually determine if a file was a 
 text file or an image file instead of calling accept on a abstract file and using the correct syntax to get the desired information.
 - We initally did not have our copy method copy over the password corrcctly for password protected files
 - Finally, we accidently were printing out the prompt instructions twice after certain functions.

 Testing Strategy:
 We tested as we completed different commands, but also have re-tested after completing all functions of the lab. For each function,
 we will test for cases that have the correct input and incorrect input to ensure the commands work as expected for both. Additionally,
 we have tested to make sure each function's help print out works property with correct and incorrect input. One specific type of incorrect
 input that we made sure to test for all commands was if their is information following the command and the corresponding input. For example,
 if the command only needs one file name, we determined it should fail if there is additional input that should not be there following the file
 name. This is because when we use a command line, this is the case. Here is what we had in main to run our tests:

 //Studio 21 and Lab 5 Stuff:
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* aff = new SimpleFileFactory();

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

	

 Test Cases: 


 TESTING FOR LS:

 correct input:

 $  ls
a.txt               b.txt
c.txt               pass.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls -m
a.txt 0 text
b.txt 0 text
c.txt 0 text
enter password for the file:
1
pass.txt 0 text
thisFileIMG.img 9 image

ls works as anticiapted with valid input, and ls - m works as anticipated including cases in which there are password protected files.


incorrect input:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls extrastuff
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls a.txt
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  before ls
Command does not exist
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls -m extra stuff
failed

ls and ls -m work as anticipated with invalid inputs


help:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help ls
List all files in the current directory
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help ls stuff
Command does not exist
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ 

correct outcome for both valid and invalid calls to ls



TESTING FOR REMOVE COMMAND:

correct input: 

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.txt               b.txt
pass.txt            thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm a.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
b.txt               pass.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm pass.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
b.txt               thisFileIMG.img

(following input below is different from set of cases above)

$  ls
a.img               img2.img
newFile.txt         pass.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm a.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
img2.img            newFile.txt
pass.txt            thisFileIMG.img

works correctly for valid inputs (image, text and password protected files)


Invalid inputs:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
b.txt               thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm c.txt
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm b.txt dfhasdkfsdkf
failed

correctly reported failed for invalid inputs (no file given, file that does not exist, and string after the file)

help:

$  help rm
deletes file from directory
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help rm extra
Command does not exist

correctly works for valid and invalid forms of help rm. 



TESTING FOR TOUCH COMMAND (and touch command -p):

valid inputs:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch newFile.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
newFile.txt         thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch pass.txt -p
What is the password?
1234
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
newFile.txt         pass.txt
thisFileIMG.img

$  touch a.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.img               newFile.txt
pass.txt            thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch img2.img -p
What is the password?
1
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.img               img2.img
newFile.txt         pass.txt
thisFileIMG.img

works as expected for proper inputs (both image and text files and password protected files)


invalid inputs:

$  ls
newFile.txt         pass.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch newFile.txt
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch newFile.txt -p
What is the password?
1234
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch filex.txt jsdfkdjfkfj
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch filex.txt -p jfjdfjfdjsjf
failed

Responded correctly to invalid inputs (stuff following file name, trying to make files that already exist)


help:

$  help touch
touch creates a file, touch can be invoked with the command : touch <filename>
use -p to set a password for the text file
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help touch fjjf
Command does not exist

help touch works for valid and invalid cases.




CAT COMMAND TESTS (and cat -a):

correct input:

text file:
$  cat a.txt
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
1
2
3
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat a.txt -a
1
2
3

Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
4
5
6
:q
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat a.txt -a
1
2
3

image file:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat b.img
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
stuff
:wq
failed

password protected files(both text and image):
$  touch text.txt -p
What is the password?
1
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch image.img -p
What is the password?
2
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat text.txt
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
1 2 3
:wq
enter password for the file:
1
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat text.txt -a
enter password for the file:
1
1 2 3

Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
4 5 6
:q
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat text.txt -a
enter password for the file:
1
1 2 3

Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
:q
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat image.img
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
input stuff
:wq
enter password for the file:
2
failed

all valid inputs work as expected


invalid inputs:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat text.txt -a
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat text.txt
failed

$  ls
a.txt               text.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat a.txt kfjfjfj
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat a.txt -a jfkfjkls
failed

invalid inputs behave as expected


help:
$  help cat
The cat command writes to a file
-a will show what is already in the file
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help cat fjkfdj
Command does not exist

help works properly


DISPLAY COMMAND TESTS:

valid input:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch a.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat a.txt
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
abcdefg
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds a.txt
abcdefg

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds a.txt -d
abcdefg

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.txt               thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds thisFileIMG.img
X X
 X
X X

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds thisFileIMG.img -d
X X X X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch pass.txt -p
What is the password?
1
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds pass.txt
enter password for the file:
1

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

valid inputs behave as expected.

invalid inputs:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds text.txt
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds text.txt -d
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds thisFileIMG.img jflksdjf
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds thisFileIMG.img -d jkjf
failed

invalid inputs behave as expeccted.

help:
$  help ds
displays contents of an image file
-d displays the unformated version
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help de dsfjf
Command does not exist

help works as it should.


COPY COMMAND TESTS:

valid input:
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch a.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch b.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch pass.txt -p
What is the password?
123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp a.txt c
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.txt               b.txt
c.txt               pass.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp a.txt d
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.txt               b.txt
c.txt               d.txt
pass.txt            thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp pass.txt e
enter password for the file:
123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.txt               b.txt
c.txt               d.txt
e.txt               pass.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp thisFileIMG.img newIMG
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
a.txt               b.txt
c.txt               d.txt
e.txt               newIMG.img
pass.txt            thisFileIMG.img

works for all valid inputs tested.

invalid inputs:

$  ls
a.txt               b.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp a.txt b
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp ksdjfksdjf
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp a.txt c jfksjfls
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.


$  cp a.txt
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp a.txt a
failed
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp a.txt a.txt
failed

failed for invalid inputs as expected 

help:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help cp
makes a deep copy of the first argument titled the second argument
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help cp jjdjd
Command does not exist

help works as it should.


RENAME COMMAND TESTS:

valid input:

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch img.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp img.txt hello
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
hello.txt           img.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn hello.txt hi
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
hi.txt              img.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
hi.txt              img.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn thisFileIMG.img real
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
hi.txt              img.txt
real.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp real.img near
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
hi.txt              img.txt
near.img            real.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp real.img happy
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
happy.img           hi.txt
img.txt             near.img
real.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds happy.img
X X
 X
X X

invalid input:

$  ls
a.txt               b.txt
thisFileIMG.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn a.txt b
failed

$  touch a.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch b.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn a.img b
failed

$  rn
failed

$  rn a.img c lkdlakdladk
failed

all invalid inputs work as expected.

help:

$  help rn
calls previously defined commands in a specific order to complete new command
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help rn jksdjfdsklf
Command does not exist

help works as expected


HELP AND Q TESTS:
 help:
 $  help
cat
cp
ds
ec
ls
rm
rn
touch

as expected

q:
as expected

Additional Tests:

Adding special characters:
$  a.txt
no command exists
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch a.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat a.txt
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
kjflkasjfklasj
" do this" ?><::::;;;;;'''';''''{[][][{}\\||+=_--!@#$%^&*()qwearjdkflksjf
fhsdkfjsklfj9839238490389(*&^%$#@#$%^&*(
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds a.txt
kjflkasjfklasj
" do this" ?><::::;;;;;'''';''''{[][][{}\\||+=_--!@#$%^&*()qwearjdkflksjf
fhsdkfjsklfj9839238490389(*&^%$#@#$%^&*(



Extra Credit:

We implemented macro commands touch+cat+ds. We did this by making a class that inherits from the abstract parsing strategy and
having the input param be placed in to a vector three times. We then added the nexessary abstract command pointers to the
macro command in main, made an EvenCrazier pointer that inherited from abstract command, and inserted it into commands. We then 
performed tests to make sure it worked properly.
Here is what we had in main:
MacroCommand* ecMC = new MacroCommand();
	AbstractParsingStrategy* EvenCrazier = new EvenCrazierParsingStrategy();
	ecMC->addCommand(tc);
	ecMC->addCommand(cat);
	ecMC->addCommand(ds);
	ecMC->setParseStrategy(EvenCrazier);
	AbstractCommand* ec = ecMC;
	CommandPrompt* cp = new CommandPrompt();
	cp->addCommand("ec", ecMC);
	cp->run();

Here are our tests for the extra credit:

help:

$  help ec
calls previously defined commands in a specific order to complete new command
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Running with invalid and valid input:

$  ls
a.txt               thisFileIMG.img

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ec a.txt
failed
$  ec b.txt
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
ksdflsdkjfsdf
:wq
ksdflsdkjfsdf

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds b.txt
ksdflsdkjfsdf

$  ec a.img
Input data to append to the file. Input :wq to save and quit, or input :q to quit without saving.
imageinfo
:wq
failed

$  ec c.txt jfksdjfkdsf
failed



all worked as expected.



