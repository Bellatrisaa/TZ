#pragma once
#include <cstddef> 
class list {
    struct Node;

public:
    list();
    ~list();

    void push(size_t length, unsigned char* array, size_t start, size_t finish);
    void tolower_();
    void sort_alphabet();
    void printList();
    void listtofile(const char* name);

private:
    Node* pred;
    Node* head;
};
