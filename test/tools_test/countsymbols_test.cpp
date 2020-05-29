#include "tools.h"
#include <catch.hpp>
#include <fstream>

TEST_CASE("Character count test", "File: countsymbols_test.cpp")
{
    std::ifstream test_2_1_txt;
    test_2_1_txt.open("test/tools_test/test_txt_files/test_2.1.txt");
    size_t length = 0;
    countsymbols(test_2_1_txt, length);
    REQUIRE(length == 241);
    test_2_1_txt.close();
}

TEST_CASE(
        "Character count test (txt file is empty)",
        "File: countsymbols_test.cpp")
{
    std::ifstream test_2_2_txt;
    test_2_2_txt.open("test/tools_test/test_txt_files/test_2.2.txt");
    size_t length = 0;
    countsymbols(test_2_2_txt, length);
    REQUIRE(length == 0);
    test_2_2_txt.close();
}
