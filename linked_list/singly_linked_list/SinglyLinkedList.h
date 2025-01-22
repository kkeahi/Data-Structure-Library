#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insert_at_tail(int value);
    void insert_at_head(int value);
    bool insert_at_index(int value, int index);

    bool delete_tail();
    bool delete_head();
    bool delete_at_index(int index);

    void print_list();
};

#endif