#include <iostream>
#include "singly_linked_list/SinglyLinkedList.h"
using namespace std;

int main()
{
    SinglyLinkedList list;
    list.insert_at_tail(10);
    list.insert_at_tail(20);
    list.insert_at_head(5);
    list.insert_at_index(7, 1);
    list.print_list();

    cout << endl;

    list.delete_at_index(2);
    list.print_list();

    return 0;
}

// cd l*
// g++ -o main main.cpp singly_linked_list/SinglyLinkedList.cpp
// ./main