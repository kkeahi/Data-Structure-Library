#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr), size(0) {}

CircularLinkedList::~CircularLinkedList()
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

void CircularLinkedList::print_list() const
{
    if (!head)
    {
        return;
    }

    Node *current = head;

    do
    {
        cout << current->data << endl;
        current = current->next;
    } while (current != head);
}

int CircularLinkedList::get_size() const
{
    return size;
}

int CircularLinkedList::find(int value) const
{
    if (!head)
    {
        return -1;
    }

    if (tail->data == value)
    {
        return (size - 1);
    }

    Node *current = head;
    int currentIndex = 0;

    do
    {
        if (current->data == value)
        {
            return currentIndex;
        }

        current = current->next;
        currentIndex++;
    } while (current != head);

    return -1;
}

void CircularLinkedList::insert_at_tail(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    size++;
}

void CircularLinkedList::insert_at_head(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    size++;
}

bool CircularLinkedList::insert_at_index(int value, int index)
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

bool CircularLinkedList::delete_tail()
{
    if (!head)
    {
        return false;
    }

    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;

        size--;
        return true;
    }

    Node *current = head;
    while (current->next != tail)
    {
        current = current->next;
    }

    Node *temp = tail;
    tail = current;
    tail->next = head;
    delete temp;

    size--;
    return true;
}

bool CircularLinkedList::delete_head()
{
    if (!head)
    {
        return false;
    }

    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;

        size--;
        return true;
    }

    Node *temp = head;
    head = head->next;
    tail->next = head;
    delete temp;

    size--;
    return true;
}

bool CircularLinkedList::delete_at_index(int index)
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

    Node *current = head;
    int currentIndex = 0;

    while (currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;

    size--;
    return true;
}