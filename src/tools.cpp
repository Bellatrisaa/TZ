#include <fstream>
#include <ostream>
#include "tools.h"


void countsymbols(std::ifstream& file, size_t& len)
{
	char ch;
	while (file.get(ch))
	{                                                      
		len++;
	}
}
