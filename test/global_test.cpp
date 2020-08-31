#include "catch.hpp"
#include "Alphabet.h"
#include <string.h>
#include <fstream>
#include <iostream>

TEST_CASE("[main]", "Main Function")
{
    Alphabet alph("test_input.txt");

    alph.toFile();
   
    bool result = true;
    char ch_1[30], ch_2[30];

    FILE* file_1;
    FILE* file_2;

    file_1 = fopen("test_output.txt", "r");
    file_2 = fopen("output.txt", "r");
        
    while (!feof(file_1) && !feof(file_2)) {
          fgets(ch_1, 30, file_1);
          fgets(ch_2, 30, file_2);
          if (strcmp(ch_1, ch_2) != 0) {
              result = false;
          }
    } 

     fclose(file_1);
     fclose(file_2);
     REQUIRE(result == true);
    }