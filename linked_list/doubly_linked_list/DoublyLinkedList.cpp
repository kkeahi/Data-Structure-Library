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

int DoublyLinkedList::get_size() const
{
    return size;
}

int DoublyLinkedList::find(int value) const
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

bool DoublyLinkedList::delete_tail()
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

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;

    size--;
    return true;
}

bool DoublyLinkedList::delete_head()
{
    if (!head)
    {
        return false;
    }

    Node *temp = head;
    head = head->next;

    if (head)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }

    delete temp;

    size--;
    return true;
}

bool DoublyLinkedList::delete_at_index(int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }

    if (index == 0)
    {
        return delete_head();
    }

    if (index == size - 1)
    {
        return delete_tail();
    }

    Node *current;
    int currentIndex;

    if (index < (size / 2))
    {
        current = head;
        currentIndex = 0;

        while (currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }
    }
    else
    {
        current = tail;
        currentIndex = size - 1;

        while (currentIndex > index)
        {
            current = current->prev;
            currentIndex--;
        }
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;

    size--;
    return true;
}