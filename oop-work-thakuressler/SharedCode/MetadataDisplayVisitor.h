#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	//see AbstractFileVisitor header file for info on functions
	void visit_TextFile(TextFile* tf);
	void visit_ImageFile(ImageFile* tf);
};