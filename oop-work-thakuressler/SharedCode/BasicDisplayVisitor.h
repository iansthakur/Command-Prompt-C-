#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"


class BasicDisplayVisitor : public AbstractFileVisitor{
public: 
	//see AbstractFileVisitor header file for function descriptions
	void visit_TextFile(TextFile* tf);
	void visit_ImageFile(ImageFile* tf);
};