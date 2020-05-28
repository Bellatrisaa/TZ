#include "alphabet.h"
#include "singleList.h"
#include "tools.h"
#include <iostream>
#include <fstream>

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

unsigned char* Alphabet::getPtrBuffer()
{
	return buffer;
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

void Alphabet::deletepuncmark()
{
	if (buffer != NULL)
	{
		for (iBuff = 0; iBuff < lengthStrMax; iBuff++)
		{
			if (IsItLetter(buffer[iBuff]))
			{
				iWork = iBuff;
				iBuff = countsymbols(lengthWord, buffer, iWork, lengthStrMax);
				lwords.push(lengthWord, buffer, iWork, iBuff);
				lengthWord = 0;
			}
		}
	}
	else
	{
		std::cout << "Massive is empty\n";
	}
}

void Alphabet::tolower_()
{
lwords.tolower_();
}

void Alphabet::sort()
{
lwords.sort_alphabet();
}

void Alphabet::show()
{
lwords.printList();
}

void Alphabet::tofile()
{
lwords.listtofile("output.txt");
}
