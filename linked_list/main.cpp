#include <iostream>
#include "singly_linked_list/SinglyLinkedList.h"
#include "doubly_linked_list/DoublyLinkedList.h"
#include "circular_linked_list/CircularLinkedList.h"
#include "circular_doubly_linked_list/CircularDoublyLinkedList.h"
using namespace std;

int main()
{
    CircularDoublyLinkedList list;

    list.insert_at_head(10);
    list.insert_at_tail(20);
    list.insert_at_tail(30);
    list.insert_at_tail(40);

    list.print_list();

    return 0;
}