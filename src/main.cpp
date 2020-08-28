#include "Alphabet.h"
#include <cstdlib>
#include <iostream>


int main(int argc, char **argv)
{
	if (argc != 2) { 
		std::cerr << "Missed second argument\n"; 
		abort(); 
	}

	setlocale(LC_ALL, "RUS");

	Alphabet alph(argv[1]);

	alph.show();
	alph.toFile();

	return EXIT_SUCCESS;
}
