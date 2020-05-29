#include "tools.h"
#include <catch.hpp>

TEST_CASE(
        "Test function IsItLetter() if enter the russian letter",
        "File: IsItLetter_test.cpp")
{
    unsigned char letter = '�';

    REQUIRE(isitletter(letter) == 1);
}

TEST_CASE(
        "Test function IsItLetter() if enter the english letter",
        "File: IsItLetter_test.cpp")
{
    unsigned char eng_letter = 'a';

    REQUIRE(isitletter(eng_letter) == 0);
}

TEST_CASE(
        "Test function IsItLetter() if enter the digit",
        "File: IsItLetter_test.cpp")
{
    unsigned char digit = '1';

    REQUIRE(isitletter(digit) == 0);
}

TEST_CASE(
        "Test function IsItLetter() if enter the any special character",
        "File: IsItLetter_test.cpp")
{
    unsigned char spec_char = '#';

    REQUIRE(isitletter(spec_char) == 0);
}

SCENARIO("The string includes 5 russian letters")
{
    unsigned char string[] = "?�4  %@U  D��  !&�  -�";
    int counter = 0;

    for (int i = 0; i < 22; i++) {
        if (isitletter(string[i])) {
            counter++;
        }
    }

    REQUIRE(counter == 5);
}
