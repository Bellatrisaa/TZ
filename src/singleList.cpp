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

void list::push(size_t length, unsigned char* array, size_t start, size_t finish)
{
	if (head == NULL)
	{
		head = new Node;
		head->word = new unsigned char[length];
		head->length = length;
		size_t i = 0;
		for (start; start < finish; start++)
		{
			head->word[i] = array[start];
			i++;
		}                                             
		head->next = NULL;                            
		pred = head;                                  
	}                                                 
	else                                              
	{
		Node* ptr = new Node;

		ptr->word = new unsigned char[length];
		ptr->length = length;
		size_t i = 0;
		for (start; start < finish; start++)
		{
			ptr->word[i] = array[start];
			i++;
		}
		pred->next = ptr;
		pred = ptr;
		pred->next = NULL;
	}
}
