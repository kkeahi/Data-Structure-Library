#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyLinkedList::print_list() const
{
    Node *current = head;

    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    };
}

int SinglyLinkedList::get_size() const
{
    return size;
}

int SinglyLinkedList::find(int value) const
{
    if (!head)
    {
        return -1;
    }

    Node *current = head;
    int currentIndex = 0;
    while (current)
    {
        if (current->data == value)
        {
            return currentIndex;
        }

        current = current->next;
        currentIndex++;
    }

    return -1;
}

void SinglyLinkedList::insert_at_tail(int value)
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
        tail = newNode;
    }

    size++;
}

void SinglyLinkedList::insert_at_head(int value)
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
        head = newNode;
    }

    size++;
}

bool SinglyLinkedList::insert_at_index(int value, int index)
{
    if (index < 0 || index > size)
    {
        return false;
    }

    if (index == 0)
    {
        insert_at_head(value);
        return true;
    }

    if (index == size)
    {
        insert_at_tail(value);
        return true;
    }

    Node *newNode = new Node(value);
    Node *current = head;
    int currentIndex = 0;

    while (currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    newNode->next = current->next;
    current->next = newNode;

    size++;
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
        tail = nullptr;

        size--;
        return true;
    }

    Node *current = head;
    while (current->next && current->next->next)
    {
        current = current->next;
    }

    tail = current;
    delete tail->next;
    tail->next = nullptr;

    size--;
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

    if (!head)
    {
        tail = nullptr;
    }

    size--;
    return true;
}

bool SinglyLinkedList::delete_at_index(int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }

    if (index == 0)
    {
        return delete_head();
    }

    Node *current = head;
    int currentIndex = 0;

    while (currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    Node *temp = current->next;
    current->next = current->next->next;

    if (!current->next)
    {
        tail = current;
    }

    delete temp;
    size--;
    return true;
}