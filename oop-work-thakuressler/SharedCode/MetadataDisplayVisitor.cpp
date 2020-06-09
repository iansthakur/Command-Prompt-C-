// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"



void MetadataDisplayVisitor::visit_TextFile(TextFile* tf)
{
	string size = to_string(tf->getSize());//get the text files size
	cout << tf->getName() << " " << "text" << " " << size << endl; //print out file name and size
	

}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* tf)
{
	string size = to_string(tf->getSize());//get image file size
	cout << tf->getName() << " " <<"image" << " " << size << endl;//print out file name and size
}
