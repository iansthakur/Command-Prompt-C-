#pragma once
// declaration of the file visitor interface here

class TextFile;
class ImageFile;
class MetaDataDisplayVisitor;

class AbstractFileVisitor {
public:
	//prints out text file contents
	virtual void visit_TextFile(TextFile* tf) = 0;
	//prints out image file contents
	virtual void visit_ImageFile(ImageFile* tf) = 0;

};