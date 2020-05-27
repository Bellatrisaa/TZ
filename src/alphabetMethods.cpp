#include "alphabet.h"

Alphabet::Alphabet(const char *name)
{
	inputText.open(name);
	buffer = NULL;
	lengthStrMax = 0;
	iBuff = 0;                       
	lengthWord = 0;
	iWork = 0;
}

Alphabet::~Alphabet()
{
	delete[] buffer;                
}

void Alphabet::openisfile()
{
	if (inputText.is_open())
	{
		std::cout << "FILE IS OPEN" << std::endl;
	}
	else
	{
		std::cout << "FILE IS NOT OPEN" << std::endl;
	}
}

void Alphabet::printfile()
{
	while (inputText.get(sym))
	{
		std::cout << sym;
	}
}

void Alphabet::filetoarray()
{
	countsymbols(inputText, lengthStrMax);
	buffer = new unsigned char[lengthStrMax];
	while (inputText.get((char&)sym) and iBuff < lengthStrMax)
	{
		buffer[iBuff] = sym;
		iBuff++;
	}
	iBuff = 0;
	returntostart(inputText);
	inputText.close();
}

void Alphabet::printarray()
{
	if (buffer != NULL)
	{
		for (iBuff = 0; iBuff < lengthStrMax; iBuff++)
		{
			std::cout << buffer[iBuff];
		}
	}
	else
	{
		std::cout << "ERROR ARRAY IS ENPTY\n";
	}
}
