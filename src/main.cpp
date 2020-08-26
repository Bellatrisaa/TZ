#include "Alphabet.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	//if (argc != 2) { std::cerr << "Second argument doesn't exist.\n"; abort(); }

	setlocale(LC_ALL, "RUS");

	Alphabet alph("file.txt");

	alph.show();
	alph.toFile();

	return EXIT_SUCCESS;
}