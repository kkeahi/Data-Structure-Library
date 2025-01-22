#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList()
{
    Node *current = head;

    while (current)
    {
        Node *nextNode = (*current).next;
        delete current;
        current = nextNode;
    }
}

void SinglyLinkedList::print_list()
{
    Node *current = head;

    while (current)
    {
        cout << (*current).data << endl;
        current = (*current).next;
    };
}

void SinglyLinkedList::insert_at_tail(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void SinglyLinkedList::insert_at_head(int value)
{
    Node *newNode = new Node(value);

    (*newNode).next = head;
    head = newNode;
}

bool SinglyLinkedList::insert_at_index(int value, int index)
{
    if (index < 0)
    {
        return false;
    }

    if (index == 0)
    {
        insert_at_head(value);
        return true;
    }

    Node *newNode = new Node(value);

    Node *current = head;
    int currentIndex = 0;

    while (current && currentIndex < index - 1)
    {
        current = (*current).next;
        currentIndex++;
    }

    if (!current)
    {
        delete newNode;
        return false;
    }

    (*newNode).next = (*current).next;
    (*current).next = newNode;

    return true;
}

bool SinglyLinkedList::delete_tail()
{
    if (!head)
    {
        return false;
    }

    if (!head->next)
    {
        delete head;
        head = nullptr;

        return true;
    }

    Node *current = head;
    while (current->next && current->next->next)
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;

    return true;
}

bool SinglyLinkedList::delete_head()
{
    if (!head)
    {
        return false;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    return true;
}

bool SinglyLinkedList::delete_at_index(int index)
{
    if (index < 0)
    {
        return false;
    }

    if (index == 0)
    {
        return delete_head();
    }

    Node *current = head;
    int currentIndex = 0;

    while (current && currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    if (!current || !current->next)
    {
        return false;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;

    return true;
}