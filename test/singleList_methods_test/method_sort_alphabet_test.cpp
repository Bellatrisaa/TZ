#include "singleList.h"
#include <catch.hpp>
#include <fstream>
#include <string.h>

TEST_CASE(
        "Method sort_alphabet: sort of two words",
        "File: method_sort_alphabet.cpp")
{
    unsigned char word1[] = "быть";
    unsigned char word2[] = "алфавит";
    list test_list;

    test_list.push(4, word1, 0, 4);
    test_list.push(7, word2, 0, 7);
    test_list.sort_alphabet();
    test_list.listtofile(
            "test/singleList_methods_test/test_txt_files/test_3.1.txt");

    std::ifstream text;
    text.open("test/singleList_methods_test/test_txt_files/test_3.1.txt");
    char sorted_words[2][8];
    size_t i = 0;
    while (text.getline(sorted_words[i], 8)) {
        i++;
    }
    REQUIRE(strcmp(sorted_words[0], sorted_words[1]) < 0);
}
