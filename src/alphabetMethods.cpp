
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


