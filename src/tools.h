#pragma once

void countsymbols(std::ifstream& file, size_t& len);
void returntostart(std::ifstream& file);
bool IsItLetter(unsigned char& sym);
size_t countsymbols(size_t& len, unsigned char* sym, size_t i, size_t lengthStrMax);
