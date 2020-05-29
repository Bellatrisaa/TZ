#include "singleList.h"
#include <catch.hpp>
#include <cctype>
#include <fstream>
#include <locale.h>
#include <string.h>

TEST_CASE(
        "Method tolower_: translate letter to lower",
        "File: method_tolower_test.cpp")
{
    setlocale(LC_ALL, "RUS");
    unsigned char letter[] = "�";
    list test_list;

    test_list.push(1, letter, 0, 1);
    test_list.tolower_();
    test_list.listtofile(
            "test/singleList_methods_test/test_txt_files/test_2.1.txt");

    char letter_tl;
    std::ifstream text;
    text.open("test/singleList_methods_test/test_txt_files/test_2.1.txt");
    text.get(letter_tl);

    REQUIRE(islower(letter_tl) != 0);
}

TEST_CASE(
        "Method tolower_: translate word to lower",
        "File: method_tolower_test.cpp")
{
    setlocale(LC_ALL, "RUS");
    unsigned char letter[] = "�������";
    list test_list;

    test_list.push(7, letter, 0, 7);
    test_list.tolower_();
    test_list.listtofile(
            "test/singleList_methods_test/test_txt_files/test_2.2.txt");

    char word_tl[8];
    std::ifstream text;
    text.open("test/singleList_methods_test/test_txt_files/test_2.2.txt");
    text.getline(word_tl, 8);

    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (islower(word_tl[i])) {
            count++;
        }
    }

    REQUIRE(count == 7);
}
