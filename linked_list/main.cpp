#include <iostream>
#include "singly_linked_list/SinglyLinkedList.h"
#include "doubly_linked_list/DoublyLinkedList.h"
using namespace std;

int main()
{
    DoublyLinkedList list;
    list.insert_at_tail(0);
    list.insert_at_tail(1);
    list.insert_at_tail(2);
    list.insert_at_tail(3);
    list.insert_at_tail(4);
    list.insert_at_tail(5);

    list.insert_at_tail(7);
    list.insert_at_index(6, 6);
    list.print_list();

    return 0;
}

// cd l*
// g++ -o main main.cpp singly_linked_list/SinglyLinkedList.cpp
// ./main