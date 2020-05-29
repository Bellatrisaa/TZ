#pragma once
#include "singleList.h"
#include <fstream>

class alphabet {
    std::ifstream inputtext;
    std::ofstream outputtext;
    unsigned char* buffer;
    char sym;
    size_t lengthstrmax, ibuff, iwork, lengthword;
    list lwords;

public:
    alphabet(const char* name);
    ~alphabet();

    void openisfile();
    void printfile();
    void filetoarray();
    unsigned char* getptrbuffer();
    void printarray();
    void deletepuncmark();
    void tolower_();
    void sort();
    void show();
    void tofile(const char* name);
};
