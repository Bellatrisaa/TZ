#include "alphabet.h"
#include <locale.h>
#include <string>
#include <iostream>
using namespace std;  

int main(int argv, char** argc)
{
    setlocale(LC_ALL, "RUS");
    string sf; 
	printf("\n      ¬ведите название txt файла с исходными данными: ");  	
	getline(cin,sf);
	sf=sf+".txt";
    alphabet text(sf.c_str());
    text.openisfile();
    text.filetoarray();
    text.deletepuncmark();
    text.tolower_();
    text.sort();
    text.show();
    text.tofile("output.txt");
    system("pause");
    return 0;
}
