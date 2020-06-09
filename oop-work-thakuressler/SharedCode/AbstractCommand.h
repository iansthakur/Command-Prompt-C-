#pragma once
#include <string>
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <iostream>


class AbstractCommand {
public:
	//function that runs the command explained in display info
	virtual int execute(std::string) = 0;
	//describes the function purpose and/ or implementation
	virtual void displayInfo() = 0;
};