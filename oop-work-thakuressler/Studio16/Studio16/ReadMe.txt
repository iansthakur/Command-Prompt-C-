Answer studio 16 questions here

1. Ian Thakur Sydney Essler Studio 16
2. a) To declare an interface, you must first have a class that will be the interface. Then, after creating a method or
multiple methods that inherit the interface, you connect them to the interface with the following syntax:
class BaseClass{
public:
//functions, it is possible for them to be virtual or pure virtual
protected: (sometimes protected - not always. Depends on situation)
//variables are protected
}

class DerivedClass : public BaseClass{
public:
//functions including functions that you overload
private:
//variabels should be private
}

3a) interface inheritance since it inherents publically
3b) private

4. Nothing in the write or append: no output
Something in the write: output as expected
something in the write and something in the append: output as expected
something in the write and then another something in the write: output as expected

5. Nothing in the write or append: no output
Something in the write: output as expected
something in the write and something in the append: output as expected
something in the write and then another something in the write: output as expected

Main function:
TextFile tf("hello");
	AbstractFile *a = &tf;
	vector<char> charVec;
	charVec.push_back('h');
	charVec.push_back('i');
	a->write(charVec);
	vector<char> charVecTwo;
	charVecTwo.push_back('x');
	charVecTwo.push_back('y');
	charVecTwo.push_back('z');
	a->write(charVecTwo);
	a->read();
	return 0;

	6. Passed all tests.
