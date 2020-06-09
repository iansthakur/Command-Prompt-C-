
#include "../../SharedCode/TextFile.h"

using namespace std;


int main()
{
	TextFile tf("hello");
	AbstractFile *a = &tf;
	/*vector<char> charVec;
	charVec.push_back('h');
	charVec.push_back('i');
	a->write(charVec);
	vector<char> charVecTwo;
	charVecTwo.push_back('x');
	charVecTwo.push_back('y');
	charVecTwo.push_back('z');
	a->write(charVecTwo);

	a->read();*/
	
	

	return 0;
}
