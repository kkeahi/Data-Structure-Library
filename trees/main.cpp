#include <iostream>
#include "binary_tree/binary_tree.h"
using namespace std;

int main()
{
    BinaryTree t;

    t.insert_root(2);
    BinaryTree::Node *root = t.get_root();
    t.insert_left(root, 1);
    t.insert_right(root, 3);
    t.insert_left(root->right, 10);

    t.inorderTraversal(root);
    cout << endl;
    t.preorderTraversal(root);
    cout << endl;
    t.postorderTraversal(root);
}