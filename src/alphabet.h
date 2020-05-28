#pragma once
#include <fstream>
#include "singleList.h"

class Alphabet
{
	std::ifstream inputText;
	std::ofstream outputText;
	unsigned char *buffer;
	char sym;
	size_t lengthStrMax, iBuff, iWork, lengthWord;
	list lwords;
public:
	Alphabet(const char* name);
	~Alphabet();
	
	void openisfile();
	void printfile();
	void filetoarray();
	unsigned char *getPtrBuffer();
	void printarray();
	void deletepuncmark();
	void tolower_();
	void sort();
	void show();
	void tofile(const char *name);
};
