#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;

CircularDoublyLinkedList::CircularDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    if (!head)
    {
        return;
    }

    tail->next = nullptr;

    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}