#include "catch.hpp"
#include <iostream>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned int uint;

std::string getClearString(const std::string& dirtyString)
{
    std::string clearString;

    std::copy_if(
            dirtyString.begin(),
            dirtyString.end(),
            back_inserter(clearString),
            [](const char& ch) -> bool {
                return static_cast<uint>(static_cast<uchar>(ch)) == 32
                        || isalpha(static_cast<uint>(static_cast<uchar>(ch)));
            });

    return clearString;
}

std::string stringToLower(std::string& string)
{
    std::transform(
            string.begin(),
            string.end(),
            string.begin(),
            [](const char& sym) -> char { return tolower(sym); });

    return string;
}

TEST_CASE("[getClearString]", "Function to filter text")
{
    std::string str1 = getClearString("course project");
    std::string str2 = getClearString("!!Alphabet...12");
    std::string str3 = getClearString("=+::8.9,@@%#66");
    std::string str4 = getClearString("");

    REQUIRE(strcmp(str1.c_str(), "course project") == 0);
    REQUIRE(strcmp(str2.c_str(), "Alphabet") == 0);
    REQUIRE(strcmp(str3.c_str(), "") == 0);
    REQUIRE(strcmp(str4.c_str(), "") == 0);
}

TEST_CASE("[stringToLower]", "Function to convert characters to lowercase")
{
    std::string temp("course project");
    std::string str1 = stringToLower(temp);
    temp = "Course Project";
    std::string str2 = stringToLower(temp);
    temp = "AlPhAbEt";
    std::string str3 = stringToLower(temp);
    temp = "ALPHABET";
    std::string str4 = stringToLower(temp);

    REQUIRE(strcmp(str1.c_str(), "course project") == 0);
    REQUIRE(strcmp(str2.c_str(), "course project") == 0);
    REQUIRE(strcmp(str3.c_str(), "alphabet") == 0);
    REQUIRE(strcmp(str4.c_str(), "alphabet") == 0);
}
