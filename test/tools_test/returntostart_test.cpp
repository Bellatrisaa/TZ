#include "tools.h"
#include <catch.hpp>
#include <fstream>
#include <iostream>

TEST_CASE("Test function returntostart", "File: returntostart_test.cpp")
{
    std::ifstream test_1_txt;
    test_1_txt.open("test/tools_test/test_txt_files/test_1.txt");
    test_1_txt.seekg(5);
    returntostart(test_1_txt);
    REQUIRE(test_1_txt.tellg() == 0);
}
