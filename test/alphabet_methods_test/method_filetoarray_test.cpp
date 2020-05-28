#include <catch.hpp>
#include "alphabet.h"
#include "string.h"

TEST_CASE("Method filetoarray(): write word from file to array", "File: method_filetoarray_test.cpp")
{
	Alphabet test("test/alphabet_methods_test/test_txt_files/test_1.1.txt");
	test.filetoarray();
	unsigned char *text = test.getPtrBuffer();
	REQUIRE(strcmp((char*)text, "алфавит") == 0);
}
