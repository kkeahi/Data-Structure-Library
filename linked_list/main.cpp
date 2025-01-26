#include <iostream>
#include "singly_linked_list/SinglyLinkedList.h"
#include "doubly_linked_list/DoublyLinkedList.h"
#include "circular_linked_list/CircularLinkedList.h"
using namespace std;

int main()
{
    CircularLinkedList list;

    list.insert_at_head(10);
    list.insert_at_head(20);
    list.insert_at_head(30);

    list.delete_head();
    list.delete_head();
    list.delete_head();

    list.print_list();

    return 0;
}