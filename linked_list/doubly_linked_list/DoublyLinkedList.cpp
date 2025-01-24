#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList()
{
    Node *current = head;

    while (current)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
}

void DoublyLinkedList::print_list() const
{
    Node *current = head;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void DoublyLinkedList::insert_at_tail(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    size++;
}

void DoublyLinkedList::insert_at_head(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

bool DoublyLinkedList::insert_at_index(int value, int index)
{
    if (index < 0 || index > size)
    {
        return false;
    }

    if (index == 0)
    {
        insert_at_head(value);
        size++;
        return true;
    }

    if (index == size)
    {
        insert_at_tail(value);
        size++;
        return true;
    }

    Node *current;
    if (index < (size / 2)) // from left side
    {
        current = head;
        int currentIndex = 0;
        while (currentIndex != index)
        {
            current = current->next;
            currentIndex++;
        }
    }
    else
    {
        current = tail;
        int currentIndex = size - 1;
        while (currentIndex != index)
        {
            current = current->prev;
            currentIndex--;
        }
    }

    Node *newNode = new Node(value);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    size++;
    return true;
}