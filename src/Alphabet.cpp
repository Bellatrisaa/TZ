#include "Alphabet.h"
#include "convert.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>


typedef unsigned char uchar;
typedef unsigned int  uint;


Alphabet::Alphabet(const char* path) : words(nullptr)
{
	std::ifstream fin(path);

	if (fin.is_open()) {
		std::cout << "Copy text from " << path; loadingEmulation();

		std::string str;
		while (std::getline(fin, str)) { 
			std::string cp1251_str = Utf8_to_cp1251(str.c_str());
			buffer.push_back(getClearString(cp1251_str));
		}
		fin.close();
		
		if (buffer.empty()) { 
			std::cout << "Your file is empty, write some text and run again\n"; 
			exit(0); 
		}

		words = new SortedWords;
		setWordsInList();
		words->sort();

		Buffer().swap(buffer);
	} else {
		std::cerr << "File is not found\n";
		exit(1);
	}
}

void Alphabet::show() const
{
	std::cout << "\nAlphabet Words:" << std::endl << std::endl;
	for (const auto& el : *words) {
		std::cout << el << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

std::string Alphabet::getClearString(const std::string &dirtyString) const
{
	std::string clearString;

	std::copy_if(dirtyString.begin(), dirtyString.end(), back_inserter(clearString), 
	[](const  char& ch) -> bool
	{
		return static_cast<uint> (static_cast<uchar> (ch)) == 32 
				|| isalpha(static_cast<uint> (static_cast<uchar> (ch)));
	});

	return clearString;
}

void Alphabet::setWordsInList()
{
	for (const std::string& el : buffer) {
		std::stringstream stream(el);

		std::string temp;
		while (stream >> temp) { 
			words->push_front(stringToLower(temp)); 
		}

		stream.str("");
	}
}

std::string Alphabet::stringToLower(std::string& string) const
{
	std::transform(string.begin(), string.end(), string.begin(), 
	[](const char &sym) -> char 
	{ 
		return tolower(sym);
	});

	return string;
}

void Alphabet::toFile() const
{
	std::ofstream fout("output.txt");

	if (fout.is_open()) {
		for (const auto &el : *words) {
			std::string temp = el + "\n";
			fout << Cp1251_to_utf8(temp.c_str());
		}
		fout.close();

		std::cout << "\nWords written to output.txt\n";

		system("output.txt");
	} else {
		std::cerr << "Output file is not found\n";
	}
}

void Alphabet::loadingEmulation() const
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << '.';

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << '.';

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << '.';

	system("CLS");
}
