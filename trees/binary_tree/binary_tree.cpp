#include "binary_tree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() : root(nullptr) {}
BinaryTree::~BinaryTree()
{
}

BinaryTree::Node *BinaryTree::get_root() const
{
    return root;
}

void BinaryTree::inorderTraversal(Node *root) const // left root right
{
    if (!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << endl;
    inorderTraversal(root->right);
}

void BinaryTree::preorderTraversal(Node *root) const // left root right
{
    if (!root)
    {
        return;
    }

    cout << root->data << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void BinaryTree::postorderTraversal(Node *root) const // left root right
{
    if (!root)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << endl;
}

void BinaryTree::insert_root(int value)
{
    if (root)
    {
        throw runtime_error("Root already exists!");
    }

    root = new Node(value);
}

void BinaryTree::insert_left(Node *parent, int value)
{
    if (!parent)
    {
        throw runtime_error("Null parent node!");
    }

    if (parent->left)
    {
        throw runtime_error("Node already exists at this position!");
    }

    parent->left = new Node(value);
}

void BinaryTree::insert_right(Node *parent, int value)
{
    if (!parent)
    {
        throw runtime_error("Null parent node!");
    }

    if (parent->right)
    {
        throw runtime_error("Node already exists at this position!");
    }

    parent->right = new Node(value);
}