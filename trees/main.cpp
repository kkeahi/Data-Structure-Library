#include <iostream>
#include "binary_search_tree/binary_search_tree.h"
using namespace std;

int main()
{
    BinarySearchTree t;

    t.insert(10);
    t.insert(4);
    t.insert(6);
    t.insert(2);
    t.insert(7);
    t.insert(8);
    t.insert(5);
    t.insert(12);

    t.postorderTraversal(t.get_root());
}