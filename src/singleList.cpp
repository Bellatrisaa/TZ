#include <iostream>
#include <fstream>
#include <Windows.h>
#include "singleList.h"

struct list::Node
{
	unsigned char* word;
	size_t length;            
	Node* next;
};
