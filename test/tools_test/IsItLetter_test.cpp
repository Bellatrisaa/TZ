#include <catch.hpp>
#include "tools.h"

TEST_CASE("Test function IsItLetter() if enter the russian letter", "File: IsItLetter_test.cpp")
{
	unsigned char letter = 'р';
	
	REQUIRE(IsItLetter(letter) == 1);
}

TEST_CASE("Test function IsItLetter() if enter the english letter", "File: IsItLetter_test.cpp")
{
	unsigned char eng_letter = 'a';
	
	REQUIRE(IsItLetter(eng_letter) == 0); 
}

TEST_CASE("Test function IsItLetter() if enter the digit", "File: IsItLetter_test.cpp")
{
	unsigned char digit = '1';
	
	REQUIRE(IsItLetter(digit) == 0);
}

TEST_CASE("Test function IsItLetter() if enter the any special character", "File: IsItLetter_test.cpp")
{
	unsigned char spec_char = '#';
	
	REQUIRE(IsItLetter(spec_char) == 0);
}

SCENARIO("The string includes 5 russian letters")
{
	unsigned char string[] = "пя4  %@U  Dтѓ  !&?  -т";
	int counter = 0;
	
	for(int i = 0; i < 22; i++)
	{
		if(IsItLetter(string[i]))
		{
			counter++;
		}
	}
	
	REQUIRE(counter == 5);
}
