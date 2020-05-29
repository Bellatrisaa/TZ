#include "singleList.h"
#include <catch.hpp>
#include <fstream>
#include <locale.h>
#include <string.h>

TEST_CASE("Method push: add 1 elemet to list", "File: method_push_test.cpp")
{
    setlocale(LC_ALL, "RUS");
    list test_list;
    unsigned char string[] = "алфавит";
    char str[6];

    test_list.push(7, string, 0, 7);
    test_list.listtofile(
            "test/singleList_methods_test/test_txt_files/test_1.1.txt");

    std::ifstream test_text;
    test_text.open("test/singleList_methods_test/test_txt_files/test_1.1.txt");
    test_text.getline(str, 8);

    REQUIRE(strcmp(str, "алфавит") == 0);
}

TEST_CASE("Method push: add 10 elements to list", "File: method_push_test.cpp")
{
    setlocale(LC_ALL, "RUS");
    list test_list;
    char str[20];
    int count = 0;

    test_list.push(5, (unsigned char*)"павпп", 0, 5);
    test_list.push(7, (unsigned char*)"амвпыва", 0, 7);
    test_list.push(12, (unsigned char*)"ваыаываапцув", 0, 12);
    test_list.push(2, (unsigned char*)"ав", 0, 2);
    test_list.push(5, (unsigned char*)"папап", 0, 5);
    test_list.push(5, (unsigned char*)"апвпв", 0, 5);
    test_list.push(1, (unsigned char*)"в", 0, 1);
    test_list.push(4, (unsigned char*)"авав", 0, 4);
    test_list.push(14, (unsigned char*)"ававыаыаыаывауы", 0, 14);
    test_list.push(5, (unsigned char*)"ававв", 0, 5);
    test_list.listtofile(
            "test/singleList_methods_test/test_txt_files/test_1.2.txt");

    std::ifstream test_text;
    test_text.open("test/singleList_methods_test/test_txt_files/test_1.2.txt");
    while (test_text.getline(str, 20)) {
        count++;
    }

    REQUIRE(count == 10);
}

TEST_CASE("Method push: if string is empty", "File: method_push_test.cpp")
{
    setlocale(LC_ALL, "RUS");
    list test_list;
    int count = 0;
    unsigned char string[] = "";

    test_list.push(0, string, 0, 0);
    test_list.listtofile(
            "test/singleList_methods_test/test_txt_files/test_1.2.txt");

    std::ifstream test_text;
    test_text.open("test/singleList_methods_test/test_txt_files/test_1.3.txt");
    while (test_text.getline((char*)string, 1)) {
        count++;
    }
    REQUIRE(count == 0);
}
