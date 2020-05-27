#include <fstream>
#include <ostream>
#include "tools.h"

void returntostart(std::ifstream& file)
{
	file.clear();                                        
	file.seekg(0);
}

void countsymbols(std::ifstream& file, size_t& len)
{
	char ch;
	while (file.get(ch))
	{                                                      
		len++;
	}
	returntostart(file);
}

bool IsItLetter(unsigned char& sym)
{
	return ((192 <= (int)sym and (int)sym <= 255) or ((int)sym == 184) or ((int)sym == 168));
}

size_t countsymbols(size_t& len, unsigned char* sym, size_t i, size_t lengthStrMax)
{
	while (IsItLetter(sym[i]) and i < lengthStrMax)
	{
		len++;
		i++;                                                             
	}
	return i;
}
