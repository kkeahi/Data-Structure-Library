#include <iostream>
#include "BinarySearchTree.h"
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
    t.remove(12);
    cout << endl << t.height() << endl << t.depth(t.get_root());
    cout << endl << t.findMax() << endl << t.findMax();

    t.postorderTraversal(t.get_root());
}