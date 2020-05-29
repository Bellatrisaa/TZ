#include "alphabet.h"
#include <locale.h>

int main(int argv, char** argc)
{
    setlocale(LC_ALL, "RUS");
    alphabet text("input.txt");
    text.openisfile();
    text.filetoarray();
    text.deletepuncmark();
    text.tolower_();
    text.sort();
    text.show();
    text.tofile("output.txt");
    return 0;
}
