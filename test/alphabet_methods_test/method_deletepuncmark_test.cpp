#include "alphabet.h"
#include "string.h"
#include <catch.hpp>
#include <fstream>

TEST_CASE(
        "Method deletepuncmark: delete all puncmarks in string",
        "File: method_deletepuncmark_test.cpp")
{
    alphabet test("test/alphabet_methods_test/test_txt_files/test_2.1.txt");
    test.filetoarray();
    test.deletepuncmark();
    test.tofile("test/alphabet_methods_test/test_txt_files/test_2.2.txt");

    std::ifstream text;
    text.open("test/alphabet_methods_test/test_txt_files/test_2.2.txt");
    char word[8];
    text.getline(word, 8);

    REQUIRE(strcmp(word, "алфавит") == 0);
    text.close();
}

TEST_CASE(
        "Method deletepuncmark: delete all special chars in string",
        "File: method_deletepuncmark_test.cpp")
{
    alphabet test("test/alphabet_methods_test/test_txt_files/test_2.3.txt");
    test.filetoarray();
    test.deletepuncmark();
    test.tofile("test/alphabet_methods_test/test_txt_files/test_2.4.txt");

    std::ifstream text;
    text.open("test/alphabet_methods_test/test_txt_files/test_2.4.txt");
    char word[8];
    text.getline(word, 8);

    REQUIRE(strcmp(word, "алфавит") == 0);
    text.close();
}

TEST_CASE(
        "Method deletepuncmark: delete all digits in string",
        "File: method_deletepuncmark_test.cpp")
{
    alphabet test("test/alphabet_methods_test/test_txt_files/test_2.5.txt");
    test.filetoarray();
    test.deletepuncmark();
    test.tofile("test/alphabet_methods_test/test_txt_files/test_2.6.txt");

    std::ifstream text;
    text.open("test/alphabet_methods_test/test_txt_files/test_2.6.txt");
    char word[8];
    text.getline(word, 8);

    REQUIRE(strcmp(word, "алфавит") == 0);
    text.close();
}

TEST_CASE(
        "Method deletepuncmark: delete all english letters in string",
        "File: method_deletepuncmark_test.cpp")
{
    alphabet test("test/alphabet_methods_test/test_txt_files/test_2.7.txt");
    test.filetoarray();
    test.deletepuncmark();
    test.tofile("test/alphabet_methods_test/test_txt_files/test_2.8.txt");

    std::ifstream text;
    text.open("test/alphabet_methods_test/test_txt_files/test_2.8.txt");
    char word[8];
    text.getline(word, 8);

    REQUIRE(strcmp(word, "алфавит") == 0);
    text.close();
}
