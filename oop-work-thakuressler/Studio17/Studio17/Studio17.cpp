

#include <iostream>
#include "../../SharedCode/ImageFile.h"

int main()
{
	
	std::string fileName = "FileName.img";
	ImageFile t(fileName);
	std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	//Assert::AreEqual(t.write(v), 0);
	cout << t.write(v) << endl;
	return 0;
}
