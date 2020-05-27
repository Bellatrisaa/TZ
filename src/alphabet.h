#pragma once
#include <fstream>

class Alphabet
{
	std::ifstream inputText;
	std::ofstream outputText;
	unsigned char *buffer;
	char sym;
	size_t lengthStrMax, iBuff, iWork, lengthWord;
public:
	Alphabet(const char* name);
	~Alphabet();
	
	void openisfile();
	void printfile();
}
