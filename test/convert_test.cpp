#include "catch.hpp"
#include "convert.h"
#include <string>
#include <iostream>

typedef unsigned char uchar;
typedef unsigned int uint;

TEST_CASE("Convertation from utf-8 to cp1251", "File convert_test.cpp")
{
	const char *someStr = "строка";
	const std::string ansiString = Utf8_to_cp1251(someStr);
	const std::string utf8String = "строка";
	
	bool isAnsi = (utf8String.length() / ansiString.length() == 2); 

	uchar ansiChar = static_cast<uchar> (ansiString[0]);
	
	REQUIRE(isAnsi == true);
	REQUIRE(static_cast<uint> (ansiChar) == 241);
}

TEST_CASE("Convertation from cp1251 to utf-8", "File convert_test.cpp")
{
	const char *someStr = "строка";
	const std::string ansiString = Utf8_to_cp1251(someStr);
	const std::string utf8String = Cp1251_to_utf8(ansiString.c_str());
	
	bool isUtf8 = (utf8String.length() / ansiString.length() == 2); 

	uchar utf8Char = static_cast<uchar> (utf8String[0]);
	
	REQUIRE(isUtf8 == true);
	REQUIRE(static_cast<uint> (utf8Char) == 209);
}





