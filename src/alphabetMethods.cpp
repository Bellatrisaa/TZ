#include "alphabet.h"
#include "singlelist.h"
#include "tools.h"
#include <fstream>
#include <iostream>

alphabet::alphabet(const char* name)
{
    inputtext.open(name);
    buffer = nullptr;
    lengthstrmax = 0;
    ibuff = 0;
    lengthword = 0;
    iwork = 0;
}

alphabet::~alphabet()
{
    delete[] buffer;
}

void alphabet::openisfile()
{
    if (inputtext.is_open()) {
        std::cout << "file is open" << std::endl;
    } else {
        std::cout << "file is not open" << std::endl;
    }
}

void alphabet::printfile()
{
    while (inputtext.get(sym)) {
        std::cout << sym;
    }
}

void alphabet::filetoarray()
{
    countsymbols(inputtext, lengthstrmax);
    buffer = new unsigned char[lengthstrmax];
    while (inputtext.get((char&)sym) and ibuff < lengthstrmax) {
        buffer[ibuff] = sym;
        ibuff++;
    }
    ibuff = 0;
    returntostart(inputtext);
    inputtext.close();
}

unsigned char* alphabet::getptrbuffer()
{
    return buffer;
}

void alphabet::printarray()
{
    if (buffer != nullptr) {
        for (ibuff = 0; ibuff < lengthstrmax; ibuff++) {
            std::cout << buffer[ibuff];
        }
    } else {
        std::cout << "error array is enpty\n";
    }
}

void alphabet::deletepuncmark()
{
    if (buffer != nullptr) {
        for (ibuff = 0; ibuff < lengthstrmax; ibuff++) {
            if (isitletter(buffer[ibuff])) {
                iwork = ibuff;
                ibuff = countsymbols(lengthword, buffer, iwork, lengthstrmax);
                lwords.push(lengthword, buffer, iwork, ibuff);
                lengthword = 0;
            }
        }
    } else {
        std::cout << "massive is empty\n";
    }
}

void alphabet::tolower_()
{
    lwords.tolower_();
}

void alphabet::sort()
{
    lwords.sort_alphabet();
}

void alphabet::show()
{
    lwords.printList();
}

void alphabet::tofile(const char* name)
{
    lwords.listtofile(name);
}
