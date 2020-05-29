#include "singleList.h"
#include <Windows.h>
#include <fstream>
#include <iostream>

struct list::Node {
    unsigned char* word;
    size_t length;
    Node* next;
};

list::list()
{
    head = nullptr;
}

list::~list()
{
    Node* ptr = head;
    while (ptr != nullptr) {
        delete[] ptr->word;
        ptr = ptr->next;
    }
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete[] temp;
    }
}

void list::push(
        size_t length, unsigned char* array, size_t start, size_t finish)
{
    if (head == nullptr) {
        head = new Node;
        head->word = new unsigned char[length];
        head->length = length;
        size_t i = 0;
        for (start = start; start < finish; start++) {
            head->word[i] = array[start];
            i++;
        }
        head->next = nullptr;
        pred = head;
    } else {
        Node* ptr = new Node;

        ptr->word = new unsigned char[length];
        ptr->length = length;
        size_t i = 0;
        for (start = start; start < finish; start++) {
            ptr->word[i] = array[start];
            i++;
        }
        pred->next = ptr;
        pred = ptr;
        pred->next = nullptr;
    }
}

void list::tolower_()
{
    Node* ptr = head;

    while (ptr != nullptr) {
        for (size_t i = 0; i < ptr->length; i++) {
            ptr->word[i] = tolower(ptr->word[i]);
        }
        ptr = ptr->next;
    }
}

void list::sort_alphabet()
{
    Node* new_head = nullptr;

    while (head != nullptr) {
        Node* node = head;
        head = head->next;

        if (new_head == nullptr
            || strcmp((char*)node->word, (char*)new_head->word) < 0) {
            node->next = new_head;
            new_head = node;
        } else {
            Node* current = new_head;
            while (current->next != nullptr
                   && strcmp((char*)node->word, (char*)current->next->word)
                           > 0) {
                current = current->next;
            }

            node->next = current->next;
            current->next = node;
        }
    }
    head = new_head;
}

void list::printList()
{
    Node* ptr = head;
    while (ptr != nullptr) {
        for (size_t i = 0; i < ptr->length; i++) {
            std::cout << ptr->word[i];
        }
        Sleep(1000);
        std::cout << std::endl;
        ptr = ptr->next;
    }
}

void list::listtofile(const char* name)
{
    std::ofstream outputFile;
    outputFile.open(name);
    Node* ptr = head;
    while (ptr != nullptr) {
        for (size_t i = 0; i < ptr->length; i++) {
            outputFile.put(ptr->word[i]);
        }
        outputFile.put('\n');
        ptr = ptr->next;
    }
    outputFile.close();
}
