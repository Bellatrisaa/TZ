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
