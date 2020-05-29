#include "tools.h"
#include <catch.hpp>
#include <fstream>

TEST_CASE(
        "Test function size_t countsymbols(): word length counting",
        "File: sizet_countsymbols_test.cpp")
{
    unsigned char string[] = "����� ������ ���";
    size_t length_1 = 0, length_2 = 0, length_3 = 0;

    countsymbols(length_1, string, 0, 16);
    REQUIRE(length_1 == 5);

    countsymbols(length_2, string, 6, 16);
    REQUIRE(length_2 == 6);

    countsymbols(length_3, string, 13, 16);
    REQUIRE(length_3 == 3);
}

TEST_CASE(
        "Test function size_t countsymbols(): word length counting if string "
        "is empty",
        "File: sizet_countsymbols_test.cpp")
{
    unsigned char string[] = "";
    size_t length = 0;

    countsymbols(length, string, 0, 16);

    REQUIRE(length == 0);
}

TEST_CASE(
        "Test function size_t countsymbols(): index permutation",
        "File: sizet_countsymbols_test.cpp")
{
    unsigned char string[] = "����� ����� ����";
    size_t index = 0, length_1 = 0, length_2 = 0, length_3 = 0;

    index = countsymbols(length_1, string, 0, 16);
    REQUIRE(index == 5);

    index = countsymbols(length_2, string, 6, 16);
    REQUIRE(index == 11);

    index = countsymbols(length_3, string, 12, 16);
    REQUIRE(index == 16);
}

TEST_CASE(
        "Test function size_t countsymbols(): the index will not change if the "
        "first character is not a russian letter",
        "File: sizet_countsymbols_test.cpp")
{
    unsigned char string[] = "@����� a������ +������";
    size_t index = 0, length_1 = 0, length_2 = 0, length_3 = 0;

    index = countsymbols(length_1, string, 0, 22);
    REQUIRE(index == 0);

    index = countsymbols(length_2, string, 7, 22);
    REQUIRE(index == 7);

    index = countsymbols(length_3, string, 15, 22);
    REQUIRE(index == 15);
}

TEST_CASE(
        "Test function size_t countsymbols(): the index will change if the "
        "first character is a russian letter",
        "File: sizet_countsymbols_test.cpp")
{
    unsigned char string[] = "�#a������ �*����� �&gfgf";
    size_t index = 0, length_1 = 0, length_2 = 0, length_3 = 0;

    index = countsymbols(length_1, string, 0, 22);
    REQUIRE(index == 1);

    index = countsymbols(length_2, string, 10, 22);
    REQUIRE(index == 11);

    index = countsymbols(length_3, string, 18, 22);
    REQUIRE(index == 19);
}

TEST_CASE(
        "Test function size_t countsymbols(): if string is empty",
        "File: sizet_countsymbols_test.cpp")
{
    unsigned char string[] = "";
    size_t index = 0, length = 0;

    index = countsymbols(length, string, 0, 10);
    REQUIRE(index == 0);
}
