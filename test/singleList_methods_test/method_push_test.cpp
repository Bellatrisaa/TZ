#include <catch.hpp>
#include "singleList.h"
#include <fstream>
#include <string.h>
#include <locale.h>

TEST_CASE("Method push: add 1 elemet to list", "File: method_push_test.cpp")
{
	setlocale(LC_ALL, "RUS");
	list test_list;
	unsigned char string[] = "КУава";
	char str[6];
	
	test_list.push(5, string, 0, 5);
	test_list.listtofile("test/singleList_methods_test/test_txt_files/test_1.1.txt");
	
	std::ifstream test_text;
	test_text.open("test/singleList_methods_test/test_txt_files/test_1.1.txt");
	test_text.getline(str, 6);
	
	REQUIRE(strcmp(str, "КУава") == 0);
}

TEST_CASE("Method push: add 10 elements to list", "File: method_push_test.cpp")
{
	setlocale(LC_ALL, "RUS");
	list test_list;
	char str[20];
	int count = 0;
	
	test_list.push(5, (unsigned char*)"Куава", 0, 5);
	test_list.push(7, (unsigned char*)"павпвап", 0, 7);
	test_list.push(12, (unsigned char*)"куцкуцуукцкуц", 0, 12);
	test_list.push(2, (unsigned char*)"см", 0, 2);
	test_list.push(5, (unsigned char*)"Куава", 0, 5);
	test_list.push(5, (unsigned char*)"ууава", 0, 5);
	test_list.push(1, (unsigned char*)"в", 0, 1);
	test_list.push(4, (unsigned char*)"Куав", 0, 4);
	test_list.push(14, (unsigned char*)"Куаваавававаку", 0, 14);
	test_list.push(5, (unsigned char*)"Куава", 0, 5);
	test_list.listtofile("test/singleList_methods_test/test_txt_files/test_1.2.txt");
	
	std::ifstream test_text;
	test_text.open("test/singleList_methods_test/test_txt_files/test_1.2.txt");
	while(test_text.getline(str, 20))
	{
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
	test_list.listtofile("test/singleList_methods_test/test_txt_files/test_1.2.txt");
	
	std::ifstream test_text;
	test_text.open("test/singleList_methods_test/test_txt_files/test_1.3.txt");
	while(test_text.getline((char*)string, 1))
	{
		count++;
	}
	REQUIRE(count == 0);
}
