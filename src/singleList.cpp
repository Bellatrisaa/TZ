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

list::list()
{
	head = NULL;  
}

list::~list()
{
	Node* ptr = head;
	while (ptr != NULL)
	{
		delete[] ptr->word;
		ptr = ptr->next;         
	}
	while (head != NULL)
	{
		Node* temp = head;
		head = head->next;
		delete[] temp;
	}
}
