#include "CommandPrompt.h"

using namespace std;

CommandPrompt::CommandPrompt() //constructor
{
	afs = nullptr;
	aff = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* set) //sets afs variable
{
	afs = set;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* set) //sets aff variable
{
	aff = set;
}

int CommandPrompt::addCommand(std::string name, AbstractCommand* command)
{
	//create iterator to iterate thru map containing command names/ commands
	map<string, AbstractCommand*>::iterator it = m.begin();
	
	//iterate thru map to see if command by name passed into function is already in the map
	while (it != m.end())//iterate thru the map until it reaches the maps end
	{
		string word = it->first;//set word equal to string in iterator
		if (word == name) {//if word is equal to name a command by that name already exists
			return enteredDuplicateCommand;
		}
		
		it++;//increment the iterator to the next command in the map
	}
	if (command == NULL) {//if the command passed into the function is null 
		return nullCommand;
	}
	else {//everything is goood (command can be added successfully)
		m.insert(pair<string, AbstractCommand*>(name, command));//add the command (string and pointer to command) to the map
		return success;
	}
}

int CommandPrompt::run()
{
	while (1) {
		string r = prompt();//call prompt to get user input and store user input into r
		if (r == "q") {//if r is q, quit the run program and return quit value
			return userEnteredQ;
		}
		else if (r == "help") {//if r is help, return a list of all the commands
			this->listCommands();
		}
		else {//input is neither help nor q
			bool oneWord = true;//boolean to test wheter or not input is one word
			for (auto c : r) {//iterate thru r (the input) to see of there are multiple words in the input
				if (c == ' ') {//if there are multiple words, change oneWord boolean to false
					oneWord = false;
				}
			}
			if (oneWord == false) {//if input r contains more than one word
				string s = "";
				istringstream iss;
				iss.str(r);//create an istringstream containing the input r
				iss >> s;//put the first word of input r into s
				if (s=="help") { //if the first word s is help
					iss >> s;//put the second word of the input r into s
					map<string, AbstractCommand*>::iterator it = m.begin(); //create an iterator to iterate thru map of defined commands
					bool exists = false;//boolean to tell if command is defined
					while (it != m.end())//loop until iterator reaches end of map
					{
						string word = it->first; //set word equal to next word in iterator
						if (word == s) {//the word after help is the name of a defined function
							string testLength;
							if (iss >> testLength) {
								exists = false;
							}
							else {
								AbstractCommand* ac = m.at(word);//sets ac equal to the abstract command pointer associated with the name of the define function
								ac->displayInfo();//display info on that command
								exists = true;//switch exists to true bc command is defined
							}
							
						}
						it++;//increment iterator
					}
					if (exists != true) {//if command is not designed printout message
						cout << "Command does not exist" << endl;
					}

					
				}
				else {//first word is not help
					map<string, AbstractCommand*>::iterator it = m.begin();//iterator to go thru map of defined commands
					bool exists = false;//boolean indicating that the input command is defined if true
					while (it != m.end())//loop thru map
					{
						string word = it->first;//set word equal to next string in map
						if (word == s) {//word is in map
							iss >> s;//push next word in i stream into s
							string suf = "";
							//might need to add below loop to help
							while (iss >> suf) {//loop until all words in i stream are dumped into s
								s += ' ';
								s += suf;
							}
							AbstractCommand* ac = m.at(word);//set ac equal to abstractcommand pointer associated with command's name
							int suc = ac->execute(s); //calls functions execute() functions, returns true if was executed proeprly
							
							if (suc != 0) {//failed
								cout << "failed" << endl;
							}
							exists = true;//set exists equal to true bc command does exist
						}
						it++;//increment map iterator
					}
					if (exists != true) {//if command is not define print out error message
						cout << "Command does not exist" << endl;
					}
				}

			}
			else {//one word input
				map<string, AbstractCommand*>::iterator it = m.begin();//iterator for map of defined commands
				bool exists = false;//boolean true if command is defined
				while (it != m.end())//loop until iterator reaches map end
				{
					string word = it->first;//set word equal to next word in itertor
					if (word == r) {//if word equals input word
						//break;
						AbstractCommand* ac = m.at(word);//set ac equal to the abstract command pointer associated with that name
						int suc = ac->execute("");//calls execute for the command, returns 0 if successful
						exists = true;//command exists so bool should be true
						if (suc != 0) {//execute failed-- print out error message
							cout << "failed" << endl;
						}
					}
					it++;//inc iterator
				}
				if (exists == false) {//if command is not defined-- print out error message
					cout << "no command exists" << endl;
				}
			}
			
		}
		
	}
}

void CommandPrompt::listCommands()
{
	map<string, AbstractCommand*>::iterator it = m.begin();//iterator for map of commands

	while (it != m.end())//loop until end of iterator is reached
	{
		string word = it->first;//set word equal to next command name in map
		cout << word << endl;//print out name of command
		it++;//inc iterator
	}
}

std::string CommandPrompt::prompt()
{
	string prompt;
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$  ";
	std::getline(std::cin, prompt);//store the users input into prompt (includes whitespace)
	if (prompt == "") {//if prompt is empty ask for input again
		std::getline(std::cin, prompt);
	}
	return prompt;//return users input
}
