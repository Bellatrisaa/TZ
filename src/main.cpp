#include "alphabet.h"
#include <locale.h>

int main(int argv, char** argc)
{
    setlocale(LC_ALL, "RUS");
    Alphabet text("input.txt");
    text.openisfile();
    text.filetoarray();
    text.deletepuncmark();
    text.tolower_();
    text.sort();
    text.show();
    text.tofile();
    return 0;
}
